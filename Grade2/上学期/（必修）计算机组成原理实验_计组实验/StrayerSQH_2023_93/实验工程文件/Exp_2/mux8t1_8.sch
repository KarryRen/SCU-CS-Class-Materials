<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="o(7:0)" />
        <signal name="o(7:4)" />
        <signal name="o(3:0)" />
        <signal name="XLXN_6(2:0)" />
        <signal name="sel(2:0)" />
        <signal name="x1(7:0)" />
        <signal name="x1(7:4)" />
        <signal name="x1(3:0)" />
        <signal name="x0(7:0)" />
        <signal name="XLXN_16(7:0)" />
        <signal name="x0(7:4)" />
        <signal name="x0(3:0)" />
        <signal name="XLXN_27(7:0)" />
        <signal name="x3(7:0)" />
        <signal name="x3(7:4)" />
        <signal name="x3(3:0)" />
        <signal name="x2(7:0)" />
        <signal name="x2(7:4)" />
        <signal name="x2(3:0)" />
        <signal name="x5(7:0)" />
        <signal name="x5(7:4)" />
        <signal name="x5(3:0)" />
        <signal name="x4(7:0)" />
        <signal name="x4(7:4)" />
        <signal name="x4(3:0)" />
        <signal name="x7(7:0)" />
        <signal name="x7(7:4)" />
        <signal name="x7(3:0)" />
        <signal name="x6(7:0)" />
        <signal name="x6(7:4)" />
        <signal name="x6(3:0)" />
        <signal name="XLXN_41(3:0)" />
        <port polarity="Output" name="o(7:0)" />
        <port polarity="Input" name="sel(2:0)" />
        <port polarity="Input" name="x1(7:0)" />
        <port polarity="Input" name="x0(7:0)" />
        <port polarity="Input" name="x3(7:0)" />
        <port polarity="Input" name="x2(7:0)" />
        <port polarity="Input" name="x5(7:0)" />
        <port polarity="Input" name="x4(7:0)" />
        <port polarity="Input" name="x7(7:0)" />
        <port polarity="Input" name="x6(7:0)" />
        <blockdef name="mux8t1__4">
            <timestamp>2024-11-21T2:44:57</timestamp>
            <rect width="256" x="64" y="-576" height="576" />
            <rect width="64" x="0" y="-556" height="24" />
            <line x2="0" y1="-544" y2="-544" x1="64" />
            <rect width="64" x="0" y="-492" height="24" />
            <line x2="0" y1="-480" y2="-480" x1="64" />
            <rect width="64" x="0" y="-428" height="24" />
            <line x2="0" y1="-416" y2="-416" x1="64" />
            <rect width="64" x="0" y="-364" height="24" />
            <line x2="0" y1="-352" y2="-352" x1="64" />
            <rect width="64" x="0" y="-300" height="24" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <rect width="64" x="0" y="-236" height="24" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-556" height="24" />
            <line x2="384" y1="-544" y2="-544" x1="320" />
        </blockdef>
        <block symbolname="mux8t1__4" name="XLXI_1">
            <blockpin signalname="sel(2:0)" name="sel(2:0)" />
            <blockpin signalname="x1(7:4)" name="x1(3:0)" />
            <blockpin signalname="x0(7:4)" name="x0(3:0)" />
            <blockpin signalname="x3(7:4)" name="x3(3:0)" />
            <blockpin signalname="x2(7:4)" name="x2(3:0)" />
            <blockpin signalname="x5(7:4)" name="x5(3:0)" />
            <blockpin signalname="x4(7:4)" name="x4(3:0)" />
            <blockpin signalname="x7(7:4)" name="x7(3:0)" />
            <blockpin signalname="x6(7:4)" name="x6(3:0)" />
            <blockpin signalname="o(7:4)" name="o(3:0)" />
        </block>
        <block symbolname="mux8t1__4" name="XLXI_2">
            <blockpin signalname="sel(2:0)" name="sel(2:0)" />
            <blockpin signalname="x1(3:0)" name="x1(3:0)" />
            <blockpin signalname="x0(3:0)" name="x0(3:0)" />
            <blockpin signalname="x3(3:0)" name="x3(3:0)" />
            <blockpin signalname="x2(3:0)" name="x2(3:0)" />
            <blockpin signalname="x5(3:0)" name="x5(3:0)" />
            <blockpin signalname="x4(3:0)" name="x4(3:0)" />
            <blockpin signalname="x7(3:0)" name="x7(3:0)" />
            <blockpin signalname="x6(3:0)" name="x6(3:0)" />
            <blockpin signalname="o(3:0)" name="o(3:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1472" y="880" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1488" y="1824" name="XLXI_2" orien="R0">
        </instance>
        <branch name="o(7:0)">
            <wire x2="2096" y1="336" y2="816" x1="2096" />
            <wire x2="2096" y1="816" y2="1280" x1="2096" />
            <wire x2="2256" y1="816" y2="816" x1="2096" />
        </branch>
        <bustap x2="2000" y1="336" y2="336" x1="2096" />
        <bustap x2="2000" y1="1280" y2="1280" x1="2096" />
        <branch name="o(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1920" y="336" type="branch" />
            <wire x2="1920" y1="336" y2="336" x1="1856" />
            <wire x2="2000" y1="336" y2="336" x1="1920" />
        </branch>
        <branch name="o(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1952" y="1280" type="branch" />
            <wire x2="1952" y1="1280" y2="1280" x1="1872" />
            <wire x2="2000" y1="1280" y2="1280" x1="1952" />
        </branch>
        <iomarker fontsize="28" x="2256" y="816" name="o(7:0)" orien="R0" />
        <branch name="sel(2:0)">
            <wire x2="1472" y1="336" y2="336" x1="1168" />
            <wire x2="1168" y1="336" y2="976" x1="1168" />
            <wire x2="1168" y1="976" y2="1280" x1="1168" />
            <wire x2="1488" y1="1280" y2="1280" x1="1168" />
            <wire x2="1488" y1="976" y2="976" x1="1168" />
        </branch>
        <bustap x2="1024" y1="400" y2="400" x1="928" />
        <bustap x2="1024" y1="1344" y2="1344" x1="928" />
        <branch name="x1(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1264" y="400" type="branch" />
            <wire x2="1264" y1="400" y2="400" x1="1024" />
            <wire x2="1472" y1="400" y2="400" x1="1264" />
        </branch>
        <branch name="x1(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1264" y="1344" type="branch" />
            <wire x2="1264" y1="1344" y2="1344" x1="1024" />
            <wire x2="1488" y1="1344" y2="1344" x1="1264" />
        </branch>
        <bustap x2="976" y1="464" y2="464" x1="880" />
        <bustap x2="976" y1="1408" y2="1408" x1="880" />
        <iomarker fontsize="28" x="720" y="592" name="x0(7:0)" orien="R180" />
        <iomarker fontsize="28" x="720" y="528" name="x1(7:0)" orien="R180" />
        <branch name="x0(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="464" type="branch" />
            <wire x2="1232" y1="464" y2="464" x1="976" />
            <wire x2="1472" y1="464" y2="464" x1="1232" />
        </branch>
        <branch name="x0(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1408" type="branch" />
            <wire x2="1232" y1="1408" y2="1408" x1="976" />
            <wire x2="1488" y1="1408" y2="1408" x1="1232" />
        </branch>
        <branch name="x0(7:0)">
            <wire x2="880" y1="592" y2="592" x1="720" />
            <wire x2="880" y1="592" y2="1408" x1="880" />
            <wire x2="880" y1="448" y2="592" x1="880" />
        </branch>
        <branch name="x1(7:0)">
            <wire x2="928" y1="528" y2="528" x1="720" />
            <wire x2="928" y1="528" y2="1344" x1="928" />
            <wire x2="928" y1="384" y2="400" x1="928" />
            <wire x2="928" y1="400" y2="528" x1="928" />
        </branch>
        <branch name="x3(7:0)">
            <wire x2="992" y1="656" y2="656" x1="720" />
            <wire x2="992" y1="656" y2="1472" x1="992" />
            <wire x2="992" y1="1472" y2="1488" x1="992" />
            <wire x2="992" y1="528" y2="656" x1="992" />
        </branch>
        <iomarker fontsize="28" x="720" y="656" name="x3(7:0)" orien="R180" />
        <bustap x2="1088" y1="528" y2="528" x1="992" />
        <bustap x2="1088" y1="1472" y2="1472" x1="992" />
        <branch name="x3(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1216" y="528" type="branch" />
            <wire x2="1216" y1="528" y2="528" x1="1088" />
            <wire x2="1472" y1="528" y2="528" x1="1216" />
        </branch>
        <branch name="x3(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1200" y="1472" type="branch" />
            <wire x2="1200" y1="1472" y2="1472" x1="1088" />
            <wire x2="1488" y1="1472" y2="1472" x1="1200" />
        </branch>
        <bustap x2="1120" y1="1552" y2="1552" x1="1024" />
        <branch name="x2(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="592" type="branch" />
            <wire x2="1232" y1="592" y2="592" x1="1120" />
            <wire x2="1472" y1="592" y2="592" x1="1232" />
        </branch>
        <branch name="x2(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1536" type="branch" />
            <wire x2="1120" y1="1536" y2="1552" x1="1120" />
            <wire x2="1232" y1="1536" y2="1536" x1="1120" />
            <wire x2="1488" y1="1536" y2="1536" x1="1232" />
        </branch>
        <bustap x2="1120" y1="592" y2="592" x1="1024" />
        <branch name="x2(7:0)">
            <wire x2="1024" y1="720" y2="720" x1="720" />
            <wire x2="1024" y1="720" y2="1552" x1="1024" />
            <wire x2="1024" y1="592" y2="720" x1="1024" />
        </branch>
        <iomarker fontsize="28" x="720" y="720" name="x2(7:0)" orien="R180" />
        <branch name="x5(7:0)">
            <wire x2="800" y1="912" y2="912" x1="528" />
            <wire x2="800" y1="912" y2="1744" x1="800" />
            <wire x2="800" y1="784" y2="912" x1="800" />
        </branch>
        <bustap x2="896" y1="784" y2="784" x1="800" />
        <bustap x2="896" y1="1728" y2="1728" x1="800" />
        <iomarker fontsize="28" x="528" y="912" name="x5(7:0)" orien="R180" />
        <branch name="x5(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1248" y="656" type="branch" />
            <wire x2="1184" y1="784" y2="784" x1="896" />
            <wire x2="1184" y1="656" y2="784" x1="1184" />
            <wire x2="1248" y1="656" y2="656" x1="1184" />
            <wire x2="1472" y1="656" y2="656" x1="1248" />
        </branch>
        <branch name="x5(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1248" y="1600" type="branch" />
            <wire x2="1184" y1="1728" y2="1728" x1="896" />
            <wire x2="1184" y1="1600" y2="1728" x1="1184" />
            <wire x2="1248" y1="1600" y2="1600" x1="1184" />
            <wire x2="1488" y1="1600" y2="1600" x1="1248" />
        </branch>
        <branch name="x4(7:0)">
            <wire x2="624" y1="1104" y2="1104" x1="352" />
            <wire x2="624" y1="1104" y2="1936" x1="624" />
            <wire x2="624" y1="976" y2="1104" x1="624" />
        </branch>
        <bustap x2="720" y1="976" y2="976" x1="624" />
        <bustap x2="720" y1="1920" y2="1920" x1="624" />
        <iomarker fontsize="28" x="352" y="1104" name="x4(7:0)" orien="R180" />
        <branch name="x4(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="720" type="branch" />
            <wire x2="1088" y1="976" y2="976" x1="720" />
            <wire x2="1088" y1="720" y2="976" x1="1088" />
            <wire x2="1232" y1="720" y2="720" x1="1088" />
            <wire x2="1472" y1="720" y2="720" x1="1232" />
        </branch>
        <branch name="x4(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1264" y="1664" type="branch" />
            <wire x2="1200" y1="1920" y2="1920" x1="720" />
            <wire x2="1200" y1="1664" y2="1920" x1="1200" />
            <wire x2="1264" y1="1664" y2="1664" x1="1200" />
            <wire x2="1488" y1="1664" y2="1664" x1="1264" />
        </branch>
        <branch name="x7(7:0)">
            <wire x2="672" y1="1248" y2="1248" x1="400" />
            <wire x2="672" y1="1248" y2="2080" x1="672" />
            <wire x2="672" y1="1120" y2="1248" x1="672" />
        </branch>
        <bustap x2="768" y1="1120" y2="1120" x1="672" />
        <bustap x2="768" y1="2064" y2="2064" x1="672" />
        <iomarker fontsize="28" x="400" y="1248" name="x7(7:0)" orien="R180" />
        <branch name="x7(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1280" y="784" type="branch" />
            <wire x2="1200" y1="1120" y2="1120" x1="768" />
            <wire x2="1200" y1="784" y2="1120" x1="1200" />
            <wire x2="1280" y1="784" y2="784" x1="1200" />
            <wire x2="1472" y1="784" y2="784" x1="1280" />
        </branch>
        <branch name="x7(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1280" y="1728" type="branch" />
            <wire x2="1216" y1="2064" y2="2064" x1="768" />
            <wire x2="1216" y1="1728" y2="2064" x1="1216" />
            <wire x2="1280" y1="1728" y2="1728" x1="1216" />
            <wire x2="1488" y1="1728" y2="1728" x1="1280" />
        </branch>
        <branch name="x6(7:0)">
            <wire x2="688" y1="1456" y2="1456" x1="416" />
            <wire x2="688" y1="1456" y2="2288" x1="688" />
            <wire x2="688" y1="1328" y2="1456" x1="688" />
        </branch>
        <bustap x2="784" y1="1328" y2="1328" x1="688" />
        <bustap x2="784" y1="2272" y2="2272" x1="688" />
        <iomarker fontsize="28" x="416" y="1456" name="x6(7:0)" orien="R180" />
        <branch name="x6(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1264" y="848" type="branch" />
            <wire x2="864" y1="1328" y2="1328" x1="784" />
            <wire x2="864" y1="848" y2="1328" x1="864" />
            <wire x2="1264" y1="848" y2="848" x1="864" />
            <wire x2="1472" y1="848" y2="848" x1="1264" />
        </branch>
        <branch name="x6(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="960" y="2272" type="branch" />
            <wire x2="960" y1="2272" y2="2272" x1="784" />
            <wire x2="1488" y1="2272" y2="2272" x1="960" />
            <wire x2="1488" y1="1792" y2="2272" x1="1488" />
        </branch>
        <iomarker fontsize="28" x="1488" y="976" name="sel(2:0)" orien="R0" />
    </sheet>
</drawing>