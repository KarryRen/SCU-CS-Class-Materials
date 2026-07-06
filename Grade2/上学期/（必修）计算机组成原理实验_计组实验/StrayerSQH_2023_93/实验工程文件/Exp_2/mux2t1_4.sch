<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="sel" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="a(3:0)" />
        <signal name="b(3:0)" />
        <signal name="o(3:0)" />
        <signal name="a(0)" />
        <signal name="b(0)" />
        <signal name="b(1)" />
        <signal name="b(2)" />
        <signal name="b(3)" />
        <signal name="XLXN_13" />
        <signal name="a(3)" />
        <signal name="a(2)" />
        <signal name="a(1)" />
        <signal name="o(0)" />
        <signal name="o(1)" />
        <signal name="o(2)" />
        <signal name="o(3)" />
        <port polarity="Input" name="sel" />
        <port polarity="Input" name="a(3:0)" />
        <port polarity="Input" name="b(3:0)" />
        <port polarity="Output" name="o(3:0)" />
        <blockdef name="mux2t1">
            <timestamp>2005-12-31T17:42:15</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
        </blockdef>
        <block symbolname="mux2t1" name="XLXI_1">
            <blockpin signalname="a(0)" name="a" />
            <blockpin signalname="b(0)" name="b" />
            <blockpin signalname="sel" name="sel" />
            <blockpin signalname="o(0)" name="o" />
        </block>
        <block symbolname="mux2t1" name="XLXI_2">
            <blockpin signalname="a(1)" name="a" />
            <blockpin signalname="b(1)" name="b" />
            <blockpin signalname="sel" name="sel" />
            <blockpin signalname="o(1)" name="o" />
        </block>
        <block symbolname="mux2t1" name="XLXI_3">
            <blockpin signalname="a(2)" name="a" />
            <blockpin signalname="b(2)" name="b" />
            <blockpin signalname="sel" name="sel" />
            <blockpin signalname="o(2)" name="o" />
        </block>
        <block symbolname="mux2t1" name="XLXI_4">
            <blockpin signalname="a(3)" name="a" />
            <blockpin signalname="b(3)" name="b" />
            <blockpin signalname="sel" name="sel" />
            <blockpin signalname="o(3)" name="o" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1056" y="848" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1056" y="1232" name="XLXI_2" orien="R0">
        </instance>
        <instance x="1056" y="1552" name="XLXI_3" orien="R0">
        </instance>
        <instance x="1056" y="1872" name="XLXI_4" orien="R0">
        </instance>
        <branch name="sel">
            <wire x2="896" y1="592" y2="816" x1="896" />
            <wire x2="1056" y1="816" y2="816" x1="896" />
            <wire x2="896" y1="816" y2="1200" x1="896" />
            <wire x2="1056" y1="1200" y2="1200" x1="896" />
            <wire x2="896" y1="1200" y2="1520" x1="896" />
            <wire x2="1056" y1="1520" y2="1520" x1="896" />
            <wire x2="896" y1="1520" y2="1840" x1="896" />
            <wire x2="1056" y1="1840" y2="1840" x1="896" />
        </branch>
        <branch name="a(3:0)">
            <wire x2="640" y1="944" y2="944" x1="304" />
            <wire x2="640" y1="944" y2="1072" x1="640" />
            <wire x2="640" y1="1072" y2="1392" x1="640" />
            <wire x2="640" y1="1392" y2="1712" x1="640" />
            <wire x2="640" y1="672" y2="688" x1="640" />
            <wire x2="640" y1="688" y2="944" x1="640" />
        </branch>
        <branch name="b(3:0)">
            <wire x2="448" y1="1344" y2="1344" x1="304" />
            <wire x2="448" y1="1344" y2="1456" x1="448" />
            <wire x2="448" y1="1456" y2="1776" x1="448" />
            <wire x2="448" y1="752" y2="1136" x1="448" />
            <wire x2="448" y1="1136" y2="1344" x1="448" />
        </branch>
        <iomarker fontsize="28" x="304" y="944" name="a(3:0)" orien="R180" />
        <iomarker fontsize="28" x="304" y="1344" name="b(3:0)" orien="R180" />
        <iomarker fontsize="28" x="896" y="592" name="sel" orien="R270" />
        <branch name="o(3:0)">
            <wire x2="1744" y1="672" y2="688" x1="1744" />
            <wire x2="1744" y1="688" y2="1072" x1="1744" />
            <wire x2="1744" y1="1072" y2="1168" x1="1744" />
            <wire x2="1856" y1="1168" y2="1168" x1="1744" />
            <wire x2="1744" y1="1168" y2="1392" x1="1744" />
            <wire x2="1744" y1="1392" y2="1712" x1="1744" />
        </branch>
        <iomarker fontsize="28" x="1856" y="1168" name="o(3:0)" orien="R0" />
        <bustap x2="736" y1="688" y2="688" x1="640" />
        <bustap x2="736" y1="1072" y2="1072" x1="640" />
        <bustap x2="736" y1="1392" y2="1392" x1="640" />
        <bustap x2="736" y1="1712" y2="1712" x1="640" />
        <bustap x2="544" y1="752" y2="752" x1="448" />
        <bustap x2="544" y1="1136" y2="1136" x1="448" />
        <bustap x2="544" y1="1456" y2="1456" x1="448" />
        <bustap x2="544" y1="1776" y2="1776" x1="448" />
        <branch name="a(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="768" y="688" type="branch" />
            <wire x2="768" y1="688" y2="688" x1="736" />
            <wire x2="848" y1="688" y2="688" x1="768" />
            <wire x2="1056" y1="688" y2="688" x1="848" />
        </branch>
        <branch name="b(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="592" y="752" type="branch" />
            <wire x2="592" y1="752" y2="752" x1="544" />
            <wire x2="688" y1="752" y2="752" x1="592" />
            <wire x2="1056" y1="752" y2="752" x1="688" />
        </branch>
        <branch name="b(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="592" y="1136" type="branch" />
            <wire x2="592" y1="1136" y2="1136" x1="544" />
            <wire x2="720" y1="1136" y2="1136" x1="592" />
            <wire x2="736" y1="1136" y2="1136" x1="720" />
            <wire x2="1040" y1="1136" y2="1136" x1="736" />
            <wire x2="1056" y1="1136" y2="1136" x1="1040" />
        </branch>
        <branch name="b(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="576" y="1456" type="branch" />
            <wire x2="576" y1="1456" y2="1456" x1="544" />
            <wire x2="720" y1="1456" y2="1456" x1="576" />
            <wire x2="1056" y1="1456" y2="1456" x1="720" />
        </branch>
        <branch name="b(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="592" y="1776" type="branch" />
            <wire x2="592" y1="1776" y2="1776" x1="544" />
            <wire x2="688" y1="1776" y2="1776" x1="592" />
            <wire x2="1056" y1="1776" y2="1776" x1="688" />
        </branch>
        <branch name="a(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="784" y="1712" type="branch" />
            <wire x2="784" y1="1712" y2="1712" x1="736" />
            <wire x2="848" y1="1712" y2="1712" x1="784" />
            <wire x2="864" y1="1712" y2="1712" x1="848" />
            <wire x2="1056" y1="1712" y2="1712" x1="864" />
        </branch>
        <branch name="a(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="784" y="1392" type="branch" />
            <wire x2="784" y1="1392" y2="1392" x1="736" />
            <wire x2="848" y1="1392" y2="1392" x1="784" />
            <wire x2="1056" y1="1392" y2="1392" x1="848" />
        </branch>
        <branch name="a(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="784" y="1072" type="branch" />
            <wire x2="784" y1="1072" y2="1072" x1="736" />
            <wire x2="848" y1="1072" y2="1072" x1="784" />
            <wire x2="1056" y1="1072" y2="1072" x1="848" />
        </branch>
        <bustap x2="1648" y1="688" y2="688" x1="1744" />
        <bustap x2="1648" y1="1072" y2="1072" x1="1744" />
        <bustap x2="1648" y1="1392" y2="1392" x1="1744" />
        <bustap x2="1648" y1="1712" y2="1712" x1="1744" />
        <branch name="o(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1536" y="688" type="branch" />
            <wire x2="1536" y1="688" y2="688" x1="1440" />
            <wire x2="1648" y1="688" y2="688" x1="1536" />
        </branch>
        <branch name="o(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1520" y="1072" type="branch" />
            <wire x2="1520" y1="1072" y2="1072" x1="1440" />
            <wire x2="1648" y1="1072" y2="1072" x1="1520" />
        </branch>
        <branch name="o(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1520" y="1392" type="branch" />
            <wire x2="1520" y1="1392" y2="1392" x1="1440" />
            <wire x2="1648" y1="1392" y2="1392" x1="1520" />
        </branch>
        <branch name="o(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1552" y="1712" type="branch" />
            <wire x2="1552" y1="1712" y2="1712" x1="1440" />
            <wire x2="1648" y1="1712" y2="1712" x1="1552" />
        </branch>
    </sheet>
</drawing>