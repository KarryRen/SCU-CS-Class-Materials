capture log close
log using "F:\fjx学习\计量\stata入门\logfile\test.log",replace
use nlsy2000,clear
reg lropc00 age00 msa ctrlcity north_central south00 west sch_10 diploma_hs ged_hs smcol bachelor_col master_col doctor_col if female==0 & white==1
estimates store male
reg lropc00 age00 msa ctrlcity north_central south00 west sch_10 diploma_hs ged_hs smcol bachelor_col master_col doctor_col if female==1 & white==1
estimates store female
oaxaca8 male female, weight(1 0 0.651) notf

replace afqtp89=afqtp89/100.0

reg lropc00 age00 msa ctrlcity north_central south00 west sch_10 diploma_hs ged_hs smcol bachelor_col master_col doctor_col afqtp89 if female==0 & white==1
estimates store male
reg lropc00 age00 msa ctrlcity north_central south00 west sch_10 diploma_hs ged_hs smcol bachelor_col master_col doctor_col afqtp89 if female==1 & white==1
estimates store female
oaxaca8 male female, weight(1 0 0.651) notf