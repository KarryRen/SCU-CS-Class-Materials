#pragma once
#include<iostream>
template<class t>
class mystack {
private:
	t* pfir;
	size_t len;
	size_t maxlen;
	//size_t 类型表示C中任何对象所能达到的最大长度
	//size_t 在数组下标和内存管理函数之类的地方广泛使用
public:
	mystack() { pfir = NULL; len = 0; maxlen = 0; }
	~mystack() { if (pfir)delete[] pfir; pfir = NULL; len = 0; maxlen = 0; }
	void push(const t& data);
	void pop() { len--; }
	t gettop() { return pfir[len - 1]; }
	bool empty() {
		if (len == 0)return true;
		else return false;
	}
};

template<class t>
//入栈操作实现
void mystack<t>::push(const t& data) {
	if (len <= maxlen) {
		maxlen = maxlen + ((maxlen >> 1) > 1 ? (maxlen >> 1) : 1);
		/*
		三目运算符:   <表达式1> ? <表达式2> : <表达式3>;
		返回值：先求表达式 1 的值，如果为真，则执行表达式 2，
		并返回表达式 2 的结果；
		如果表达式 1 的值为假，则执行表达式 3，
		并返回表达式 3 的结果。

		位运算：>>1 表示二进制右移1位，相当于除以2
		相比在代码中直接使用(+、-、*、/)运算符，
		合理的运用位运算更能显著提高代码在机器上的执行效率。
		*/
		t* ptemp = new t[maxlen];
		if (pfir) {
			memcpy(ptemp, pfir, sizeof(t) * len);
			delete[] pfir;
		}
		pfir = ptemp;
	};
	pfir[len++] = data;
}
