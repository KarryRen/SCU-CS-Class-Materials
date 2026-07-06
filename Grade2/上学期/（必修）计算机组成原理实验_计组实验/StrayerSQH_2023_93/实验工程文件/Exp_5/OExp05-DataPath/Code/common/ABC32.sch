<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1(31:0)" />
        <signal name="A(31:0)" />
        <signal name="S(31:0)" />
        <signal name="B(31:0)" />
        <signal name="sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub" />
        <signal name="sub" />
        <signal name="Co" />
        <port polarity="Input" name="A(31:0)" />
        <port polarity="Output" name="S(31:0)" />
        <port polarity="Input" name="B(31:0)" />
        <port polarity="Input" name="sub" />
        <port polarity="Output" name="Co" />
        <blockdef name="ADC32">
            <timestamp>2017-3-28T6:58:22</timestamp>
            <line x2="48" y1="-256" y2="-256" style="linewidth:W" x1="64" />
            <line x2="48" y1="-128" y2="-128" style="linewidth:W" x1="64" />
            <line x2="64" y1="-224" y2="-300" x1="64" />
            <line x2="112" y1="-224" y2="-192" x1="64" />
            <line x2="112" y1="-160" y2="-192" x1="64" />
            <line x2="64" y1="-160" y2="-76" x1="64" />
            <line x2="224" y1="-76" y2="-140" x1="64" />
            <line x2="224" y1="-300" y2="-236" x1="64" />
            <line x2="224" y1="-140" y2="-236" x1="224" />
            <line x2="240" y1="-192" y2="-192" style="linewidth:W" x1="224" />
            <line x2="128" y1="-304" y2="-276" x1="128" />
            <line x2="160" y1="-112" y2="-96" x1="160" />
            <line x2="240" y1="-96" y2="-96" x1="160" />
        </blockdef>
        <blockdef name="xor32">
            <timestamp>2014-3-19T14:4:0</timestamp>
            <arc ex="80" ey="-112" sx="80" sy="-16" r="56" cx="48" cy="-64" />
            <line x2="80" y1="-112" y2="-112" x1="144" />
            <line x2="80" y1="-16" y2="-16" x1="144" />
            <arc ex="144" ey="-112" sx="224" sy="-64" r="88" cx="148" cy="-24" />
            <arc ex="60" ey="-112" sx="64" sy="-16" r="56" cx="32" cy="-64" />
            <arc ex="224" ey="-64" sx="144" sy="-16" r="88" cx="148" cy="-104" />
            <line x2="80" y1="-96" y2="-96" style="linewidth:W" x1="32" />
            <line x2="80" y1="-32" y2="-32" style="linewidth:W" x1="32" />
            <line x2="228" y1="-64" y2="-64" style="linewidth:W" x1="256" />
        </blockdef>
        <block symbolname="xor32" name="MXOR">
            <blockpin signalname="sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub" name="A(31:0)" />
            <blockpin signalname="B(31:0)" name="B(31:0)" />
            <blockpin signalname="XLXN_1(31:0)" name="res(31:0)" />
        </block>
        <block symbolname="ADC32" name="MADC32">
            <blockpin signalname="XLXN_1(31:0)" name="B(31:0)" />
            <blockpin signalname="A(31:0)" name="A(31:0)" />
            <blockpin signalname="sub" name="C0" />
            <blockpin signalname="S(31:0)" name="S(31:0)" />
            <blockpin signalname="Co" name="Co" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="1760" height="1360">
        <branch name="A(31:0)">
            <wire x2="832" y1="288" y2="288" x1="272" />
        </branch>
        <branch name="S(31:0)">
            <wire x2="1136" y1="352" y2="352" x1="1024" />
        </branch>
        <branch name="sub">
            <wire x2="480" y1="160" y2="160" x1="224" />
            <wire x2="912" y1="160" y2="160" x1="480" />
            <wire x2="912" y1="160" y2="240" x1="912" />
        </branch>
        <bustap x2="480" y1="240" y2="160" x1="480" />
        <iomarker fontsize="28" x="272" y="288" name="A(31:0)" orien="R180" />
        <iomarker fontsize="28" x="272" y="448" name="B(31:0)" orien="R180" />
        <iomarker fontsize="28" x="224" y="160" name="sub" orien="R180" />
        <iomarker fontsize="28" x="1136" y="352" name="S(31:0)" orien="R0" />
        <text style="fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" x="360" y="376">{32{sub}}</text>
        <branch name="B(31:0)">
            <wire x2="288" y1="448" y2="448" x1="272" />
            <wire x2="528" y1="448" y2="448" x1="288" />
        </branch>
        <branch name="sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub,sub">
            <wire x2="480" y1="240" y2="256" x1="480" />
            <wire x2="480" y1="256" y2="384" x1="480" />
            <wire x2="528" y1="384" y2="384" x1="480" />
        </branch>
        <instance x="496" y="480" name="MXOR" orien="R0">
        </instance>
        <branch name="XLXN_1(31:0)">
            <wire x2="832" y1="416" y2="416" x1="752" />
        </branch>
        <instance x="784" y="544" name="MADC32" orien="R0">
        </instance>
        <branch name="Co">
            <wire x2="1200" y1="448" y2="448" x1="1024" />
        </branch>
        <iomarker fontsize="28" x="1200" y="448" name="Co" orien="R0" />
    </sheet>
</drawing>