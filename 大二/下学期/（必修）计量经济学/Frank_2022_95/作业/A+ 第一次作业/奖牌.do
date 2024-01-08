clear
cd "F:\fjx学习\计量\stata入门\dofile\奖牌.do"
capture log close  
log using "F:\fjx学习\计量\stata入门\logfile\test.log",replace 
cd "F:\fjx学习\计量" 
shell out RESTAT_Olympic_Data.xlsx
import excel "RESTAT_Olympic_Data", sheet("Sheet2") firstrow clear 
reg medaltot gdp pop host planned perform
shell out RESTAT_Olympic_Data.xlsx
import excel "RESTAT_Olympic_Data", sheet("Sheet3") firstrow clear 
gen pre=_b[gdp]*gdp+_b[pop]*pop+_b[host]*host+_b[planned]*planned+_b[_cons]+_b[perform]*perform
tab pre
save "F:\fjx学习\计量\stata入门\datafile\奖牌预测.dta"