<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <attr value="Never" name="RenameBusIO" />
    <netlist>
        <signal name="clk" />
        <signal name="CPU_MIO" />
        <signal name="mem_w" />
        <signal name="INT" />
        <signal name="inst_in(31:0)" />
        <signal name="inst_in(31:26)" />
        <signal name="inst_in(5:0)" />
        <signal name="reset" />
        <signal name="MIO_ready" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="XLXN_7(2:0)" />
        <signal name="XLXN_8" />
        <signal name="Data_in(31:0)" />
        <signal name="inst_in(25:0)" />
        <signal name="PC_out(31:0)" />
        <signal name="Addr_out(31:0)" />
        <signal name="Data_out(31:0)" />
        <port polarity="Input" name="clk" />
        <port polarity="Output" name="CPU_MIO" />
        <port polarity="Output" name="mem_w" />
        <port polarity="Input" name="INT" />
        <port polarity="Input" name="inst_in(31:0)" />
        <port polarity="Input" name="reset" />
        <port polarity="Input" name="MIO_ready" />
        <port polarity="Input" name="Data_in(31:0)" />
        <port polarity="Output" name="PC_out(31:0)" />
        <port polarity="Output" name="Addr_out(31:0)" />
        <port polarity="Output" name="Data_out(31:0)" />
        <blockdef name="SCtrl">
            <timestamp>2017-4-26T7:1:17</timestamp>
            <rect style="linewidth:W;linecolor:rgb(255,0,0);fillcolor:rgb(255,170,255);fillstyle:Solid" width="336" x="64" y="-576" height="576" />
            <line x2="464" y1="-544" y2="-544" x1="400" />
            <line x2="464" y1="-480" y2="-480" x1="400" />
            <line x2="464" y1="-416" y2="-416" x1="400" />
            <line x2="464" y1="-352" y2="-352" x1="400" />
            <line x2="464" y1="-288" y2="-288" x1="400" />
            <line x2="464" y1="-224" y2="-224" x1="400" />
            <line x2="464" y1="-160" y2="-160" style="linewidth:W" x1="400" />
            <line x2="464" y1="-32" y2="-32" x1="400" />
            <line x2="464" y1="-96" y2="-96" x1="400" />
            <line x2="0" y1="-352" y2="-352" style="linewidth:W" x1="64" />
            <line x2="0" y1="-64" y2="-64" x1="64" />
            <line x2="0" y1="-432" y2="-432" style="linewidth:W" x1="64" />
        </blockdef>
        <blockdef name="SDPath">
            <timestamp>2024-12-12T1:10:24</timestamp>
            <rect style="linewidth:W;linecolor:rgb(0,0,255);fillcolor:rgb(170,255,255);fillstyle:Solid" width="352" x="64" y="-888" height="792" />
            <line x2="0" y1="-544" y2="-544" x1="64" />
            <line x2="0" y1="-480" y2="-480" x1="64" />
            <line x2="0" y1="-416" y2="-416" x1="64" />
            <line x2="0" y1="-352" y2="-352" x1="64" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-700" height="24" />
            <line x2="0" y1="-688" y2="-688" x1="64" />
            <rect width="64" x="0" y="-636" height="24" />
            <line x2="0" y1="-624" y2="-624" x1="64" />
            <line x2="0" y1="-800" y2="-800" x1="64" />
            <line x2="0" y1="-736" y2="-736" x1="64" />
            <rect width="64" x="416" y="-700" height="24" />
            <line x2="480" y1="-688" y2="-688" x1="416" />
            <rect width="64" x="416" y="-540" height="24" />
            <line x2="480" y1="-528" y2="-528" x1="416" />
            <rect width="64" x="416" y="-412" height="24" />
            <line x2="480" y1="-400" y2="-400" x1="416" />
        </blockdef>
        <block symbolname="SCtrl" name="Controller">
            <blockpin signalname="XLXN_2" name="RegDst" />
            <blockpin signalname="XLXN_3" name="ALUSrc_B" />
            <blockpin signalname="XLXN_4" name="MemtoReg" />
            <blockpin signalname="XLXN_5" name="Jump" />
            <blockpin signalname="XLXN_6" name="Branch" />
            <blockpin signalname="XLXN_8" name="RegWrite" />
            <blockpin signalname="XLXN_7(2:0)" name="ALU_Control(2:0)" />
            <blockpin signalname="CPU_MIO" name="CPU_MIO" />
            <blockpin signalname="mem_w" name="mem_w" />
            <blockpin signalname="inst_in(5:0)" name="Fun(5:0)" />
            <blockpin signalname="MIO_ready" name="MIO_ready" />
            <blockpin signalname="inst_in(31:26)" name="OPcode(5:0)" />
        </block>
        <block symbolname="SDPath" name="XLXI_1">
            <blockpin signalname="XLXN_2" name="RegDst" />
            <blockpin signalname="Data_in(31:0)" name="Data_in(31:0)" />
            <blockpin signalname="XLXN_3" name="ALUSrc_B" />
            <blockpin signalname="XLXN_6" name="Branch" />
            <blockpin signalname="XLXN_8" name="RegWrite" />
            <blockpin signalname="XLXN_4" name="MemtoReg" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="reset" name="rst" />
            <blockpin signalname="XLXN_7(2:0)" name="ALU_Control(2:0)" />
            <blockpin signalname="inst_in(25:0)" name="inst_field(25:0)" />
            <blockpin signalname="XLXN_5" name="Jump" />
            <blockpin signalname="Data_out(31:0)" name="Data_out(31:0)" />
            <blockpin signalname="PC_out(31:0)" name="PC_out(31:0)" />
            <blockpin signalname="Addr_out(31:0)" name="ALU_out(31:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="1760" height="1360">
        <branch name="CPU_MIO">
            <wire x2="832" y1="1024" y2="1024" x1="816" />
            <wire x2="832" y1="1024" y2="1248" x1="832" />
            <wire x2="1488" y1="1248" y2="1248" x1="832" />
            <wire x2="1504" y1="1248" y2="1248" x1="1488" />
        </branch>
        <branch name="mem_w">
            <wire x2="864" y1="960" y2="960" x1="816" />
            <wire x2="864" y1="960" y2="1088" x1="864" />
            <wire x2="1520" y1="1088" y2="1088" x1="864" />
            <wire x2="1536" y1="1088" y2="1088" x1="1520" />
        </branch>
        <iomarker fontsize="38" x="1504" y="1248" name="CPU_MIO" orien="R0" />
        <iomarker fontsize="38" x="1536" y="1088" name="mem_w" orien="R0" />
        <branch name="inst_in(31:0)">
            <wire x2="240" y1="432" y2="432" x1="208" />
            <wire x2="240" y1="432" y2="624" x1="240" />
            <wire x2="240" y1="624" y2="704" x1="240" />
            <wire x2="320" y1="432" y2="432" x1="240" />
        </branch>
        <bustap x2="336" y1="624" y2="624" x1="240" />
        <bustap x2="336" y1="704" y2="704" x1="240" />
        <text style="fontsize:28;fontname:Arial" x="264" y="676">inst_in(5:0)</text>
        <text style="fontsize:26;fontname:Arial" x="252" y="596">inst_in(31:26)</text>
        <branch name="inst_in(5:0)">
            <wire x2="352" y1="704" y2="704" x1="336" />
        </branch>
        <iomarker fontsize="38" x="144" y="1200" name="INT" orien="R180" />
        <branch name="INT">
            <wire x2="352" y1="1200" y2="1200" x1="144" />
        </branch>
        <branch name="reset">
            <wire x2="880" y1="320" y2="320" x1="112" />
            <wire x2="1008" y1="320" y2="320" x1="880" />
        </branch>
        <iomarker fontsize="38" x="256" y="992" name="MIO_ready" orien="R180" />
        <branch name="XLXN_2">
            <wire x2="864" y1="512" y2="512" x1="816" />
            <wire x2="880" y1="512" y2="512" x1="864" />
            <wire x2="1008" y1="512" y2="512" x1="880" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="864" y1="576" y2="576" x1="816" />
            <wire x2="880" y1="576" y2="576" x1="864" />
            <wire x2="896" y1="576" y2="576" x1="880" />
            <wire x2="1008" y1="576" y2="576" x1="896" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="864" y1="640" y2="640" x1="816" />
            <wire x2="880" y1="640" y2="640" x1="864" />
            <wire x2="1008" y1="640" y2="640" x1="880" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="864" y1="704" y2="704" x1="816" />
            <wire x2="880" y1="704" y2="704" x1="864" />
            <wire x2="1008" y1="704" y2="704" x1="880" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="864" y1="768" y2="768" x1="816" />
            <wire x2="880" y1="768" y2="768" x1="864" />
            <wire x2="1008" y1="768" y2="768" x1="880" />
        </branch>
        <branch name="XLXN_7(2:0)">
            <wire x2="864" y1="896" y2="896" x1="816" />
            <wire x2="880" y1="896" y2="896" x1="864" />
            <wire x2="1008" y1="896" y2="896" x1="880" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="864" y1="832" y2="832" x1="816" />
            <wire x2="880" y1="832" y2="832" x1="864" />
            <wire x2="1008" y1="832" y2="832" x1="880" />
        </branch>
        <iomarker fontsize="28" x="112" y="320" name="reset" orien="R180" />
        <branch name="clk">
            <wire x2="864" y1="256" y2="256" x1="96" />
            <wire x2="880" y1="256" y2="256" x1="864" />
            <wire x2="1008" y1="256" y2="256" x1="880" />
        </branch>
        <branch name="Data_in(31:0)">
            <wire x2="880" y1="368" y2="368" x1="224" />
            <wire x2="1008" y1="368" y2="368" x1="880" />
        </branch>
        <iomarker fontsize="28" x="224" y="368" name="Data_in(31:0)" orien="R180" />
        <bustap x2="416" y1="432" y2="432" x1="320" />
        <iomarker fontsize="28" x="208" y="432" name="inst_in(31:0)" orien="R180" />
        <branch name="inst_in(25:0)">
            <wire x2="880" y1="432" y2="432" x1="416" />
            <wire x2="1008" y1="432" y2="432" x1="880" />
        </branch>
        <text style="fontsize:28;fontname:Arial" x="376" y="408">inst_in(25:0)</text>
        <iomarker fontsize="28" x="96" y="256" name="clk" orien="R180" />
        <branch name="MIO_ready">
            <wire x2="272" y1="992" y2="992" x1="256" />
            <wire x2="352" y1="992" y2="992" x1="272" />
        </branch>
        <branch name="inst_in(31:26)">
            <wire x2="352" y1="624" y2="624" x1="336" />
        </branch>
        <instance x="352" y="1056" name="Controller" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" attrname="InstName" x="80" y="-512" type="instance" />
        </instance>
        <instance x="1008" y="1056" name="XLXI_1" orien="R0">
        </instance>
        <branch name="PC_out(31:0)">
            <wire x2="1552" y1="368" y2="368" x1="1488" />
        </branch>
        <branch name="Addr_out(31:0)">
            <wire x2="1568" y1="528" y2="528" x1="1488" />
        </branch>
        <branch name="Data_out(31:0)">
            <wire x2="1568" y1="656" y2="656" x1="1488" />
        </branch>
        <iomarker fontsize="28" x="1552" y="368" name="PC_out(31:0)" orien="R0" />
        <iomarker fontsize="28" x="1568" y="528" name="Addr_out(31:0)" orien="R0" />
        <iomarker fontsize="28" x="1568" y="656" name="Data_out(31:0)" orien="R0" />
    </sheet>
</drawing>