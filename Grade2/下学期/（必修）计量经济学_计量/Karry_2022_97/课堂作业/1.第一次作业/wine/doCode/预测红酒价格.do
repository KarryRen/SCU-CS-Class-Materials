*Author: RenKai
*Date: 2022-4-1

**********************************************************************
*************************葡萄酒价格预测*******************************
**********************************************************************

*** 基本操作
clear all          // 清空内存
set more off       // 使结果窗口持续显示结果
set maxvar 32767   // 最大变量数
set linesize 100   // 一行的数目

capture log close
log using "D:\Economitrics\HomeWork\3.28_Second\wine\logFile\test.log",replace
use "D:\Economitrics\HomeWork\3.28_Second\wine\processedDataFile\rawData.dta"
*** 描述性统计 -ln(price) of year 绘制图一
generate lnPrice = ln(price)
twoway (sc lnPrice year) (lfit lnPrice year)
twoway (sc lnPrice age) (lfit lnPrice age)
reg lnPrice year // 同样的 -0.03 的结果

*** 描述性统计 -sum har of year 绘制图二
mean()
generate tmp_year = year - 1900
twoway ///
 (scatter sum har if price>=28.30769, mcolor(gs5) msymbol(smcircle_hollow) mlabel(tmp_year))  ///
 (scatter sum har if price < 28.30769, mcolor(gs11) msymbol(smcircle_hollow) mlabel(tmp_year))


*** run 回归 - 结果相同
reg lnPrice age
reg lnPrice age sum har win
reg lnPrice age sum har win sep
predict pre_lnPrice
generate pre_price = exp(pre_lnPrice)
gen pre_priceIndex = pre_price/((price[7] + price[8] + price[10] + price[12]) / 4)

*** run 预测
clear
use "C:\Users\16332\Desktop\Economitrics\HomeWork\3.28_Second\wine\processedDataFile\testData.dta"
predict pre_lnPrice
generate pre_price=exp(pre_lnPrice)
label var pre_price "预测的 price"
generate pre_priceIndex = pre_price/(52.75)
label var pre_priceIndex "预测的价格指数"

*** 展示结果
clear
use "C:\Users\16332\Desktop\Economitrics\HomeWork\3.28_Second\wine\paper\Result\综合.dta"
generate tmp_year = year - 1900
twoway ///
 (scatter sum har if (price>=28.30769 & year<=1980), mcolor(gs5) msymbol(smcircle_hollow) mlabel(tmp_year)) ///
 (scatter sum har if (price < 28.30769 & year<=1980), mcolor(gs11) msymbol(smcircle_hollow) mlabel(tmp_year)) ///
 (scatter sum har if (price>=28.30769 & year > 1980), mcolor(red) msymbol(smcircle_hollow) mlabel(tmp_year)) ///
 (scatter sum har if (price < 28.30769 & year>1980), mcolor(blue) msymbol(smcircle_hollow) mlabel(tmp_year)) 
