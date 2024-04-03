*Author: RenKai
*Date: 2022-6-4

**********************************************************************
*****************第五次作业 ******************************************
**********************************************************************

*** 基本操作
clear all          // 清空内存
set more off       // 使结果窗口持续显示结果
set maxvar 32767   // 最大变量数
set linesize 100   // 一行的数目

capture log close
log using "D:\Economitrics\HomeWork\第五次\test.log",replace
use "D:\Economitrics\HomeWork\第五次\nlsy2000.dta"

** 2.1 直接回归
reg lropc00 age00 msa ctrlcity north_central south00 west sch_10 diploma_hs ged_hs smcol bachelor_col master_col doctor_col if female==0 & white==1 // 在男性白人中进行回归
estimates store male // 保存回归结果

reg lropc00 age00 msa ctrlcity north_central south00 west sch_10 diploma_hs ged_hs smcol bachelor_col master_col doctor_col if female==1 & white==1 // 在女性白人中进行回归
estimates store female // 保存回归结果

oaxaca8 male female, weight(0.651) notf


** 2.2 加一个变量后回归

replace afqtp89=afqtp89/100.0 // 改变 afqtp89 的单位

reg lropc00 age00 msa ctrlcity north_central south00 west sch_10 diploma_hs ged_hs smcol bachelor_col master_col doctor_col afqtp89 if female==0 & white==1
estimates store male

reg lropc00 age00 msa ctrlcity north_central south00 west sch_10 diploma_hs ged_hs smcol bachelor_col master_col doctor_col afqtp89 if female==1 & white==1
estimates store female

oaxaca8 male female, weight(1 0 0.651) detail notf