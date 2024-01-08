*Author: RenKai
*Date: 2022-4-1

**********************************************************************
*****************第二次作业第 3 问 房价推断************************
**********************************************************************

*** 基本操作
clear all          // 清空内存
set more off       // 使结果窗口持续显示结果
set maxvar 32767   // 最大变量数
set linesize 100   // 一行的数目

capture log close
log using "C:\Users\16332\Desktop\Economitrics\HomeWork\4.18_Third\Decision\Q3\test.log",replace
use "C:\Users\16332\Desktop\Economitrics\HomeWork\4.18_Third\Decision\Q3\hprice1.dta"

*** Q(a) 进行二元回归
reg price assess

*** Q(b) 受约束模型
gen tmp = price - assess
reg tmp


*** Q(c) 不受约束模型
reg price assess sqrft lotsize bdrms


*** Q(e)
gen lnPrice = log(Price)
