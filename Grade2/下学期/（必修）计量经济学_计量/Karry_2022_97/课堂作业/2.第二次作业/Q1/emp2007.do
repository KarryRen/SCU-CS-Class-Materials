*Author: RenKai
*Date: 2022-4-1

**********************************************************************
*****************第二次作业第一问 多元线性回归************************
**********************************************************************

*** 基本操作
clear all          // 清空内存
set more off       // 使结果窗口持续显示结果
set maxvar 32767   // 最大变量数
set linesize 100   // 一行的数目

capture log close
log using "C:\Users\16332\Desktop\Economitrics\HomeWork\4.18_Third\Decision\Q1\test.log",replace
use "C:\Users\16332\Desktop\Economitrics\HomeWork\4.18_Third\Decision\Q1\emp2007.dta"

*** Q(b) 复现回归结果
reg lnw eduy
reg lnw eduy age

*** Q(c) 估计一个新的多元线性模型
gen age_squred = age * age
reg lnw eduy age age_squred

*** Q(d)
** Step 1 将 eduy 对 age 和 age_squred 回归 并得到残差 x_1
reg eduy age age_squred
predict eduy_hat
gen x_1 = eduy - eduy_hat
reg lnw x_1

*** Q(e)
gen exp=age - eduy - 6
reg lnw eduy age age_squred exp
