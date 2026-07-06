<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="A(31:0)" />
        <signal name="XLXN_12(31:0)" />
        <signal name="XLXN_11(31:0)" />
        <signal name="XLXN_22(31:0)" />
        <signal name="XLXN_23(31:0)" />
        <signal name="res(31:0)" />
        <signal name="N0" />
        <signal name="XLXN_47(31:0)" />
        <signal name="N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,S(31)" />
        <signal name="B(31:0)" />
        <signal name="ALU_Ctr(2:0)" />
        <signal name="ALU_Ctr(2)" />
        <signal name="S(31:0)" />
        <signal name="zero" />
        <signal name="overflow" />
        <signal name="Co" />
        <port polarity="Input" name="A(31:0)" />
        <port polarity="Output" name="res(31:0)" />
        <port polarity="Input" name="B(31:0)" />
        <port polarity="Input" name="ALU_Ctr(2:0)" />
        <port polarity="Output" name="zero" />
        <port polarity="Output" name="overflow" />
        <port polarity="Output" name="Co" />
        <blockdef name="and32">
            <timestamp>2014-3-19T13:28:2</timestamp>
            <line x2="32" y1="-96" y2="-96" style="linewidth:W" x1="64" />
            <line x2="28" y1="-32" y2="-32" style="linewidth:W" x1="64" />
            <line x2="64" y1="-16" y2="-16" x1="144" />
            <line x2="64" y1="-16" y2="-112" x1="64" />
            <line x2="144" y1="-112" y2="-112" x1="64" />
            <arc ex="144" ey="-112" sx="144" sy="-16" r="48" cx="144" cy="-64" />
            <line x2="224" y1="-64" y2="-64" style="linewidth:W" x1="192" />
        </blockdef>
        <blockdef name="or32">
            <timestamp>2014-3-19T13:34:25</timestamp>
            <line x2="64" y1="-16" y2="-16" x1="128" />
            <arc ex="208" ey="-64" sx="128" sy="-16" r="88" cx="132" cy="-104" />
            <arc ex="128" ey="-112" sx="208" sy="-64" r="88" cx="132" cy="-24" />
            <line x2="236" y1="-64" y2="-64" style="linewidth:W" x1="208" />
            <line x2="64" y1="-112" y2="-112" x1="128" />
            <line x2="48" y1="-96" y2="-96" style="linewidth:W" x1="80" />
            <arc ex="64" ey="-112" sx="64" sy="-16" r="56" cx="32" cy="-64" />
            <line x2="48" y1="-32" y2="-32" style="linewidth:W" x1="80" />
        </blockdef>
        <blockdef name="nor32">
            <timestamp>2014-3-19T13:43:42</timestamp>
            <line x2="64" y1="-112" y2="-112" x1="128" />
            <arc ex="64" ey="-112" sx="64" sy="-16" r="56" cx="32" cy="-64" />
            <line x2="64" y1="-16" y2="-16" x1="128" />
            <arc ex="208" ey="-64" sx="128" sy="-16" r="88" cx="132" cy="-104" />
            <arc ex="128" ey="-112" sx="208" sy="-64" r="88" cx="132" cy="-24" />
            <line x2="224" y1="-64" y2="-64" style="linewidth:W" x1="256" />
            <circle style="linewidth:W" r="8" cx="216" cy="-64" />
            <line x2="48" y1="-96" y2="-96" style="linewidth:W" x1="80" />
            <line x2="48" y1="-32" y2="-32" style="linewidth:W" x1="80" />
        </blockdef>
        <blockdef name="srl32">
            <timestamp>2014-3-19T13:48:11</timestamp>
            <rect width="184" x="64" y="-128" height="128" />
            <line x2="32" y1="-96" y2="-96" style="linewidth:W" x1="64" />
            <line x2="32" y1="-32" y2="-32" style="linewidth:W" x1="64" />
            <line x2="288" y1="-64" y2="-64" style="linewidth:W" x1="248" />
        </blockdef>
        <blockdef name="xor32">
            <timestamp>2014-3-19T14:3:59</timestamp>
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
        <blockdef name="gnd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-96" x1="64" />
            <line x2="52" y1="-48" y2="-48" x1="76" />
            <line x2="60" y1="-32" y2="-32" x1="68" />
            <line x2="40" y1="-64" y2="-64" x1="88" />
            <line x2="64" y1="-64" y2="-80" x1="64" />
            <line x2="64" y1="-128" y2="-96" x1="64" />
        </blockdef>
        <blockdef name="or_bit_32">
            <timestamp>2014-3-19T14:52:25</timestamp>
            <rect width="220" x="64" y="-104" height="112" />
            <line x2="32" y1="-48" y2="-48" style="linewidth:W" x1="64" />
            <arc ex="260" ey="-48" sx="180" sy="0" r="88" cx="184" cy="-88" />
            <line x2="116" y1="0" y2="0" x1="180" />
            <line x2="116" y1="-96" y2="-96" x1="180" />
            <arc ex="116" ey="-96" sx="116" sy="0" r="56" cx="84" cy="-48" />
            <arc ex="180" ey="-96" sx="260" sy="-48" r="88" cx="184" cy="-8" />
            <line x2="120" y1="-96" y2="-96" x1="184" />
            <line x2="88" y1="-80" y2="-80" x1="128" />
            <line x2="92" y1="-16" y2="-16" x1="132" />
            <line x2="304" y1="-48" y2="-48" x1="284" />
        </blockdef>
        <blockdef name="MUX8T1_32">
            <timestamp>2015-12-29T14:54:8</timestamp>
            <rect width="68" x="12" y="-264" height="264" />
            <line x2="48" y1="-264" y2="-272" style="linewidth:W" x1="48" />
            <line x2="0" y1="-16" y2="-16" style="linewidth:W" x1="12" />
            <line x2="0" y1="-48" y2="-48" style="linewidth:W" x1="12" />
            <line x2="0" y1="-80" y2="-80" style="linewidth:W" x1="12" />
            <line x2="0" y1="-112" y2="-112" style="linewidth:W" x1="12" />
            <line x2="0" y1="-144" y2="-144" style="linewidth:W" x1="12" />
            <line x2="0" y1="-176" y2="-176" style="linewidth:W" x1="12" />
            <line x2="0" y1="-208" y2="-208" style="linewidth:W" x1="12" />
            <line x2="0" y1="-240" y2="-240" style="linewidth:W" x1="12" />
            <line x2="96" y1="-160" y2="-160" style="linewidth:W" x1="80" />
        </blockdef>
        <blockdef name="ABC32">
            <timestamp>2017-4-13T13:5:18</timestamp>
            <line x2="0" y1="-176" y2="-176" style="linewidth:W" x1="16" />
            <line x2="0" y1="-48" y2="-48" style="linewidth:W" x1="16" />
            <line x2="16" y1="-144" y2="-220" x1="16" />
            <line x2="64" y1="-144" y2="-112" x1="16" />
            <line x2="64" y1="-80" y2="-112" x1="16" />
            <line x2="16" y1="-80" y2="4" x1="16" />
            <line x2="176" y1="4" y2="-60" x1="16" />
            <line x2="176" y1="-220" y2="-156" x1="16" />
            <line x2="176" y1="-60" y2="-156" x1="176" />
            <line x2="192" y1="-112" y2="-112" style="linewidth:W" x1="176" />
            <line x2="80" y1="-224" y2="-196" x1="80" />
            <line x2="108" y1="-32" y2="0" x1="108" />
            <line x2="192" y1="0" y2="0" x1="108" />
        </blockdef>
        <block symbolname="nor32" name="ALU_U4">
            <blockpin signalname="XLXN_11(31:0)" name="res(31:0)" />
            <blockpin signalname="A(31:0)" name="A(31:0)" />
            <blockpin signalname="B(31:0)" name="B(31:0)" />
        </block>
        <block symbolname="or32" name="ALU_U2">
            <blockpin signalname="XLXN_23(31:0)" name="res(31:0)" />
            <blockpin signalname="A(31:0)" name="A(31:0)" />
            <blockpin signalname="B(31:0)" name="B(31:0)" />
        </block>
        <block symbolname="and32" name="ALU_U1">
            <blockpin signalname="XLXN_22(31:0)" name="res(31:0)" />
            <blockpin signalname="A(31:0)" name="A(31:0)" />
            <blockpin signalname="B(31:0)" name="B(31:0)" />
        </block>
        <block symbolname="xor32" name="ALU_U3">
            <blockpin signalname="A(31:0)" name="A(31:0)" />
            <blockpin signalname="B(31:0)" name="B(31:0)" />
            <blockpin signalname="XLXN_12(31:0)" name="res(31:0)" />
        </block>
        <block symbolname="gnd" name="XLXI_13">
            <blockpin signalname="N0" name="G" />
        </block>
        <block symbolname="srl32" name="ALU_U5">
            <blockpin signalname="A(31:0)" name="A(31:0)" />
            <blockpin signalname="B(31:0)" name="B(31:0)" />
            <blockpin signalname="XLXN_47(31:0)" name="res(31:0)" />
        </block>
        <block symbolname="or_bit_32" name="ALU_Zero">
            <blockpin signalname="zero" name="o" />
            <blockpin signalname="res(31:0)" name="A(31:0)" />
        </block>
        <block symbolname="MUX8T1_32" name="MUX3281">
            <blockpin signalname="ALU_Ctr(2:0)" name="s(2:0)" />
            <blockpin signalname="N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,S(31)" name="I7(31:0)" />
            <blockpin signalname="S(31:0)" name="I6(31:0)" />
            <blockpin signalname="XLXN_47(31:0)" name="I5(31:0)" />
            <blockpin signalname="XLXN_11(31:0)" name="I4(31:0)" />
            <blockpin signalname="XLXN_12(31:0)" name="I3(31:0)" />
            <blockpin signalname="S(31:0)" name="I2(31:0)" />
            <blockpin signalname="XLXN_23(31:0)" name="I1(31:0)" />
            <blockpin signalname="XLXN_22(31:0)" name="I0(31:0)" />
            <blockpin signalname="res(31:0)" name="o(31:0)" />
        </block>
        <block symbolname="ABC32" name="M0">
            <blockpin signalname="B(31:0)" name="B(31:0)" />
            <blockpin signalname="A(31:0)" name="A(31:0)" />
            <blockpin signalname="ALU_Ctr(2)" name="sub" />
            <blockpin signalname="S(31:0)" name="S(31:0)" />
            <blockpin signalname="Co" name="Co" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="1760" height="1360">
        <branch name="XLXN_11(31:0)">
            <wire x2="992" y1="784" y2="784" x1="800" />
            <wire x2="992" y1="416" y2="784" x1="992" />
            <wire x2="1248" y1="416" y2="416" x1="992" />
        </branch>
        <branch name="XLXN_22(31:0)">
            <wire x2="1024" y1="128" y2="128" x1="784" />
            <wire x2="1024" y1="128" y2="288" x1="1024" />
            <wire x2="1248" y1="288" y2="288" x1="1024" />
        </branch>
        <branch name="XLXN_23(31:0)">
            <wire x2="800" y1="240" y2="240" x1="784" />
            <wire x2="800" y1="240" y2="320" x1="800" />
            <wire x2="1248" y1="320" y2="320" x1="800" />
        </branch>
        <branch name="res(31:0)">
            <wire x2="1328" y1="736" y2="864" x1="1328" />
            <wire x2="1344" y1="864" y2="864" x1="1328" />
            <wire x2="1424" y1="736" y2="736" x1="1328" />
            <wire x2="1424" y1="368" y2="368" x1="1344" />
            <wire x2="1424" y1="368" y2="736" x1="1424" />
            <wire x2="1600" y1="368" y2="368" x1="1424" />
        </branch>
        <bustap x2="1184" y1="672" y2="672" x1="1088" />
        <branch name="XLXN_12(31:0)">
            <wire x2="960" y1="672" y2="672" x1="800" />
            <wire x2="960" y1="384" y2="672" x1="960" />
            <wire x2="1248" y1="384" y2="384" x1="960" />
        </branch>
        <instance x="544" y="736" name="ALU_U3" orien="R0">
        </instance>
        <instance x="544" y="848" name="ALU_U4" orien="R0">
        </instance>
        <instance x="512" y="1008" name="ALU_U5" orien="R0">
        </instance>
        <branch name="XLXN_47(31:0)">
            <wire x2="1024" y1="944" y2="944" x1="800" />
            <wire x2="1024" y1="448" y2="944" x1="1024" />
            <wire x2="1248" y1="448" y2="448" x1="1024" />
        </branch>
        <branch name="N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,S(31)">
            <wire x2="1248" y1="512" y2="512" x1="1088" />
            <wire x2="1088" y1="512" y2="672" x1="1088" />
        </branch>
        <instance x="560" y="192" name="ALU_U1" orien="R0">
        </instance>
        <instance x="544" y="304" name="ALU_U2" orien="R0">
        </instance>
        <branch name="A(31:0)">
            <wire x2="528" y1="416" y2="416" x1="176" />
            <wire x2="528" y1="416" y2="640" x1="528" />
            <wire x2="528" y1="640" y2="752" x1="528" />
            <wire x2="528" y1="752" y2="912" x1="528" />
            <wire x2="544" y1="912" y2="912" x1="528" />
            <wire x2="592" y1="752" y2="752" x1="528" />
            <wire x2="576" y1="640" y2="640" x1="528" />
            <wire x2="592" y1="416" y2="416" x1="528" />
            <wire x2="592" y1="96" y2="96" x1="528" />
            <wire x2="528" y1="96" y2="208" x1="528" />
            <wire x2="592" y1="208" y2="208" x1="528" />
            <wire x2="528" y1="208" y2="416" x1="528" />
        </branch>
        <branch name="ALU_Ctr(2:0)">
            <wire x2="352" y1="48" y2="48" x1="240" />
            <wire x2="1296" y1="48" y2="48" x1="352" />
            <wire x2="1296" y1="48" y2="256" x1="1296" />
            <wire x2="352" y1="48" y2="192" x1="352" />
        </branch>
        <branch name="ALU_Ctr(2)">
            <wire x2="352" y1="304" y2="336" x1="352" />
            <wire x2="672" y1="336" y2="336" x1="352" />
            <wire x2="672" y1="336" y2="368" x1="672" />
        </branch>
        <branch name="N0">
            <wire x2="1248" y1="672" y2="672" x1="1184" />
            <wire x2="1248" y1="672" y2="784" x1="1248" />
        </branch>
        <instance x="1184" y="912" name="XLXI_13" orien="R0" />
        <branch name="S(31:0)">
            <wire x2="928" y1="480" y2="480" x1="784" />
            <wire x2="1248" y1="480" y2="480" x1="928" />
            <wire x2="1248" y1="352" y2="352" x1="928" />
            <wire x2="928" y1="352" y2="480" x1="928" />
        </branch>
        <branch name="zero">
            <wire x2="1648" y1="864" y2="864" x1="1616" />
        </branch>
        <instance x="1312" y="912" name="ALU_Zero" orien="R0">
        </instance>
        <iomarker fontsize="28" x="1648" y="864" name="zero" orien="R0" />
        <iomarker fontsize="28" x="1600" y="368" name="res(31:0)" orien="R0" />
        <branch name="overflow">
            <wire x2="1584" y1="992" y2="992" x1="1440" />
        </branch>
        <iomarker fontsize="28" x="1584" y="992" name="overflow" orien="R0" />
        <iomarker fontsize="28" x="240" y="48" name="ALU_Ctr(2:0)" orien="R180" />
        <instance x="1248" y="528" name="MUX3281" orien="R0">
        </instance>
        <branch name="Co">
            <wire x2="1632" y1="592" y2="592" x1="784" />
        </branch>
        <iomarker fontsize="28" x="1632" y="592" name="Co" orien="R0" />
        <instance x="592" y="592" name="M0" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="80" y="-140" type="instance" />
        </instance>
        <branch name="B(31:0)">
            <wire x2="448" y1="544" y2="544" x1="176" />
            <wire x2="448" y1="544" y2="704" x1="448" />
            <wire x2="576" y1="704" y2="704" x1="448" />
            <wire x2="448" y1="704" y2="816" x1="448" />
            <wire x2="592" y1="816" y2="816" x1="448" />
            <wire x2="448" y1="816" y2="976" x1="448" />
            <wire x2="544" y1="976" y2="976" x1="448" />
            <wire x2="592" y1="544" y2="544" x1="448" />
            <wire x2="592" y1="160" y2="160" x1="448" />
            <wire x2="448" y1="160" y2="272" x1="448" />
            <wire x2="592" y1="272" y2="272" x1="448" />
            <wire x2="448" y1="272" y2="544" x1="448" />
        </branch>
        <iomarker fontsize="28" x="176" y="416" name="A(31:0)" orien="R180" />
        <bustap x2="352" y1="192" y2="304" x1="352" />
        <iomarker fontsize="28" x="176" y="544" name="B(31:0)" orien="R180" />
        <text style="fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" x="112" y="1132">SLT = N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,S(31)</text>
        <circle style="linecolor:rgb(255,0,0);linestyle:Dot" r="54" cx="1636" cy="1128" />
        <text style="fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" x="1124" y="560">SLT</text>
    </sheet>
</drawing>