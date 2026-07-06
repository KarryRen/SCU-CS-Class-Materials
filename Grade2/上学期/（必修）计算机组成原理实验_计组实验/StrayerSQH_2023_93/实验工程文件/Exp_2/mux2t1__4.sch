<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="sel" />
        <signal name="a(3:0)" />
        <signal name="XLXN_3(3:0)" />
        <signal name="b(3:0)" />
        <signal name="XLXN_5(3:0)" />
        <signal name="o(3:0)" />
        <signal name="a(0)" />
        <signal name="b(0)" />
        <signal name="b(1)" />
        <signal name="b(2)" />
        <signal name="b(3)" />
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
        <instance x="1648" y="1152" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1648" y="1536" name="XLXI_2" orien="R0">
        </instance>
        <instance x="1648" y="1856" name="XLXI_3" orien="R0">
        </instance>
        <instance x="1648" y="2176" name="XLXI_4" orien="R0">
        </instance>
        <branch name="sel">
            <wire x2="1488" y1="896" y2="1120" x1="1488" />
            <wire x2="1648" y1="1120" y2="1120" x1="1488" />
            <wire x2="1488" y1="1120" y2="1504" x1="1488" />
            <wire x2="1648" y1="1504" y2="1504" x1="1488" />
            <wire x2="1488" y1="1504" y2="1824" x1="1488" />
            <wire x2="1648" y1="1824" y2="1824" x1="1488" />
            <wire x2="1488" y1="1824" y2="2144" x1="1488" />
            <wire x2="1648" y1="2144" y2="2144" x1="1488" />
        </branch>
        <branch name="a(3:0)">
            <wire x2="1232" y1="1248" y2="1248" x1="896" />
            <wire x2="1232" y1="1248" y2="1376" x1="1232" />
            <wire x2="1232" y1="1376" y2="1696" x1="1232" />
            <wire x2="1232" y1="1696" y2="2016" x1="1232" />
            <wire x2="1232" y1="976" y2="992" x1="1232" />
            <wire x2="1232" y1="992" y2="1248" x1="1232" />
        </branch>
        <branch name="b(3:0)">
            <wire x2="1040" y1="1648" y2="1648" x1="896" />
            <wire x2="1040" y1="1648" y2="1760" x1="1040" />
            <wire x2="1040" y1="1760" y2="2080" x1="1040" />
            <wire x2="1040" y1="1056" y2="1440" x1="1040" />
            <wire x2="1040" y1="1440" y2="1648" x1="1040" />
        </branch>
        <branch name="o(3:0)">
            <wire x2="2336" y1="976" y2="992" x1="2336" />
            <wire x2="2336" y1="992" y2="1376" x1="2336" />
            <wire x2="2336" y1="1376" y2="1472" x1="2336" />
            <wire x2="2448" y1="1472" y2="1472" x1="2336" />
            <wire x2="2336" y1="1472" y2="1696" x1="2336" />
            <wire x2="2336" y1="1696" y2="2016" x1="2336" />
        </branch>
        <bustap x2="1328" y1="992" y2="992" x1="1232" />
        <bustap x2="1328" y1="1376" y2="1376" x1="1232" />
        <bustap x2="1328" y1="1696" y2="1696" x1="1232" />
        <bustap x2="1328" y1="2016" y2="2016" x1="1232" />
        <bustap x2="1136" y1="1056" y2="1056" x1="1040" />
        <bustap x2="1136" y1="1440" y2="1440" x1="1040" />
        <bustap x2="1136" y1="1760" y2="1760" x1="1040" />
        <bustap x2="1136" y1="2080" y2="2080" x1="1040" />
        <branch name="a(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1360" y="992" type="branch" />
            <wire x2="1360" y1="992" y2="992" x1="1328" />
            <wire x2="1440" y1="992" y2="992" x1="1360" />
            <wire x2="1648" y1="992" y2="992" x1="1440" />
        </branch>
        <branch name="b(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1184" y="1056" type="branch" />
            <wire x2="1184" y1="1056" y2="1056" x1="1136" />
            <wire x2="1280" y1="1056" y2="1056" x1="1184" />
            <wire x2="1648" y1="1056" y2="1056" x1="1280" />
        </branch>
        <branch name="b(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1184" y="1440" type="branch" />
            <wire x2="1184" y1="1440" y2="1440" x1="1136" />
            <wire x2="1312" y1="1440" y2="1440" x1="1184" />
            <wire x2="1328" y1="1440" y2="1440" x1="1312" />
            <wire x2="1632" y1="1440" y2="1440" x1="1328" />
            <wire x2="1648" y1="1440" y2="1440" x1="1632" />
        </branch>
        <branch name="b(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1168" y="1760" type="branch" />
            <wire x2="1168" y1="1760" y2="1760" x1="1136" />
            <wire x2="1312" y1="1760" y2="1760" x1="1168" />
            <wire x2="1648" y1="1760" y2="1760" x1="1312" />
        </branch>
        <branch name="b(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1184" y="2080" type="branch" />
            <wire x2="1184" y1="2080" y2="2080" x1="1136" />
            <wire x2="1280" y1="2080" y2="2080" x1="1184" />
            <wire x2="1648" y1="2080" y2="2080" x1="1280" />
        </branch>
        <branch name="a(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1376" y="2016" type="branch" />
            <wire x2="1376" y1="2016" y2="2016" x1="1328" />
            <wire x2="1440" y1="2016" y2="2016" x1="1376" />
            <wire x2="1456" y1="2016" y2="2016" x1="1440" />
            <wire x2="1648" y1="2016" y2="2016" x1="1456" />
        </branch>
        <branch name="a(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1376" y="1696" type="branch" />
            <wire x2="1376" y1="1696" y2="1696" x1="1328" />
            <wire x2="1440" y1="1696" y2="1696" x1="1376" />
            <wire x2="1648" y1="1696" y2="1696" x1="1440" />
        </branch>
        <branch name="a(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1376" y="1376" type="branch" />
            <wire x2="1376" y1="1376" y2="1376" x1="1328" />
            <wire x2="1440" y1="1376" y2="1376" x1="1376" />
            <wire x2="1648" y1="1376" y2="1376" x1="1440" />
        </branch>
        <bustap x2="2240" y1="992" y2="992" x1="2336" />
        <bustap x2="2240" y1="1376" y2="1376" x1="2336" />
        <bustap x2="2240" y1="1696" y2="1696" x1="2336" />
        <bustap x2="2240" y1="2016" y2="2016" x1="2336" />
        <branch name="o(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2128" y="992" type="branch" />
            <wire x2="2128" y1="992" y2="992" x1="2032" />
            <wire x2="2240" y1="992" y2="992" x1="2128" />
        </branch>
        <branch name="o(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2112" y="1376" type="branch" />
            <wire x2="2112" y1="1376" y2="1376" x1="2032" />
            <wire x2="2240" y1="1376" y2="1376" x1="2112" />
        </branch>
        <branch name="o(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2112" y="1696" type="branch" />
            <wire x2="2112" y1="1696" y2="1696" x1="2032" />
            <wire x2="2240" y1="1696" y2="1696" x1="2112" />
        </branch>
        <branch name="o(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="2016" type="branch" />
            <wire x2="2144" y1="2016" y2="2016" x1="2032" />
            <wire x2="2240" y1="2016" y2="2016" x1="2144" />
        </branch>
        <iomarker fontsize="28" x="896" y="1248" name="a(3:0)" orien="R180" />
        <iomarker fontsize="28" x="896" y="1648" name="b(3:0)" orien="R180" />
        <iomarker fontsize="28" x="1488" y="896" name="sel" orien="R270" />
        <iomarker fontsize="28" x="2448" y="1472" name="o(3:0)" orien="R0" />
    </sheet>
</drawing>