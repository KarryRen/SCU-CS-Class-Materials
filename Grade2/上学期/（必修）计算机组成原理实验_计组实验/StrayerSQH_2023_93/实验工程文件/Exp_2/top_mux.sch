<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1(7:0)" />
        <signal name="XLXN_2(7:0)" />
        <signal name="led(7:0)" />
        <signal name="dout(63:0)" />
        <signal name="dout(15:8)" />
        <signal name="dout(7:0)" />
        <signal name="XLXN_8" />
        <signal name="dout(31:24)" />
        <signal name="dout(23:16)" />
        <signal name="dout(47:40)" />
        <signal name="dout(39:32)" />
        <signal name="dout(63:56)" />
        <signal name="dout(55:48)" />
        <signal name="sw(3:0)" />
        <signal name="sw(2:0)" />
        <signal name="sw(3)" />
        <port polarity="Output" name="led(7:0)" />
        <port polarity="Input" name="sw(3:0)" />
        <blockdef name="mux8t1_8">
            <timestamp>2024-11-21T3:13:5</timestamp>
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
        <blockdef name="rom">
            <timestamp>2024-11-21T3:18:43</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="buf8">
            <timestamp>2024-11-21T3:19:19</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="mux8t1_8" name="XLXI_1">
            <blockpin signalname="sw(2:0)" name="sel(2:0)" />
            <blockpin signalname="dout(15:8)" name="x1(7:0)" />
            <blockpin signalname="dout(7:0)" name="x0(7:0)" />
            <blockpin signalname="dout(31:24)" name="x3(7:0)" />
            <blockpin signalname="dout(23:16)" name="x2(7:0)" />
            <blockpin signalname="dout(47:40)" name="x5(7:0)" />
            <blockpin signalname="dout(39:32)" name="x4(7:0)" />
            <blockpin signalname="dout(63:56)" name="x7(7:0)" />
            <blockpin signalname="dout(55:48)" name="x6(7:0)" />
            <blockpin signalname="XLXN_2(7:0)" name="o(7:0)" />
        </block>
        <block symbolname="rom" name="XLXI_2">
            <blockpin signalname="sw(3)" name="addr" />
            <blockpin signalname="dout(63:0)" name="dout(63:0)" />
        </block>
        <block symbolname="buf8" name="XLXI_3">
            <blockpin signalname="XLXN_2(7:0)" name="din(7:0)" />
            <blockpin signalname="led(7:0)" name="dout(7:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1808" y="1392" name="XLXI_1" orien="R0">
        </instance>
        <instance x="912" y="1152" name="XLXI_2" orien="R0">
        </instance>
        <instance x="2528" y="880" name="XLXI_3" orien="R0">
        </instance>
        <branch name="XLXN_2(7:0)">
            <wire x2="2208" y1="848" y2="848" x1="2192" />
            <wire x2="2512" y1="848" y2="848" x1="2208" />
            <wire x2="2528" y1="848" y2="848" x1="2512" />
        </branch>
        <branch name="led(7:0)">
            <wire x2="3072" y1="848" y2="848" x1="2912" />
        </branch>
        <iomarker fontsize="28" x="3072" y="848" name="led(7:0)" orien="R0" />
        <branch name="dout(63:0)">
            <wire x2="1408" y1="1120" y2="1120" x1="1296" />
            <wire x2="1408" y1="1120" y2="1168" x1="1408" />
            <wire x2="1408" y1="1168" y2="1232" x1="1408" />
            <wire x2="1408" y1="1232" y2="1296" x1="1408" />
            <wire x2="1408" y1="1296" y2="1360" x1="1408" />
            <wire x2="1408" y1="912" y2="976" x1="1408" />
            <wire x2="1408" y1="976" y2="1040" x1="1408" />
            <wire x2="1408" y1="1040" y2="1104" x1="1408" />
            <wire x2="1408" y1="1104" y2="1120" x1="1408" />
        </branch>
        <bustap x2="1504" y1="912" y2="912" x1="1408" />
        <bustap x2="1504" y1="976" y2="976" x1="1408" />
        <bustap x2="1504" y1="1040" y2="1040" x1="1408" />
        <bustap x2="1504" y1="1104" y2="1104" x1="1408" />
        <bustap x2="1504" y1="1168" y2="1168" x1="1408" />
        <bustap x2="1504" y1="1232" y2="1232" x1="1408" />
        <bustap x2="1504" y1="1296" y2="1296" x1="1408" />
        <bustap x2="1504" y1="1360" y2="1360" x1="1408" />
        <branch name="dout(15:8)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1712" y="912" type="branch" />
            <wire x2="1712" y1="912" y2="912" x1="1504" />
            <wire x2="1792" y1="912" y2="912" x1="1712" />
            <wire x2="1808" y1="912" y2="912" x1="1792" />
        </branch>
        <branch name="dout(7:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1728" y="976" type="branch" />
            <wire x2="1728" y1="976" y2="976" x1="1504" />
            <wire x2="1808" y1="976" y2="976" x1="1728" />
        </branch>
        <branch name="dout(31:24)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1712" y="1040" type="branch" />
            <wire x2="1520" y1="1040" y2="1040" x1="1504" />
            <wire x2="1712" y1="1040" y2="1040" x1="1520" />
            <wire x2="1792" y1="1040" y2="1040" x1="1712" />
            <wire x2="1808" y1="1040" y2="1040" x1="1792" />
        </branch>
        <branch name="dout(23:16)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1712" y="1104" type="branch" />
            <wire x2="1712" y1="1104" y2="1104" x1="1504" />
            <wire x2="1808" y1="1104" y2="1104" x1="1712" />
        </branch>
        <branch name="dout(47:40)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1712" y="1168" type="branch" />
            <wire x2="1712" y1="1168" y2="1168" x1="1504" />
            <wire x2="1808" y1="1168" y2="1168" x1="1712" />
        </branch>
        <branch name="dout(39:32)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1712" y="1232" type="branch" />
            <wire x2="1712" y1="1232" y2="1232" x1="1504" />
            <wire x2="1808" y1="1232" y2="1232" x1="1712" />
        </branch>
        <branch name="dout(63:56)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1712" y="1296" type="branch" />
            <wire x2="1712" y1="1296" y2="1296" x1="1504" />
            <wire x2="1808" y1="1296" y2="1296" x1="1712" />
        </branch>
        <branch name="dout(55:48)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1712" y="1360" type="branch" />
            <wire x2="1712" y1="1360" y2="1360" x1="1504" />
            <wire x2="1808" y1="1360" y2="1360" x1="1712" />
        </branch>
        <branch name="sw(3:0)">
            <wire x2="720" y1="928" y2="928" x1="576" />
            <wire x2="720" y1="928" y2="1120" x1="720" />
            <wire x2="720" y1="800" y2="816" x1="720" />
            <wire x2="720" y1="816" y2="928" x1="720" />
        </branch>
        <iomarker fontsize="28" x="576" y="928" name="sw(3:0)" orien="R180" />
        <bustap x2="816" y1="816" y2="816" x1="720" />
        <bustap x2="816" y1="1120" y2="1120" x1="720" />
        <branch name="sw(2:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="992" y="816" type="branch" />
            <wire x2="992" y1="816" y2="816" x1="816" />
            <wire x2="1312" y1="816" y2="816" x1="992" />
            <wire x2="1312" y1="816" y2="848" x1="1312" />
            <wire x2="1808" y1="848" y2="848" x1="1312" />
        </branch>
        <branch name="sw(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="832" y="1120" type="branch" />
            <wire x2="832" y1="1120" y2="1120" x1="816" />
            <wire x2="912" y1="1120" y2="1120" x1="832" />
        </branch>
    </sheet>
</drawing>