<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="a" />
        <signal name="XLXN_6" />
        <signal name="b" />
        <signal name="sel" />
        <signal name="o" />
        <signal name="XLXN_11" />
        <port polarity="Input" name="a" />
        <port polarity="Input" name="b" />
        <port polarity="Input" name="sel" />
        <port polarity="Output" name="o" />
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="a" name="I0" />
            <blockpin signalname="sel" name="I1" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="b" name="I0" />
            <blockpin signalname="XLXN_1" name="I1" />
            <blockpin signalname="XLXN_11" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_3">
            <blockpin signalname="XLXN_11" name="I0" />
            <blockpin signalname="XLXN_2" name="I1" />
            <blockpin signalname="o" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_4">
            <blockpin signalname="sel" name="I" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1120" y="640" name="XLXI_1" orien="R0" />
        <instance x="1120" y="880" name="XLXI_2" orien="R0" />
        <instance x="1568" y="752" name="XLXI_3" orien="R0" />
        <instance x="784" y="784" name="XLXI_4" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1120" y1="752" y2="752" x1="1008" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1472" y1="544" y2="544" x1="1376" />
            <wire x2="1472" y1="544" y2="624" x1="1472" />
            <wire x2="1568" y1="624" y2="624" x1="1472" />
        </branch>
        <branch name="a">
            <wire x2="1120" y1="576" y2="576" x1="656" />
        </branch>
        <branch name="b">
            <wire x2="1120" y1="816" y2="816" x1="656" />
        </branch>
        <branch name="sel">
            <wire x2="736" y1="512" y2="512" x1="656" />
            <wire x2="1120" y1="512" y2="512" x1="736" />
            <wire x2="736" y1="512" y2="752" x1="736" />
            <wire x2="784" y1="752" y2="752" x1="736" />
        </branch>
        <iomarker fontsize="28" x="656" y="512" name="sel" orien="R180" />
        <iomarker fontsize="28" x="656" y="576" name="a" orien="R180" />
        <iomarker fontsize="28" x="656" y="816" name="b" orien="R180" />
        <branch name="o">
            <wire x2="1856" y1="656" y2="656" x1="1824" />
        </branch>
        <iomarker fontsize="28" x="1856" y="656" name="o" orien="R0" />
        <branch name="XLXN_11">
            <wire x2="1472" y1="784" y2="784" x1="1376" />
            <wire x2="1472" y1="688" y2="784" x1="1472" />
            <wire x2="1568" y1="688" y2="688" x1="1472" />
        </branch>
    </sheet>
</drawing>