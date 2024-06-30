#ifndef HIGHPRECISIONFLOAT_H
#define HIGHPRECISIONFLOAT_H

#include <string>
#include <iostream>
#include <iomanip>


class HighPrecisionFloat {
    static const int MAX_PRECISION = 10;
private:
    std::string num;
    int sign; // 非负数为1，负数为-1
    int dotPos; // 小数点位置，小数部分长度
    static std::stringstream ss;
public:
    HighPrecisionFloat();

    explicit HighPrecisionFloat(std::string);

    HighPrecisionFloat(long double);

    HighPrecisionFloat(const HighPrecisionFloat &);

    HighPrecisionFloat(HighPrecisionFloat &&) noexcept;

    HighPrecisionFloat &operator=(const HighPrecisionFloat &);

    HighPrecisionFloat &operator=(HighPrecisionFloat &&) noexcept;

    HighPrecisionFloat &operator=(long double);

    void removeLeadingZeros();

    friend HighPrecisionFloat operator+(const HighPrecisionFloat &, const HighPrecisionFloat &);

    friend HighPrecisionFloat operator-(const HighPrecisionFloat &, const HighPrecisionFloat &);

    friend HighPrecisionFloat operator*(const HighPrecisionFloat &, const HighPrecisionFloat &);

    friend bool operator<(const HighPrecisionFloat &, const HighPrecisionFloat &);

    friend bool operator>(const HighPrecisionFloat &, const HighPrecisionFloat &);

    friend bool operator==(const HighPrecisionFloat &, const HighPrecisionFloat &);

    friend HighPrecisionFloat operator-(const HighPrecisionFloat &);

    friend std::ostream &operator<<(std::ostream &, const HighPrecisionFloat &);

    explicit operator long double() const;
};


#endif //HIGHPRECISIONFLOAT_H
