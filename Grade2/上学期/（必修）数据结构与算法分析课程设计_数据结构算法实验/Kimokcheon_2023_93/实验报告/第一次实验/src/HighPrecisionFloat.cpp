#include "HighPrecisionFloat.h"

std::stringstream HighPrecisionFloat::ss;



HighPrecisionFloat::HighPrecisionFloat() {
    num = "0";
    sign = 1;
    dotPos = 0;
}

HighPrecisionFloat::HighPrecisionFloat(std::string s) {
    if (s[0] == '-') {
        sign = -1;
        s = s.substr(1);
    } else {
        sign = 1;
    }
    size_t dot = s.find('.');
    if (dot != std::string::npos) {
        dotPos = s.size() - dot - 1;
        s.erase(dot, 1);
    } else {
        dotPos = 0;
    }
    num = s;
    removeLeadingZeros();
}

HighPrecisionFloat::HighPrecisionFloat(long double val) {
    ss.clear();
    ss << std::fixed << std::setprecision(MAX_PRECISION) << val << std::endl;
    std::string s;
    ss >> s;
    if (s[0] == '-') {
        sign = -1;
        s = s.substr(1);
    } else {
        sign = 1;
    }
    size_t dot = s.find('.');
    if (dot != std::string::npos) {
        dotPos = s.size() - dot - 1;
        s.erase(dot, 1);
    } else {
        dotPos = 0;
    }
    num = s;
    removeLeadingZeros();
}

HighPrecisionFloat::HighPrecisionFloat(const HighPrecisionFloat &other) {
    if (this != &other) {
        sign = other.sign;
        num = other.num;
        dotPos = other.dotPos;
    }
}

HighPrecisionFloat::HighPrecisionFloat(HighPrecisionFloat &&other) noexcept {
    if (this != &other) {
        std::swap(sign, other.sign);
        swap(num, other.num);
        std::swap(dotPos, other.dotPos);
    }
}

HighPrecisionFloat &HighPrecisionFloat::operator=(const HighPrecisionFloat &other) {
    if (this != &other) {
        sign = other.sign;
        num = other.num;
        dotPos = other.dotPos;
    }
    return *this;
}

HighPrecisionFloat &HighPrecisionFloat::operator=(HighPrecisionFloat &&other) noexcept {
    if (this != &other) {
        std::swap(sign, other.sign);
        swap(num, other.num);
        std::swap(dotPos, other.dotPos);
    }
    return *this;
}

HighPrecisionFloat &HighPrecisionFloat::operator=(long double val) {
    HighPrecisionFloat tmp(val);
    std::swap(sign, tmp.sign);
    swap(num, tmp.num);
    std::swap(dotPos, tmp.dotPos);
    return *this;
}

void HighPrecisionFloat::removeLeadingZeros() {
    while (num.size() > 1 && num[0] == '0') {
        num.erase(0, 1);
    }
    while (num.size() > 1 && num[num.size() - 1] == '0' && dotPos > 0) {
        num.erase(num.size() - 1, 1);
        dotPos--;
    }
    if (num == "0") {
        sign = 1;
        dotPos = 0;
    }
}

HighPrecisionFloat operator+(const HighPrecisionFloat &a, const HighPrecisionFloat &b) {
    if (a.sign == b.sign) {
        HighPrecisionFloat res;
        res.dotPos = std::max(a.dotPos, b.dotPos);
        int maxIntPartLen = std::max(a.num.size() - a.dotPos, b.num.size() - b.dotPos);
        res.num.resize(res.dotPos + maxIntPartLen + 1, '0');
        int carry = 0;
        int bias_a = a.num.size() - a.dotPos - maxIntPartLen, bias_b = b.num.size() - b.dotPos - maxIntPartLen;
        for (int i = res.num.size() - 1; i >= 0; --i) {
            int ai = (i + bias_a - 1 >= 0 && i + bias_a - 1 < a.num.size()) ? (a.num[i + bias_a - 1] - '0') : 0;
            int bi = (i + bias_b - 1 >= 0 && i + bias_b - 1 < b.num.size()) ? (b.num[i + bias_b - 1] - '0') : 0;
            int ri = ai + bi + carry;
            if (ri >= 10) {
                carry = 1;
                ri -= 10;
            } else {
                carry = 0;
            }
            res.num[i] = ri + '0';
        }
        res.sign = a.sign;
        res.removeLeadingZeros();
        return res;
    } else {
        return a - (-b);
    }
}

HighPrecisionFloat operator-(const HighPrecisionFloat &a, const HighPrecisionFloat &b) {
    if (a.sign == b.sign) {
        if (a.sign == -1) {
            return (-b) - (-a);
        }
        if (a < b) {
            return -(b - a);
        }
        HighPrecisionFloat res;
        res.dotPos = std::max(a.dotPos, b.dotPos);
        int maxIntPartLen = std::max(a.num.size() - a.dotPos, b.num.size() - b.dotPos);
        res.num.resize(res.dotPos + maxIntPartLen, '0');
        int borrow = 0;
        int bias_a = a.num.size() - a.dotPos - maxIntPartLen, bias_b = b.num.size() - b.dotPos - maxIntPartLen;
        for (int i = res.num.size() - 1; i >= 0; --i) {
            int ai = (i + bias_a >= 0 && i + bias_a < a.num.size()) ? (a.num[i + bias_a] - '0') : 0;
            int bi = (i + bias_b >= 0 && i + bias_b < b.num.size()) ? (b.num[i + bias_b] - '0') : 0;
            int ri = ai - bi - borrow;
            if (ri < 0) {
                ri += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            res.num[i] = ri + '0';
        }
        if (borrow == 1) {
            res.sign = -1;
            res.num[0] = 10 - (res.num[0] - '0') + '0';
        }
        res.removeLeadingZeros();
        return res;
    } else {
        return a + (-b);
    }
}

HighPrecisionFloat operator*(const HighPrecisionFloat &a, const HighPrecisionFloat &b) {
    if (a == HighPrecisionFloat("0") || b == HighPrecisionFloat("0")) {
        return {0};
    }
    HighPrecisionFloat res;
    res.dotPos = a.dotPos + b.dotPos;
    res.num.resize(a.num.size() + b.num.size(), '0');
    for (int i = a.num.size() - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = b.num.size() - 1; j >= 0; j--) {
            int ai = a.num[i] - '0';
            int bi = b.num[j] - '0';
            int ri = ai * bi + carry + (res.num[i + j + 1] - '0');
            carry = ri / 10;
            ri %= 10;
            res.num[i + j + 1] = ri + '0';
        }
        res.num[i] += carry;
    }
    res.sign = a.sign * b.sign;
    res.removeLeadingZeros();
    return res;
}

bool operator<(const HighPrecisionFloat &a, const HighPrecisionFloat &b) {
    if (a.sign != b.sign) {
        return a.sign < b.sign;
    }
    if (a.num.size() - a.dotPos != b.num.size() - b.dotPos) {
        return a.num.size() - a.dotPos < b.num.size() - b.dotPos;
    }
    for (int i = 0; i < std::min(a.num.size(), b.num.size()); i++) {
        if (a.num[i] != b.num[i]) {
            return a.num[i] < b.num[i];
        }
    }
    return a.num.size() < b.num.size();
}

bool operator>(const HighPrecisionFloat &a, const HighPrecisionFloat &b) {
    return b < a;
}

bool operator==(const HighPrecisionFloat &a, const HighPrecisionFloat &b) {
    return a.sign == b.sign && a.dotPos == b.dotPos && a.num == b.num;
}

HighPrecisionFloat operator-(const HighPrecisionFloat &a) {
    HighPrecisionFloat res = a;
    res.sign *= -1;
    return res;
}

std::ostream &operator<<(std::ostream &os, const HighPrecisionFloat &a) {
    if (a.sign == -1) {
        os << "-";
    }
    if (a.num.empty()) {
        os << "0";
        return os;
    }
    if (a.num.size() == a.dotPos) {
        os << "0";
    }
    for (int i = 0; i < a.num.size(); i++) {
        if (a.num.size() - i == a.dotPos) {
            os << ".";
        }
        os << a.num[i];
    }
    return os;
}

HighPrecisionFloat::operator long double() const {
    ss.clear();
    ss << *this;
    long double ret;
    ss >> ret;
    return ret;
}