<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="sel(2:0)" />
        <signal name="XLXN_2(3:0)" />
        <signal name="XLXN_3(3:0)" />
        <signal name="XLXN_4(3:0)" />
        <signal name="XLXN_5(3:0)" />
        <signal name="XLXN_6(3:0)" />
        <signal name="XLXN_7(3:0)" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="sel(1)" />
        <signal name="sel(2)" />
        <signal name="x1(3:0)" />
        <signal name="x0(3:0)" />
        <signal name="x3(3:0)" />
        <signal name="x2(3:0)" />
        <signal name="x5(3:0)" />
        <signal name="x4(3:0)" />
        <signal name="x7(3:0)" />
        <signal name="x6(3:0)" />
        <signal name="XLXN_23" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="sel(0)" />
        <signal name="o(3:0)" />
        <port polarity="Input" name="sel(2:0)" />
        <port polarity="Input" name="x1(3:0)" />
        <port polarity="Input" name="x0(3:0)" />
        <port polarity="Input" name="x3(3:0)" />
        <port polarity="Input" name="x2(3:0)" />
        <port polarity="Input" name="x5(3:0)" />
        <port polarity="Input" name="x4(3:0)" />
        <port polarity="Input" name="x7(3:0)" />
        <port polarity="Input" name="x6(3:0)" />
        <port polarity="Output" name="o(3:0)" />
        <blockdef name="mux2t1__4">
            <timestamp>2024-11-21T2:32:38</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-172" height="24" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
        </blockdef>
        <block symbolname="mux2t1__4" name="XLXI_1">
            <blockpin signalname="sel(0)" name="sel" />
            <blockpin signalname="x1(3:0)" name="a(3:0)" />
            <blockpin signalname="x0(3:0)" name="b(3:0)" />
            <blockpin signalname="XLXN_2(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="mux2t1__4" name="XLXI_2">
            <blockpin signalname="sel(0)" name="sel" />
            <blockpin signalname="x3(3:0)" name="a(3:0)" />
            <blockpin signalname="x2(3:0)" name="b(3:0)" />
            <blockpin signalname="XLXN_3(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="mux2t1__4" name="XLXI_3">
            <blockpin signalname="sel(0)" name="sel" />
            <blockpin signalname="x5(3:0)" name="a(3:0)" />
            <blockpin signalname="x4(3:0)" name="b(3:0)" />
            <blockpin signalname="XLXN_4(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="mux2t1__4" name="XLXI_4">
            <blockpin signalname="sel(0)" name="sel" />
            <blockpin signalname="x7(3:0)" name="a(3:0)" />
            <blockpin signalname="x6(3:0)" name="b(3:0)" />
            <blockpin signalname="XLXN_5(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="mux2t1__4" name="XLXI_5">
            <blockpin signalname="sel(1)" name="sel" />
            <blockpin signalname="XLXN_3(3:0)" name="a(3:0)" />
            <blockpin signalname="XLXN_2(3:0)" name="b(3:0)" />
            <blockpin signalname="XLXN_6(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="mux2t1__4" name="XLXI_6">
            <blockpin signalname="sel(1)" name="sel" />
            <blockpin signalname="XLXN_5(3:0)" name="a(3:0)" />
            <blockpin signalname="XLXN_4(3:0)" name="b(3:0)" />
            <blockpin signalname="XLXN_7(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="mux2t1__4" name="XLXI_7">
            <blockpin signalname="sel(2)" name="sel" />
            <blockpin signalname="XLXN_7(3:0)" name="a(3:0)" />
            <blockpin signalname="XLXN_6(3:0)" name="b(3:0)" />
            <blockpin signalname="o(3:0)" name="o(3:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="944" y="688" name="XLXI_1" orien="R0">
        </instance>
        <instance x="944" y="1024" name="XLXI_2" orien="R0">
        </instance>
        <instance x="944" y="1328" name="XLXI_3" orien="R0">
        </instance>
        <instance x="944" y="1648" name="XLXI_4" orien="R0">
        </instance>
        <instance x="1664" y="832" name="XLXI_5" orien="R0">
        </instance>
        <instance x="1664" y="1472" name="XLXI_6" orien="R0">
        </instance>
        <instance x="2288" y="1120" name="XLXI_7" orien="R0">
        </instance>
        <branch name="sel(2:0)">
            <wire x2="848" y1="1936" y2="1936" x1="560" />
            <wire x2="1584" y1="1936" y2="1936" x1="848" />
            <wire x2="2272" y1="1936" y2="1936" x1="1584" />
        </branch>
        <branch name="XLXN_2(3:0)">
            <wire x2="1488" y1="528" y2="528" x1="1328" />
            <wire x2="1488" y1="528" y2="800" x1="1488" />
            <wire x2="1664" y1="800" y2="800" x1="1488" />
        </branch>
        <branch name="XLXN_3(3:0)">
            <wire x2="1472" y1="864" y2="864" x1="1328" />
            <wire x2="1472" y1="736" y2="864" x1="1472" />
            <wire x2="1664" y1="736" y2="736" x1="1472" />
        </branch>
        <branch name="XLXN_4(3:0)">
            <wire x2="1488" y1="1168" y2="1168" x1="1328" />
            <wire x2="1488" y1="1168" y2="1440" x1="1488" />
            <wire x2="1664" y1="1440" y2="1440" x1="1488" />
        </branch>
        <branch name="XLXN_5(3:0)">
            <wire x2="1472" y1="1488" y2="1488" x1="1328" />
            <wire x2="1472" y1="1376" y2="1488" x1="1472" />
            <wire x2="1664" y1="1376" y2="1376" x1="1472" />
        </branch>
        <branch name="XLXN_6(3:0)">
            <wire x2="2160" y1="672" y2="672" x1="2048" />
            <wire x2="2160" y1="672" y2="1088" x1="2160" />
            <wire x2="2288" y1="1088" y2="1088" x1="2160" />
        </branch>
        <branch name="XLXN_7(3:0)">
            <wire x2="2144" y1="1312" y2="1312" x1="2048" />
            <wire x2="2144" y1="1024" y2="1312" x1="2144" />
            <wire x2="2288" y1="1024" y2="1024" x1="2144" />
        </branch>
        <iomarker fontsize="28" x="560" y="1936" name="sel(2:0)" orien="R180" />
        <bustap x2="848" y1="1936" y2="1840" x1="848" />
        <bustap x2="1584" y1="1936" y2="1840" x1="1584" />
        <bustap x2="2272" y1="1936" y2="1840" x1="2272" />
        <branch name="sel(1)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1584" y="1696" type="branch" />
            <wire x2="1664" y1="672" y2="672" x1="1584" />
            <wire x2="1584" y1="672" y2="1312" x1="1584" />
            <wire x2="1664" y1="1312" y2="1312" x1="1584" />
            <wire x2="1584" y1="1312" y2="1696" x1="1584" />
            <wire x2="1584" y1="1696" y2="1840" x1="1584" />
        </branch>
        <branch name="sel(2)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2272" y="1712" type="branch" />
            <wire x2="2288" y1="960" y2="960" x1="2272" />
            <wire x2="2272" y1="960" y2="1712" x1="2272" />
            <wire x2="2272" y1="1712" y2="1840" x1="2272" />
        </branch>
        <branch name="x1(3:0)">
            <wire x2="944" y1="592" y2="592" x1="720" />
        </branch>
        <branch name="x0(3:0)">
            <wire x2="944" y1="656" y2="656" x1="720" />
        </branch>
        <branch name="x3(3:0)">
            <wire x2="944" y1="928" y2="928" x1="720" />
        </branch>
        <branch name="x2(3:0)">
            <wire x2="944" y1="992" y2="992" x1="720" />
        </branch>
        <branch name="x5(3:0)">
            <wire x2="944" y1="1232" y2="1232" x1="720" />
        </branch>
        <branch name="x4(3:0)">
            <wire x2="944" y1="1296" y2="1296" x1="720" />
        </branch>
        <branch name="x7(3:0)">
            <wire x2="944" y1="1552" y2="1552" x1="720" />
        </branch>
        <branch name="x6(3:0)">
            <wire x2="944" y1="1616" y2="1616" x1="720" />
        </branch>
        <branch name="sel(0)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="848" y="1792" type="branch" />
            <wire x2="944" y1="528" y2="528" x1="848" />
            <wire x2="848" y1="528" y2="864" x1="848" />
            <wire x2="944" y1="864" y2="864" x1="848" />
            <wire x2="848" y1="864" y2="1168" x1="848" />
            <wire x2="944" y1="1168" y2="1168" x1="848" />
            <wire x2="848" y1="1168" y2="1488" x1="848" />
            <wire x2="944" y1="1488" y2="1488" x1="848" />
            <wire x2="848" y1="1488" y2="1792" x1="848" />
            <wire x2="848" y1="1792" y2="1840" x1="848" />
        </branch>
        <iomarker fontsize="28" x="720" y="656" name="x0(3:0)" orien="R180" />
        <iomarker fontsize="28" x="720" y="592" name="x1(3:0)" orien="R180" />
        <iomarker fontsize="28" x="720" y="928" name="x3(3:0)" orien="R180" />
        <iomarker fontsize="28" x="720" y="992" name="x2(3:0)" orien="R180" />
        <iomarker fontsize="28" x="720" y="1232" name="x5(3:0)" orien="R180" />
        <iomarker fontsize="28" x="720" y="1296" name="x4(3:0)" orien="R180" />
        <iomarker fontsize="28" x="720" y="1616" name="x6(3:0)" orien="R180" />
        <branch name="o(3:0)">
            <wire x2="2800" y1="960" y2="960" x1="2672" />
        </branch>
        <iomarker fontsize="28" x="2800" y="960" name="o(3:0)" orien="R0" />
        <iomarker fontsize="28" x="720" y="1552" name="x7(3:0)" orien="R180" />
    </sheet>
</drawing>