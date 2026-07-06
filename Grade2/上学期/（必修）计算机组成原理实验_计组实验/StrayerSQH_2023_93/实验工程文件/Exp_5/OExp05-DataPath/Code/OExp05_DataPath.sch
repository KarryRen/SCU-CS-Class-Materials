<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="Disp_num(31:0)" />
        <signal name="LE_out(7:0)" />
        <signal name="point_out(7:0)" />
        <signal name="V5" />
        <signal name="Div(25)" />
        <signal name="rst" />
        <signal name="clk_100mhz" />
        <signal name="SW_OK(0)" />
        <signal name="SEGMENT(7:0)" />
        <signal name="AN(3:0)" />
        <signal name="SW_OK(7:5)" />
        <signal name="SW_OK(1),Div(19:18)" />
        <signal name="N0" />
        <signal name="Bi(31:0)" />
        <signal name="readn" />
        <signal name="RDY" />
        <signal name="SW(15:0)">
            <attr value="K13,K14,J13,J14,H13,H14,G12,F12" name="LOC">
                <trait verilog="all:0 wsynth:1" />
                <trait vhdl="all:0 wa:1 wd:1" />
            </attr>
        </signal>
        <signal name="K_ROW(4:0)" />
        <signal name="K_COL(3:0)" />
        <signal name="RSTN" />
        <signal name="SW_OK(7:5),SW_OK(15),SW_OK(0)" />
        <signal name="BTN_OK(3:0)" />
        <signal name="BTN_OK(2:0)" />
        <signal name="XLXN_444(4:0)" />
        <signal name="CR" />
        <signal name="Ai(31:0)" />
        <signal name="SW_OK(15:0)" />
        <signal name="Div(31:0)" />
        <signal name="Clk_CPU" />
        <signal name="Div(20)" />
        <signal name="Pulse(3:0)" />
        <signal name="LED(7:0)" />
        <signal name="CPU2IO(31:0)" />
        <signal name="PC(31:0)" />
        <signal name="Data_in(31:0)" />
        <signal name="Data_out(31:0)" />
        <signal name="Addr_out(31:0)" />
        <signal name="inst(31:0)" />
        <signal name="N0,N0,PC(31:2)" />
        <signal name="Counter_out(31:0)" />
        <signal name="N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0" />
        <signal name="Div(31:0),Div(31:0)" />
        <signal name="XLXN_219(1:0)" />
        <signal name="Div(4)" />
        <signal name="Div(9)" />
        <signal name="Div(11)" />
        <signal name="XLXN_154" />
        <signal name="XLXN_153" />
        <signal name="XLXN_541" />
        <signal name="GPIOF0" />
        <signal name="XLXN_544" />
        <signal name="XLXN_557(0:0)" />
        <signal name="XLXN_558(9:0)" />
        <signal name="XLXN_559(31:0)" />
        <signal name="XLXN_560" />
        <signal name="LED_out(15:0)" />
        <signal name="IO_clk" />
        <signal name="XLXN_579" />
        <signal name="PC(11:2)" />
        <signal name="blink(7:0)" />
        <signal name="LEDCLK" />
        <signal name="LEDDT" />
        <signal name="LEDEN" />
        <signal name="SEGCLK" />
        <signal name="SEGDT" />
        <signal name="SEGEN" />
        <signal name="XLXN_556(31:0)" />
        <signal name="SW_OK(2)" />
        <signal name="clk200P" />
        <signal name="clk200N" />
        <port polarity="Output" name="SEGMENT(7:0)" />
        <port polarity="Output" name="AN(3:0)" />
        <port polarity="Output" name="readn" />
        <port polarity="Output" name="RDY" />
        <port polarity="Input" name="SW(15:0)" />
        <port polarity="Output" name="K_ROW(4:0)" />
        <port polarity="Input" name="K_COL(3:0)" />
        <port polarity="Input" name="RSTN" />
        <port polarity="Output" name="CR" />
        <port polarity="Output" name="LED(7:0)" />
        <port polarity="Output" name="LEDCLK" />
        <port polarity="Output" name="LEDDT" />
        <port polarity="Output" name="LEDEN" />
        <port polarity="Output" name="SEGCLK" />
        <port polarity="Output" name="SEGDT" />
        <port polarity="Output" name="SEGEN" />
        <port polarity="Input" name="clk200P" />
        <port polarity="Input" name="clk200N" />
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
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
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="ROM_D">
            <timestamp>2016-1-3T10:17:26</timestamp>
            <rect style="fillcolor:rgb(255,170,255);fillstyle:Solid" width="380" x="32" y="84" height="244" />
            <line x2="32" y1="208" y2="208" style="linewidth:W" x1="0" />
            <line x2="416" y1="208" y2="208" style="linewidth:W" x1="448" />
        </blockdef>
        <blockdef name="RAM_B">
            <timestamp>2017-3-8T7:8:24</timestamp>
            <rect style="fillcolor:rgb(255,170,255);fillstyle:Solid" width="380" x="32" y="32" height="280" />
            <line x2="32" y1="80" y2="80" style="linewidth:W" x1="0" />
            <line x2="32" y1="272" y2="272" x1="0" />
            <line x2="32" y1="144" y2="144" style="linewidth:W" x1="0" />
            <line x2="32" y1="224" y2="224" style="linewidth:W" x1="0" />
            <line x2="416" y1="144" y2="144" style="linewidth:W" x1="448" />
        </blockdef>
        <blockdef name="MIO_BUS">
            <timestamp>2016-1-3T10:23:30</timestamp>
            <rect style="fillcolor:rgb(255,255,127);fillstyle:Solid" width="432" x="64" y="-832" height="832" />
            <line x2="32" y1="-800" y2="-800" x1="64" />
            <line x2="32" y1="-736" y2="-736" x1="64" />
            <line x2="32" y1="-544" y2="-544" x1="64" />
            <line x2="32" y1="-480" y2="-480" style="linewidth:W" x1="64" />
            <line x2="32" y1="-416" y2="-416" style="linewidth:W" x1="64" />
            <line x2="32" y1="-352" y2="-352" style="linewidth:W" x1="64" />
            <line x2="32" y1="-64" y2="-64" style="linewidth:W" x1="64" />
            <line x2="32" y1="-112" y2="-112" style="linewidth:W" x1="64" />
            <line x2="32" y1="-160" y2="-160" x1="64" />
            <line x2="32" y1="-208" y2="-208" style="linewidth:W" x1="64" />
            <line x2="528" y1="-192" y2="-192" style="linewidth:W" x1="496" />
            <line x2="496" y1="-160" y2="-160" x1="528" />
            <line x2="496" y1="-128" y2="-128" x1="528" />
            <line x2="496" y1="-96" y2="-96" x1="528" />
            <line x2="528" y1="-64" y2="-64" x1="496" />
            <line x2="32" y1="-672" y2="-672" style="linewidth:W" x1="64" />
            <line x2="32" y1="-624" y2="-624" style="linewidth:W" x1="64" />
            <line x2="528" y1="-368" y2="-368" style="linewidth:W" x1="496" />
            <line x2="528" y1="-768" y2="-768" style="linewidth:W" x1="496" />
            <line x2="528" y1="-720" y2="-720" x1="496" />
            <line x2="528" y1="-672" y2="-672" x1="496" />
        </blockdef>
        <blockdef name="Multi_8CH32">
            <timestamp>2015-11-8T11:47:48</timestamp>
            <line x2="0" y1="-528" y2="-528" style="linewidth:W" x1="32" />
            <line x2="0" y1="-464" y2="-464" style="linewidth:W" x1="32" />
            <line x2="0" y1="-672" y2="-672" x1="32" />
            <line x2="0" y1="-624" y2="-624" x1="32" />
            <line x2="0" y1="-576" y2="-576" x1="32" />
            <line x2="0" y1="-416" y2="-416" style="linewidth:W" x1="32" />
            <line x2="0" y1="-368" y2="-368" style="linewidth:W" x1="32" />
            <line x2="0" y1="-320" y2="-320" style="linewidth:W" x1="32" />
            <line x2="0" y1="-272" y2="-272" style="linewidth:W" x1="32" />
            <line x2="0" y1="-224" y2="-224" style="linewidth:W" x1="32" />
            <line x2="0" y1="-176" y2="-176" style="linewidth:W" x1="32" />
            <line x2="0" y1="-128" y2="-128" style="linewidth:W" x1="32" />
            <line x2="0" y1="-80" y2="-80" style="linewidth:W" x1="32" />
            <line x2="0" y1="-32" y2="-32" style="linewidth:W" x1="32" />
            <line x2="352" y1="-576" y2="-576" style="linewidth:W" x1="384" />
            <line x2="352" y1="-528" y2="-528" style="linewidth:W" x1="384" />
            <line x2="352" y1="-624" y2="-624" style="linewidth:W" x1="384" />
            <rect style="fillcolor:rgb(179,164,255);fillstyle:Solid" width="320" x="32" y="-696" height="696" />
        </blockdef>
        <blockdef name="Display">
            <timestamp>2018-3-9T12:10:21</timestamp>
            <line x2="0" y1="-48" y2="-48" style="linewidth:W" x1="32" />
            <line x2="368" y1="-160" y2="-160" x1="384" />
            <line x2="368" y1="-224" y2="-224" x1="384" />
            <line x2="368" y1="-96" y2="-96" x1="384" />
            <line x2="0" y1="-80" y2="-80" style="linewidth:W" x1="32" />
            <line x2="0" y1="-112" y2="-112" style="linewidth:W" x1="32" />
            <rect style="linecolor:rgb(0,0,0);fillcolor:rgb(174,185,255);fillstyle:Solid" width="336" x="32" y="-372" height="360" />
            <line x2="0" y1="-224" y2="-224" x1="32" />
            <line x2="0" y1="-160" y2="-160" x1="32" />
            <line x2="368" y1="-288" y2="-288" x1="384" />
            <line x2="0" y1="-336" y2="-336" x1="32" />
            <line x2="0" y1="-304" y2="-304" x1="32" />
            <line x2="0" y1="-272" y2="-272" x1="32" />
        </blockdef>
        <blockdef name="GPIO">
            <timestamp>2017-3-2T9:6:46</timestamp>
            <line x2="32" y1="-224" y2="-224" x1="64" />
            <line x2="32" y1="-32" y2="-32" style="linewidth:W" x1="64" />
            <line x2="464" y1="-224" y2="-224" style="linewidth:W" x1="448" />
            <line x2="32" y1="-176" y2="-176" x1="64" />
            <line x2="32" y1="-128" y2="-128" x1="64" />
            <line x2="32" y1="-80" y2="-80" x1="64" />
            <line x2="464" y1="-192" y2="-192" style="linewidth:W" x1="448" />
            <line x2="464" y1="-160" y2="-160" style="linewidth:W" x1="448" />
            <line x2="448" y1="-32" y2="-32" x1="464" />
            <line x2="464" y1="-64" y2="-64" x1="448" />
            <rect style="fillcolor:rgb(149,160,255);fillstyle:Solid" width="384" x="64" y="-260" height="256" />
            <line x2="444" y1="-128" y2="-128" x1="460" />
            <line x2="460" y1="-96" y2="-96" x1="444" />
        </blockdef>
        <blockdef name="clk_div">
            <timestamp>2017-11-3T9:0:57</timestamp>
            <rect style="linewidth:W;linecolor:rgb(0,0,255);fillcolor:rgb(142,240,255);fillstyle:Solid" width="256" x="16" y="-148" height="152" />
            <line x2="288" y1="-16" y2="-16" x1="272" />
            <line x2="0" y1="-16" y2="-16" x1="16" />
            <line x2="288" y1="-128" y2="-128" style="linewidth:W" x1="272" />
            <line x2="0" y1="-128" y2="-128" x1="16" />
            <line x2="288" y1="-64" y2="-64" x1="272" />
            <line x2="0" y1="-48" y2="-48" x1="16" />
            <line x2="0" y1="-80" y2="-80" x1="16" />
        </blockdef>
        <blockdef name="SAnti_jitter">
            <timestamp>2015-12-27T10:36:32</timestamp>
            <rect style="linewidth:W;linecolor:rgb(0,0,255);fillcolor:rgb(170,255,255);fillstyle:Solid" width="300" x="64" y="-248" height="256" />
            <line x2="32" y1="-64" y2="-64" style="linewidth:W" x1="64" />
            <line x2="32" y1="-32" y2="-32" x1="64" />
            <line x2="32" y1="-160" y2="-160" style="linewidth:W" x1="64" />
            <line x2="32" y1="-112" y2="-112" style="linewidth:W" x1="64" />
            <line x2="32" y1="-224" y2="-224" x1="64" />
            <line x2="32" y1="-192" y2="-192" x1="64" />
            <line x2="400" y1="-192" y2="-192" style="linewidth:W" x1="368" />
            <line x2="364" y1="-160" y2="-160" x1="400" />
            <line x2="364" y1="-224" y2="-224" x1="400" />
            <line x2="364" y1="-16" y2="-16" x1="400" />
            <line x2="400" y1="-48" y2="-48" style="linewidth:W" x1="368" />
            <line x2="400" y1="-128" y2="-128" style="linewidth:W" x1="368" />
            <line x2="400" y1="-96" y2="-96" style="linewidth:W" x1="368" />
        </blockdef>
        <blockdef name="Counter">
            <timestamp>2017-3-6T15:29:16</timestamp>
            <rect style="fillcolor:rgb(180,180,180);fillstyle:Solid" width="384" x="64" y="-512" height="512" />
            <line x2="0" y1="-480" y2="-480" x1="64" />
            <line x2="0" y1="-416" y2="-416" x1="64" />
            <line x2="0" y1="-352" y2="-352" x1="64" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="512" y1="-480" y2="-480" x1="448" />
            <line x2="512" y1="-336" y2="-336" x1="448" />
            <line x2="512" y1="-192" y2="-192" x1="448" />
            <rect width="64" x="448" y="-60" height="24" />
            <line x2="512" y1="-48" y2="-48" x1="448" />
        </blockdef>
        <blockdef name="SEnter_2_32">
            <timestamp>2015-12-27T10:39:46</timestamp>
            <line x2="288" y1="-240" y2="-240" x1="320" />
            <line x2="320" y1="-192" y2="-192" style="linewidth:W" x1="288" />
            <line x2="320" y1="-128" y2="-128" style="linewidth:W" x1="288" />
            <line x2="320" y1="-64" y2="-64" style="linewidth:W" x1="288" />
            <rect style="linewidth:W;linecolor:rgb(0,0,255);fillcolor:rgb(170,255,255);fillstyle:Solid" width="256" x="32" y="-272" height="272" />
            <line x2="0" y1="-208" y2="-208" style="linewidth:W" x1="32" />
            <line x2="0" y1="-176" y2="-176" x1="32" />
            <line x2="0" y1="-240" y2="-240" x1="32" />
            <line x2="0" y1="-64" y2="-64" style="linewidth:W" x1="32" />
            <line x2="0" y1="-112" y2="-112" style="linewidth:W" x1="32" />
        </blockdef>
        <blockdef name="Seg7_Dev">
            <timestamp>2016-1-2T8:47:50</timestamp>
            <rect style="linewidth:W;linecolor:rgb(0,0,255);fillcolor:rgb(192,173,254);fillstyle:Solid" width="288" x="32" y="-240" height="240" />
            <line x2="0" y1="-32" y2="-32" style="linewidth:W" x1="32" />
            <line x2="0" y1="-208" y2="-208" style="linewidth:W" x1="32" />
            <line x2="352" y1="-192" y2="-192" style="linewidth:W" x1="320" />
            <line x2="352" y1="-64" y2="-64" style="linewidth:W" x1="320" />
            <line x2="0" y1="-64" y2="-64" style="linewidth:W" x1="32" />
            <line x2="32" y1="-144" y2="-144" x1="0" />
            <line x2="32" y1="-176" y2="-176" x1="0" />
            <line x2="0" y1="-96" y2="-96" style="linewidth:W" x1="32" />
        </blockdef>
        <blockdef name="PIO">
            <timestamp>2015-12-27T10:49:22</timestamp>
            <rect style="fillcolor:rgb(149,160,255);fillstyle:Solid" width="384" x="64" y="-256" height="256" />
            <line x2="32" y1="-224" y2="-224" x1="64" />
            <line x2="32" y1="-160" y2="-160" x1="64" />
            <line x2="32" y1="-96" y2="-96" x1="64" />
            <line x2="32" y1="-32" y2="-32" style="linewidth:W" x1="64" />
            <line x2="480" y1="-32" y2="-32" style="linewidth:W" x1="448" />
            <line x2="480" y1="-128" y2="-128" style="linewidth:W" x1="448" />
            <line x2="480" y1="-224" y2="-224" style="linewidth:W" x1="448" />
        </blockdef>
        <blockdef name="SCPU">
            <timestamp>2024-12-12T1:12:10</timestamp>
            <line x2="-48" y1="-512" y2="-512" x1="-16" />
            <line x2="-48" y1="-464" y2="-464" x1="-16" />
            <line x2="-48" y1="-384" y2="-384" style="linewidth:W" x1="-16" />
            <line x2="-48" y1="-224" y2="-224" style="linecolor:rgb(255,0,0)" x1="-16" />
            <rect style="linewidth:W;linecolor:rgb(0,0,255);fillcolor:rgb(255,170,255);fillstyle:Solid" width="384" x="-16" y="-580" height="564" />
            <line x2="400" y1="-432" y2="-432" style="linewidth:W" x1="368" />
            <line x2="400" y1="-496" y2="-496" x1="368" />
            <line x2="400" y1="-368" y2="-368" style="linewidth:W" x1="368" />
            <line x2="400" y1="-304" y2="-304" style="linewidth:W" x1="368" />
            <line x2="-16" y1="-112" y2="-112" style="linewidth:W" x1="-48" />
            <line x2="400" y1="-176" y2="-176" x1="368" />
            <line x2="400" y1="-112" y2="-112" x1="368" />
        </blockdef>
        <block symbolname="vcc" name="XLXI_1">
            <blockpin signalname="V5" name="P" />
        </block>
        <block symbolname="gnd" name="XLXI_2">
            <blockpin signalname="N0" name="G" />
        </block>
        <block symbolname="inv" name="XLXI_72">
            <blockpin signalname="Clk_CPU" name="I" />
            <blockpin signalname="IO_clk" name="O" />
        </block>
        <block symbolname="ROM_D" name="U2">
            <blockpin signalname="PC(11:2)" name="a(9:0)" />
            <blockpin signalname="inst(31:0)" name="spo(31:0)" />
        </block>
        <block symbolname="RAM_B" name="U3">
            <blockpin signalname="XLXN_558(9:0)" name="addra(9:0)" />
            <blockpin signalname="clk_100mhz" name="clka" />
            <blockpin signalname="XLXN_557(0:0)" name="wea(0:0)" />
            <blockpin signalname="XLXN_556(31:0)" name="dina(31:0)" />
            <blockpin signalname="XLXN_559(31:0)" name="douta(31:0)" />
        </block>
        <block symbolname="MIO_BUS" name="U4">
            <blockpin signalname="rst" name="rst" />
            <blockpin signalname="clk_100mhz" name="clk" />
            <blockpin signalname="XLXN_544" name="mem_w" />
            <blockpin signalname="Addr_out(31:0)" name="addr_bus(31:0)" />
            <blockpin signalname="Data_in(31:0)" name="Cpu_data4bus(31:0)" />
            <blockpin signalname="Data_out(31:0)" name="Cpu_data2bus(31:0)" />
            <blockpin signalname="XLXN_559(31:0)" name="ram_data_out(31:0)" />
            <blockpin signalname="XLXN_558(9:0)" name="ram_addr(9:0)" />
            <blockpin signalname="XLXN_557(0:0)" name="data_ram_we" />
            <blockpin signalname="XLXN_556(31:0)" name="ram_data_in(31:0)" />
            <blockpin signalname="Counter_out(31:0)" name="counter_out(31:0)" />
            <blockpin signalname="XLXN_154" name="counter2_out" />
            <blockpin signalname="XLXN_153" name="counter1_out" />
            <blockpin signalname="XLXN_579" name="counter0_out" />
            <blockpin signalname="XLXN_560" name="counter_we" />
            <blockpin signalname="BTN_OK(3:0)" name="BTN(3:0)" />
            <blockpin signalname="SW_OK(15:0)" name="SW(15:0)" />
            <blockpin signalname="LED_out(15:0)" name="led_out(15:0)" />
            <blockpin signalname="CPU2IO(31:0)" name="Peripheral_in(31:0)" />
            <blockpin signalname="XLXN_541" name="GPIOe0000000_we" />
            <blockpin signalname="GPIOF0" name="GPIOf0000000_we" />
        </block>
        <block symbolname="Multi_8CH32" name="U5">
            <blockpin signalname="SW_OK(7:5)" name="Test(2:0)" />
            <blockpin signalname="Div(31:0),Div(31:0)" name="point_in(63:0)" />
            <blockpin signalname="XLXN_541" name="EN" />
            <blockpin signalname="IO_clk" name="clk" />
            <blockpin signalname="rst" name="rst" />
            <blockpin signalname="N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0" name="LES(63:0)" />
            <blockpin signalname="CPU2IO(31:0)" name="Data0(31:0)" />
            <blockpin signalname="N0,N0,PC(31:2)" name="data1(31:0)" />
            <blockpin signalname="inst(31:0)" name="data2(31:0)" />
            <blockpin signalname="Counter_out(31:0)" name="data3(31:0)" />
            <blockpin signalname="Addr_out(31:0)" name="data4(31:0)" />
            <blockpin signalname="Data_out(31:0)" name="data5(31:0)" />
            <blockpin signalname="Data_in(31:0)" name="data6(31:0)" />
            <blockpin signalname="PC(31:0)" name="data7(31:0)" />
            <blockpin signalname="point_out(7:0)" name="point_out(7:0)" />
            <blockpin signalname="LE_out(7:0)" name="LE_out(7:0)" />
            <blockpin signalname="Disp_num(31:0)" name="Disp_num(31:0)" />
        </block>
        <block symbolname="Display" name="U6">
            <blockpin signalname="LE_out(7:0)" name="LES(7:0)" />
            <blockpin signalname="SEGEN" name="SEGEN" />
            <blockpin signalname="SEGDT" name="segsout" />
            <blockpin name="segclrn" />
            <blockpin signalname="point_out(7:0)" name="points(7:0)" />
            <blockpin signalname="Disp_num(31:0)" name="Hexs(31:0)" />
            <blockpin signalname="SW_OK(0)" name="Text" />
            <blockpin signalname="Div(25)" name="flash" />
            <blockpin signalname="SEGCLK" name="segclk" />
            <blockpin signalname="clk_100mhz" name="clk" />
            <blockpin signalname="rst" name="rst" />
            <blockpin signalname="Div(20)" name="Start" />
        </block>
        <block symbolname="GPIO" name="U7">
            <blockpin signalname="IO_clk" name="clk" />
            <blockpin signalname="CPU2IO(31:0)" name="P_Data(31:0)" />
            <blockpin signalname="rst" name="rst" />
            <blockpin signalname="GPIOF0" name="EN" />
            <blockpin signalname="Div(20)" name="Start" />
            <blockpin signalname="LEDCLK" name="ledclk" />
            <blockpin name="GPIOf0(13:0)" />
            <blockpin signalname="LED_out(15:0)" name="LED_out(15:0)" />
            <blockpin signalname="XLXN_219(1:0)" name="counter_set(1:0)" />
            <blockpin name="ledclrn" />
            <blockpin signalname="LEDEN" name="LEDEN" />
            <blockpin signalname="LEDDT" name="ledsout" />
        </block>
        <block symbolname="clk_div" name="U8">
            <blockpin signalname="clk200N" name="clk200N" />
            <blockpin signalname="Clk_CPU" name="Clk_CPU" />
            <blockpin signalname="rst" name="rst" />
            <blockpin signalname="Div(31:0)" name="clkdiv(31:0)" />
            <blockpin signalname="clk_100mhz" name="clk100MHz" />
            <blockpin signalname="clk200P" name="clk200P" />
            <blockpin signalname="SW_OK(2)" name="STEP" />
        </block>
        <block symbolname="SAnti_jitter" name="U9">
            <blockpin signalname="SW(15:0)" name="SW(15:0)" />
            <blockpin signalname="readn" name="readn" />
            <blockpin signalname="K_COL(3:0)" name="Key_y(3:0)" />
            <blockpin signalname="K_ROW(4:0)" name="Key_x(4:0)" />
            <blockpin signalname="RSTN" name="RSTN" />
            <blockpin signalname="clk_100mhz" name="clk" />
            <blockpin signalname="XLXN_444(4:0)" name="Key_out(4:0)" />
            <blockpin signalname="RDY" name="Key_ready" />
            <blockpin signalname="CR" name="CR" />
            <blockpin signalname="rst" name="rst" />
            <blockpin signalname="SW_OK(15:0)" name="SW_OK(15:0)" />
            <blockpin signalname="Pulse(3:0)" name="pulse_out(3:0)" />
            <blockpin signalname="BTN_OK(3:0)" name="BTN_OK(3:0)" />
        </block>
        <block symbolname="Counter" name="U10">
            <blockpin signalname="IO_clk" name="clk" />
            <blockpin signalname="rst" name="rst" />
            <blockpin signalname="Div(4)" name="clk0" />
            <blockpin signalname="Div(9)" name="clk1" />
            <blockpin signalname="Div(11)" name="clk2" />
            <blockpin signalname="XLXN_560" name="counter_we" />
            <blockpin signalname="CPU2IO(31:0)" name="counter_val(31:0)" />
            <blockpin signalname="XLXN_219(1:0)" name="counter_ch(1:0)" />
            <blockpin signalname="XLXN_579" name="counter0_OUT" />
            <blockpin signalname="XLXN_153" name="counter1_OUT" />
            <blockpin signalname="XLXN_154" name="counter2_OUT" />
            <blockpin signalname="Counter_out(31:0)" name="counter_out(31:0)" />
        </block>
        <block symbolname="SEnter_2_32" name="M4">
            <blockpin signalname="readn" name="readn" />
            <blockpin signalname="Ai(31:0)" name="Ai(31:0)" />
            <blockpin signalname="Bi(31:0)" name="Bi(31:0)" />
            <blockpin signalname="blink(7:0)" name="blink(7:0)" />
            <blockpin signalname="XLXN_444(4:0)" name="Din(4:0)" />
            <blockpin signalname="RDY" name="D_ready" />
            <blockpin signalname="clk_100mhz" name="clk" />
            <blockpin signalname="SW_OK(7:5),SW_OK(15),SW_OK(0)" name="Ctrl(4:0)" />
            <blockpin signalname="BTN_OK(2:0)" name="BTN(2:0)" />
        </block>
        <block symbolname="Seg7_Dev" name="U61">
            <blockpin signalname="LE_out(7:0)" name="LES(7:0)" />
            <blockpin signalname="SW_OK(1),Div(19:18)" name="Scan(2:0)" />
            <blockpin signalname="SEGMENT(7:0)" name="SEGMENT(7:0)" />
            <blockpin signalname="AN(3:0)" name="AN(3:0)" />
            <blockpin signalname="point_out(7:0)" name="point(7:0)" />
            <blockpin signalname="Div(25)" name="flash" />
            <blockpin signalname="SW_OK(0)" name="SW0" />
            <blockpin signalname="Disp_num(31:0)" name="Hexs(31:0)" />
        </block>
        <block symbolname="PIO" name="U71">
            <blockpin signalname="IO_clk" name="clk" />
            <blockpin signalname="rst" name="rst" />
            <blockpin signalname="GPIOF0" name="EN" />
            <blockpin signalname="CPU2IO(31:0)" name="PData_in(31:0)" />
            <blockpin name="GPIOf0(21:0)" />
            <blockpin signalname="LED(7:0)" name="LED_out(7:0)" />
            <blockpin name="counter_set(1:0)" />
        </block>
        <block symbolname="SCPU" name="XLXI_74">
            <blockpin signalname="Clk_CPU" name="clk" />
            <blockpin signalname="XLXN_579" name="INT" />
            <blockpin signalname="inst(31:0)" name="inst_in(31:0)" />
            <blockpin signalname="rst" name="reset" />
            <blockpin name="MIO_ready" />
            <blockpin signalname="Data_in(31:0)" name="Data_in(31:0)" />
            <blockpin name="CPU_MIO" />
            <blockpin signalname="XLXN_544" name="mem_w" />
            <blockpin signalname="PC(31:0)" name="PC_out(31:0)" />
            <blockpin signalname="Addr_out(31:0)" name="Addr_out(31:0)" />
            <blockpin signalname="Data_out(31:0)" name="Data_out(31:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="Disp_num(31:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2784" y="592" type="branch" />
            <wire x2="2240" y1="304" y2="592" x1="2240" />
            <wire x2="2784" y1="592" y2="592" x1="2240" />
            <wire x2="3200" y1="592" y2="592" x1="2784" />
            <wire x2="3200" y1="592" y2="736" x1="3200" />
            <wire x2="2336" y1="304" y2="304" x1="2240" />
            <wire x2="3200" y1="736" y2="736" x1="3168" />
        </branch>
        <branch name="LE_out(7:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2768" y="496" type="branch" />
            <wire x2="2304" y1="368" y2="496" x1="2304" />
            <wire x2="2768" y1="496" y2="496" x1="2304" />
            <wire x2="3264" y1="496" y2="496" x1="2768" />
            <wire x2="3264" y1="496" y2="832" x1="3264" />
            <wire x2="2336" y1="368" y2="368" x1="2304" />
            <wire x2="3264" y1="832" y2="832" x1="3168" />
        </branch>
        <branch name="point_out(7:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2784" y="544" type="branch" />
            <wire x2="2272" y1="336" y2="544" x1="2272" />
            <wire x2="2784" y1="544" y2="544" x1="2272" />
            <wire x2="3232" y1="544" y2="544" x1="2784" />
            <wire x2="3232" y1="544" y2="784" x1="3232" />
            <wire x2="2336" y1="336" y2="336" x1="2272" />
            <wire x2="3232" y1="784" y2="784" x1="3168" />
        </branch>
        <branch name="SW_OK(7:5)">
            <wire x2="2784" y1="832" y2="832" x1="2288" />
        </branch>
        <bustap x2="2288" y1="832" y2="832" x1="2192" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="304" cy="134" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="304" cy="132" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="364" cy="134" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="364" cy="132" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="428" cy="134" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="428" cy="132" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="492" cy="134" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="492" cy="132" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="304" cy="186" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="304" cy="184" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="304" cy="234" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="304" cy="232" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="364" cy="186" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="364" cy="184" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="428" cy="186" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="428" cy="184" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="364" cy="234" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="428" cy="234" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="428" cy="232" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="364" cy="232" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="492" cy="186" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="492" cy="184" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="492" cy="234" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="492" cy="232" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="304" cy="334" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="304" cy="332" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="364" cy="334" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="428" cy="334" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="428" cy="332" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="364" cy="332" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="304" cy="282" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="304" cy="280" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="364" cy="282" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="364" cy="280" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="428" cy="282" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="428" cy="280" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="492" cy="282" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="492" cy="280" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="564" cy="182" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="564" cy="180" />
        <branch name="readn">
            <wire x2="816" y1="304" y2="304" x1="800" />
            <wire x2="800" y1="304" y2="400" x1="800" />
            <wire x2="2016" y1="400" y2="400" x1="800" />
            <wire x2="2016" y1="112" y2="112" x1="1904" />
            <wire x2="2048" y1="112" y2="112" x1="2016" />
            <wire x2="2016" y1="112" y2="400" x1="2016" />
        </branch>
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="20" cx="492" cy="334" />
        <circle style="linecolor:rgb(0,255,0);fillcolor:rgb(0,0,0);fillstyle:Solid" r="12" cx="492" cy="332" />
        <rect style="linecolor:rgb(255,0,0);fillcolor:rgb(0,0,255);fillstyle:Solid" width="44" x="296" y="388" height="84" />
        <rect style="linecolor:rgb(255,0,0);fillcolor:rgb(0,0,0);fillstyle:Solid" width="36" x="300" y="436" height="28" />
        <text style="fontsize:20;fontname:Arial" x="296" y="496">SW14</text>
        <text style="fontsize:58;fontname:Arial" x="372" y="424">...</text>
        <text style="fontsize:20;fontname:Arial" x="432" y="496">SW1</text>
        <text style="fontsize:20;fontname:Arial" x="504" y="492">SW0</text>
        <rect style="linecolor:rgb(255,0,0);fillcolor:rgb(0,0,255);fillstyle:Solid" width="44" x="444" y="388" height="84" />
        <rect style="linecolor:rgb(255,0,0);fillcolor:rgb(0,0,0);fillstyle:Solid" width="36" x="448" y="396" height="28" />
        <rect style="linecolor:rgb(255,0,0);fillcolor:rgb(0,0,255);fillstyle:Solid" width="44" x="512" y="384" height="84" />
        <rect style="linecolor:rgb(255,0,0);fillcolor:rgb(0,0,0);fillstyle:Solid" width="36" x="516" y="432" height="28" />
        <branch name="SW(15:0)">
            <wire x2="576" y1="512" y2="512" x1="192" />
            <wire x2="816" y1="272" y2="272" x1="576" />
            <wire x2="576" y1="272" y2="512" x1="576" />
        </branch>
        <branch name="K_ROW(4:0)">
            <wire x2="560" y1="368" y2="368" x1="224" />
            <wire x2="816" y1="224" y2="224" x1="560" />
            <wire x2="560" y1="224" y2="368" x1="560" />
        </branch>
        <branch name="K_COL(3:0)">
            <wire x2="592" y1="160" y2="160" x1="208" />
            <wire x2="592" y1="160" y2="176" x1="592" />
            <wire x2="816" y1="176" y2="176" x1="592" />
        </branch>
        <branch name="RSTN">
            <wire x2="816" y1="112" y2="112" x1="144" />
        </branch>
        <iomarker fontsize="28" x="208" y="160" name="K_COL(3:0)" orien="R180" />
        <iomarker fontsize="28" x="192" y="512" name="SW(15:0)" orien="R180" />
        <iomarker fontsize="28" x="1968" y="64" name="RDY" orien="R0" />
        <iomarker fontsize="28" x="144" y="112" name="RSTN" orien="R180" />
        <iomarker fontsize="28" x="2048" y="112" name="readn" orien="R0" />
        <branch name="SW_OK(7:5),SW_OK(15),SW_OK(0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1488" y="288" type="branch" />
            <wire x2="1488" y1="288" y2="288" x1="1424" />
            <wire x2="1584" y1="288" y2="288" x1="1488" />
        </branch>
        <branch name="BTN_OK(2:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:20;fontname:Arial" attrname="Name" x="1536" y="240" type="branch" />
            <wire x2="1536" y1="240" y2="240" x1="1424" />
            <wire x2="1584" y1="240" y2="240" x1="1536" />
        </branch>
        <branch name="RDY">
            <wire x2="1552" y1="176" y2="176" x1="1184" />
            <wire x2="1584" y1="176" y2="176" x1="1552" />
            <wire x2="1968" y1="64" y2="64" x1="1552" />
            <wire x2="1552" y1="64" y2="176" x1="1552" />
        </branch>
        <branch name="XLXN_444(4:0)">
            <wire x2="1584" y1="144" y2="144" x1="1184" />
        </branch>
        <branch name="CR">
            <wire x2="1280" y1="112" y2="112" x1="1184" />
        </branch>
        <iomarker fontsize="28" x="1280" y="112" name="CR" orien="R0" />
        <bustap x2="1424" y1="288" y2="288" x1="1328" />
        <rect style="linecolor:rgb(255,0,0);fillcolor:rgb(0,0,255);fillstyle:Solid" width="44" x="228" y="388" height="84" />
        <rect style="linecolor:rgb(255,0,0);fillcolor:rgb(0,0,0);fillstyle:Solid" width="36" x="232" y="396" height="28" />
        <text style="fontsize:20;fontname:Arial" x="220" y="496">SW15</text>
        <bustap x2="1424" y1="240" y2="240" x1="1328" />
        <branch name="Pulse(3:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="1296" y="208" type="branch" />
            <wire x2="1296" y1="208" y2="208" x1="1184" />
        </branch>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="3420" y="128" height="88" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="3324" y="128" height="88" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="3420" y="216" height="96" />
        <text style="fontsize:40;fontname:Arial" x="3428" y="172">b</text>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="3356" y="284" height="28" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="3324" y="216" height="96" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="3356" y="128" height="28" />
        <text style="fontsize:40;fontname:Arial;textcolor:rgb(0,0,0)" x="3328" y="260">e</text>
        <text style="fontsize:40;fontname:Arial;textcolor:rgb(0,0,0)" x="3380" y="300">d</text>
        <text style="fontsize:40;fontname:Arial" x="3332" y="180">f</text>
        <text style="fontsize:40;fontname:Arial" x="3428" y="260">c</text>
        <text style="fontsize:40;fontname:Arial" x="3384" y="140">a</text>
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="16" cx="3476" cy="296" />
        <text style="fontsize:28;fontname:Arial" x="3460" y="296">dp</text>
        <rect style="linewidth:W;linecolor:rgb(0,0,255);linestyle:Dot" width="724" x="2772" y="112" height="236" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="3356" y="200" height="32" />
        <text style="fontsize:40;fontname:Arial" x="3380" y="212">g</text>
        <text style="fontsize:28;fontname:Arial" x="3360" y="328">AN0</text>
        <text style="alignment:CENTER;fontsize:40;fontname:Times New Roman;textcolor:rgb(255,0,0)" x="3128" y="84">Seven-Digit: Seven-Segment LED Display</text>
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="16" cx="3180" cy="232" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="16" cx="3236" cy="232" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="16" cx="3288" cy="232" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="3084" y="128" height="88" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="2988" y="128" height="88" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="3084" y="216" height="96" />
        <text style="fontsize:40;fontname:Arial" x="3092" y="172">b</text>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="3020" y="284" height="28" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="2988" y="216" height="96" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="3020" y="128" height="28" />
        <text style="fontsize:40;fontname:Arial;textcolor:rgb(0,0,0)" x="2992" y="260">e</text>
        <text style="fontsize:40;fontname:Arial" x="2996" y="180">f</text>
        <text style="fontsize:40;fontname:Arial" x="3092" y="260">c</text>
        <text style="fontsize:40;fontname:Arial" x="3036" y="140">a</text>
        <text style="fontsize:40;fontname:Arial;textcolor:rgb(0,0,0)" x="3040" y="300">d</text>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="3020" y="200" height="32" />
        <text style="fontsize:40;fontname:Arial" x="3044" y="212">g</text>
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="16" cx="3136" cy="296" />
        <text style="fontsize:28;fontname:Arial" x="3120" y="296">dp</text>
        <line x2="2980" y1="348" y2="112" x1="2980" />
        <text style="fontsize:28;fontname:Arial" x="3024" y="332">AN7</text>
        <branch name="Div(25)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:24;fontname:Arial" attrname="Name" x="2272" y="256" type="branch" />
            <wire x2="2336" y1="256" y2="256" x1="2272" />
        </branch>
        <branch name="SW_OK(0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:24;fontname:Arial" attrname="Name" x="2288" y="192" type="branch" />
            <wire x2="2336" y1="192" y2="192" x1="2288" />
        </branch>
        <branch name="Div(20)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="2304" y="144" type="branch" />
            <wire x2="2336" y1="144" y2="144" x1="2304" />
        </branch>
        <branch name="rst">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="2288" y="112" type="branch" />
            <wire x2="2336" y1="112" y2="112" x1="2288" />
        </branch>
        <branch name="Ai(31:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="2064" y="160" type="branch" />
            <wire x2="2064" y1="160" y2="160" x1="1904" />
        </branch>
        <branch name="Bi(31:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="2064" y="224" type="branch" />
            <wire x2="2064" y1="224" y2="224" x1="1904" />
        </branch>
        <branch name="PC(31:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="2576" y="1328" type="branch" />
            <wire x2="2784" y1="1328" y2="1328" x1="2576" />
        </branch>
        <branch name="Data_in(31:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="2640" y="1280" type="branch" />
            <wire x2="2784" y1="1280" y2="1280" x1="2640" />
        </branch>
        <branch name="Data_out(31:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="2656" y="1232" type="branch" />
            <wire x2="2784" y1="1232" y2="1232" x1="2656" />
        </branch>
        <branch name="Addr_out(31:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="2656" y="1184" type="branch" />
            <wire x2="2784" y1="1184" y2="1184" x1="2656" />
        </branch>
        <branch name="inst(31:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="2592" y="1088" type="branch" />
            <wire x2="2784" y1="1088" y2="1088" x1="2592" />
        </branch>
        <branch name="N0,N0,PC(31:2)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="2672" y="1040" type="branch" />
            <wire x2="2784" y1="1040" y2="1040" x1="2672" />
        </branch>
        <branch name="Counter_out(31:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="2688" y="1136" type="branch" />
            <wire x2="2784" y1="1136" y2="1136" x1="2688" />
        </branch>
        <branch name="N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0,N0">
            <wire x2="2784" y1="944" y2="944" x1="2576" />
        </branch>
        <branch name="Div(31:0),Div(31:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="2688" y="896" type="branch" />
            <wire x2="2784" y1="896" y2="896" x1="2688" />
        </branch>
        <branch name="Counter_out(31:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:24;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="2240" y="1568" type="branch" />
            <wire x2="2240" y1="1568" y2="1568" x1="2160" />
            <wire x2="2304" y1="1568" y2="1568" x1="2240" />
            <wire x2="2304" y1="1568" y2="2416" x1="2304" />
            <wire x2="2304" y1="2416" y2="2416" x1="2160" />
        </branch>
        <branch name="XLXN_219(1:0)">
            <wire x2="1648" y1="2432" y2="2432" x1="1632" />
            <wire x2="1632" y1="2432" y2="2496" x1="1632" />
            <wire x2="2336" y1="2496" y2="2496" x1="1632" />
            <wire x2="2336" y1="1456" y2="2496" x1="2336" />
            <wire x2="3216" y1="1456" y2="1456" x1="2336" />
            <wire x2="3216" y1="1456" y2="1520" x1="3216" />
            <wire x2="3216" y1="1520" y2="1520" x1="3200" />
        </branch>
        <branch name="Div(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1600" y="2112" type="branch" />
            <wire x2="1600" y1="2112" y2="2112" x1="1584" />
            <wire x2="1648" y1="2112" y2="2112" x1="1600" />
        </branch>
        <branch name="Div(9)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1600" y="2176" type="branch" />
            <wire x2="1600" y1="2176" y2="2176" x1="1584" />
            <wire x2="1648" y1="2176" y2="2176" x1="1600" />
        </branch>
        <branch name="Div(11)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1600" y="2240" type="branch" />
            <wire x2="1600" y1="2240" y2="2240" x1="1584" />
            <wire x2="1648" y1="2240" y2="2240" x1="1600" />
        </branch>
        <bustap x2="1584" y1="2112" y2="2112" x1="1488" />
        <bustap x2="1584" y1="2176" y2="2176" x1="1488" />
        <bustap x2="1584" y1="2240" y2="2240" x1="1488" />
        <branch name="XLXN_154">
            <wire x2="2272" y1="1600" y2="1600" x1="2160" />
            <wire x2="2272" y1="1600" y2="2272" x1="2272" />
            <wire x2="2272" y1="2272" y2="2272" x1="2160" />
        </branch>
        <branch name="XLXN_153">
            <wire x2="2240" y1="1632" y2="1632" x1="2160" />
            <wire x2="2240" y1="1632" y2="2128" x1="2240" />
            <wire x2="2240" y1="2128" y2="2128" x1="2160" />
        </branch>
        <branch name="CPU2IO(31:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2224" y="992" type="branch" />
            <wire x2="1648" y1="2368" y2="2368" x1="1584" />
            <wire x2="1584" y1="2368" y2="2528" x1="1584" />
            <wire x2="2368" y1="2528" y2="2528" x1="1584" />
            <wire x2="2224" y1="992" y2="992" x1="2160" />
            <wire x2="2368" y1="992" y2="992" x1="2224" />
            <wire x2="2784" y1="992" y2="992" x1="2368" />
            <wire x2="2368" y1="992" y2="1712" x1="2368" />
            <wire x2="2368" y1="1712" y2="2528" x1="2368" />
            <wire x2="2768" y1="1712" y2="1712" x1="2368" />
        </branch>
        <branch name="Div(20)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="2720" y="1664" type="branch" />
            <wire x2="2768" y1="1664" y2="1664" x1="2720" />
        </branch>
        <instance x="3360" y="496" name="XLXI_1" orien="R0" />
        <branch name="V5">
            <attrtext style="alignment:SOFT-LEFT;fontsize:38;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="3440" y="512" type="branch" />
            <wire x2="3424" y1="496" y2="512" x1="3424" />
            <wire x2="3440" y1="512" y2="512" x1="3424" />
        </branch>
        <instance x="3360" y="768" name="XLXI_2" orien="R0" />
        <branch name="N0">
            <attrtext style="alignment:SOFT-LEFT;fontsize:38;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="3440" y="624" type="branch" />
            <wire x2="3424" y1="624" y2="640" x1="3424" />
            <wire x2="3440" y1="624" y2="624" x1="3424" />
        </branch>
        <text style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" x="3388" y="1748">LED </text>
        <rect style="linewidth:W;linecolor:rgb(0,0,255);linestyle:Dot" width="104" x="3408" y="932" height="776" />
        <circle style="linecolor:rgb(0,0,255);fillcolor:rgb(255,0,0);fillstyle:Solid" r="40" cx="3460" cy="988" />
        <circle style="linecolor:rgb(0,0,255);fillcolor:rgb(255,0,0);fillstyle:Solid" r="40" cx="3460" cy="1080" />
        <circle style="linecolor:rgb(0,0,255);fillcolor:rgb(255,0,0);fillstyle:Solid" r="40" cx="3460" cy="1172" />
        <circle style="linecolor:rgb(0,0,255);fillcolor:rgb(255,0,0);fillstyle:Solid" r="40" cx="3460" cy="1264" />
        <circle style="linecolor:rgb(0,0,255);fillcolor:rgb(255,0,0);fillstyle:Solid" r="40" cx="3460" cy="1460" />
        <circle style="linecolor:rgb(0,0,255);fillcolor:rgb(255,0,0);fillstyle:Solid" r="40" cx="3460" cy="1556" />
        <circle style="linecolor:rgb(0,0,255);fillcolor:rgb(255,0,0);fillstyle:Solid" r="40" cx="3460" cy="1652" />
        <circle style="linecolor:rgb(0,0,255);fillcolor:rgb(255,0,0);fillstyle:Solid" r="40" cx="3460" cy="1360" />
        <branch name="XLXN_541">
            <wire x2="2336" y1="1040" y2="1040" x1="2160" />
            <wire x2="2336" y1="784" y2="1040" x1="2336" />
            <wire x2="2784" y1="784" y2="784" x1="2336" />
        </branch>
        <branch name="GPIOF0">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2192" y="1088" type="branch" />
            <wire x2="2192" y1="1088" y2="1088" x1="2160" />
            <wire x2="2400" y1="1088" y2="1088" x1="2192" />
            <wire x2="2400" y1="1088" y2="1616" x1="2400" />
            <wire x2="2768" y1="1616" y2="1616" x1="2400" />
        </branch>
        <branch name="XLXN_544">
            <wire x2="1152" y1="1216" y2="1216" x1="1136" />
            <wire x2="1184" y1="1216" y2="1216" x1="1152" />
            <wire x2="1664" y1="1216" y2="1216" x1="1184" />
        </branch>
        <branch name="Addr_out(31:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="1328" y="1280" type="branch" />
            <wire x2="1152" y1="1280" y2="1280" x1="1136" />
            <wire x2="1184" y1="1280" y2="1280" x1="1152" />
            <wire x2="1328" y1="1280" y2="1280" x1="1184" />
            <wire x2="1664" y1="1280" y2="1280" x1="1328" />
        </branch>
        <branch name="Data_in(31:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="1312" y="1344" type="branch" />
            <wire x2="1152" y1="1344" y2="1344" x1="1136" />
            <wire x2="1184" y1="1344" y2="1344" x1="1152" />
            <wire x2="1312" y1="1344" y2="1344" x1="1184" />
            <wire x2="1664" y1="1344" y2="1344" x1="1312" />
        </branch>
        <branch name="Data_out(31:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="1312" y="1408" type="branch" />
            <wire x2="1152" y1="1408" y2="1408" x1="1136" />
            <wire x2="1184" y1="1408" y2="1408" x1="1152" />
            <wire x2="1312" y1="1408" y2="1408" x1="1184" />
            <wire x2="1664" y1="1408" y2="1408" x1="1312" />
        </branch>
        <branch name="rst">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1200" y="320" type="branch" />
            <wire x2="640" y1="736" y2="1248" x1="640" />
            <wire x2="688" y1="1248" y2="1248" x1="640" />
            <wire x2="704" y1="1248" y2="1248" x1="688" />
            <wire x2="848" y1="736" y2="736" x1="640" />
            <wire x2="1600" y1="736" y2="736" x1="848" />
            <wire x2="2720" y1="736" y2="736" x1="1600" />
            <wire x2="2784" y1="736" y2="736" x1="2720" />
            <wire x2="2720" y1="736" y2="1568" x1="2720" />
            <wire x2="2768" y1="1568" y2="1568" x1="2720" />
            <wire x2="1600" y1="736" y2="1024" x1="1600" />
            <wire x2="1664" y1="1024" y2="1024" x1="1600" />
            <wire x2="1600" y1="1024" y2="2048" x1="1600" />
            <wire x2="1648" y1="2048" y2="2048" x1="1600" />
            <wire x2="848" y1="368" y2="480" x1="848" />
            <wire x2="880" y1="480" y2="480" x1="848" />
            <wire x2="848" y1="480" y2="736" x1="848" />
            <wire x2="1216" y1="368" y2="368" x1="848" />
            <wire x2="1200" y1="320" y2="320" x1="1184" />
            <wire x2="1216" y1="320" y2="320" x1="1200" />
            <wire x2="1216" y1="320" y2="368" x1="1216" />
        </branch>
        <branch name="BTN_OK(3:0)">
            <wire x2="1296" y1="240" y2="240" x1="1184" />
            <wire x2="1328" y1="240" y2="240" x1="1296" />
            <wire x2="1296" y1="240" y2="1088" x1="1296" />
            <wire x2="1664" y1="1088" y2="1088" x1="1296" />
        </branch>
        <branch name="SW_OK(15:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:20;fontname:Arial" attrname="Name" x="1232" y="288" type="branch" />
            <wire x2="1232" y1="288" y2="288" x1="1184" />
            <wire x2="1264" y1="288" y2="288" x1="1232" />
            <wire x2="1264" y1="288" y2="832" x1="1264" />
            <wire x2="2192" y1="832" y2="832" x1="1264" />
            <wire x2="1264" y1="832" y2="1136" x1="1264" />
            <wire x2="1664" y1="1136" y2="1136" x1="1264" />
            <wire x2="1328" y1="288" y2="288" x1="1264" />
        </branch>
        <branch name="XLXN_560">
            <wire x2="1392" y1="1840" y2="2304" x1="1392" />
            <wire x2="1648" y1="2304" y2="2304" x1="1392" />
            <wire x2="2176" y1="1840" y2="1840" x1="1392" />
            <wire x2="2176" y1="1696" y2="1696" x1="2160" />
            <wire x2="2176" y1="1696" y2="1840" x1="2176" />
        </branch>
        <branch name="inst(31:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="560" y="1328" type="branch" />
            <wire x2="592" y1="1328" y2="1328" x1="560" />
            <wire x2="688" y1="1328" y2="1328" x1="592" />
            <wire x2="704" y1="1328" y2="1328" x1="688" />
            <wire x2="592" y1="1328" y2="1744" x1="592" />
            <wire x2="1136" y1="1744" y2="1744" x1="592" />
            <wire x2="1136" y1="1744" y2="1952" x1="1136" />
            <wire x2="1136" y1="1952" y2="1952" x1="1104" />
        </branch>
        <branch name="LED_out(15:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2256" y="1392" type="branch" />
            <wire x2="2256" y1="1392" y2="1392" x1="2160" />
            <wire x2="3248" y1="1392" y2="1392" x1="2256" />
            <wire x2="3248" y1="1392" y2="1552" x1="3248" />
            <wire x2="3248" y1="1552" y2="1552" x1="3200" />
        </branch>
        <branch name="clk_100mhz">
            <wire x2="240" y1="688" y2="2448" x1="240" />
            <wire x2="656" y1="2448" y2="2448" x1="240" />
            <wire x2="768" y1="688" y2="688" x1="240" />
            <wire x2="1184" y1="688" y2="688" x1="768" />
            <wire x2="1632" y1="688" y2="688" x1="1184" />
            <wire x2="1632" y1="688" y2="960" x1="1632" />
            <wire x2="1664" y1="960" y2="960" x1="1632" />
            <wire x2="1504" y1="64" y2="64" x1="768" />
            <wire x2="1504" y1="64" y2="112" x1="1504" />
            <wire x2="1584" y1="112" y2="112" x1="1504" />
            <wire x2="768" y1="64" y2="144" x1="768" />
            <wire x2="816" y1="144" y2="144" x1="768" />
            <wire x2="768" y1="144" y2="688" x1="768" />
            <wire x2="1184" y1="544" y2="544" x1="1168" />
            <wire x2="1184" y1="544" y2="688" x1="1184" />
            <wire x2="2288" y1="32" y2="32" x1="1504" />
            <wire x2="2288" y1="32" y2="80" x1="2288" />
            <wire x2="2336" y1="80" y2="80" x1="2288" />
            <wire x2="1504" y1="32" y2="64" x1="1504" />
        </branch>
        <branch name="IO_clk">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="592" type="branch" />
            <wire x2="2432" y1="1872" y2="1872" x1="1632" />
            <wire x2="1632" y1="1872" y2="1984" x1="1632" />
            <wire x2="1648" y1="1984" y2="1984" x1="1632" />
            <wire x2="1904" y1="592" y2="592" x1="1840" />
            <wire x2="1904" y1="592" y2="688" x1="1904" />
            <wire x2="2752" y1="688" y2="688" x1="1904" />
            <wire x2="2784" y1="688" y2="688" x1="2752" />
            <wire x2="2752" y1="688" y2="1520" x1="2752" />
            <wire x2="2768" y1="1520" y2="1520" x1="2752" />
            <wire x2="2432" y1="1520" y2="1872" x1="2432" />
            <wire x2="2752" y1="1520" y2="1520" x1="2432" />
        </branch>
        <branch name="XLXN_579">
            <wire x2="688" y1="1488" y2="1488" x1="624" />
            <wire x2="704" y1="1488" y2="1488" x1="688" />
            <wire x2="624" y1="1488" y2="1792" x1="624" />
            <wire x2="2208" y1="1792" y2="1792" x1="624" />
            <wire x2="2208" y1="1792" y2="1984" x1="2208" />
            <wire x2="2208" y1="1664" y2="1664" x1="2160" />
            <wire x2="2208" y1="1664" y2="1792" x1="2208" />
            <wire x2="2208" y1="1984" y2="1984" x1="2160" />
        </branch>
        <bustap x2="576" y1="1952" y2="1952" x1="480" />
        <branch name="PC(11:2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="592" y="1952" type="branch" />
            <wire x2="592" y1="1952" y2="1952" x1="576" />
            <wire x2="656" y1="1952" y2="1952" x1="592" />
        </branch>
        <rect style="linewidth:W;linecolor:rgb(0,0,255);fillcolor:rgb(192,192,192);fillstyle:Solid" width="704" x="2592" y="1920" height="296" />
        <text style="fontsize:160;fontname:Arial;textcolor:rgb(255,0,0)" x="2768" y="2072">VGA</text>
        <rect style="linewidth:W;linecolor:rgb(128,0,0);fillcolor:rgb(166,202,240);fillstyle:Solid" width="500" x="2696" y="2304" height="152" />
        <text style="fontsize:80;fontname:Arial;textcolor:rgb(255,0,0)" x="2712" y="2384">KEYBOARD</text>
        <rect style="linecolor:rgb(255,0,0);linestyle:Dash" width="552" x="2416" y="868" height="488" />
        <text style="fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" x="2456" y="948">64{1'b0}</text>
        <branch name="PC(31:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="432" y="1600" type="branch" />
            <wire x2="480" y1="1600" y2="1600" x1="432" />
            <wire x2="480" y1="1600" y2="1952" x1="480" />
            <wire x2="688" y1="1600" y2="1600" x1="480" />
            <wire x2="704" y1="1600" y2="1600" x1="688" />
        </branch>
        <branch name="blink(7:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2064" y="288" type="branch" />
            <wire x2="2064" y1="288" y2="288" x1="1904" />
        </branch>
        <branch name="LEDCLK">
            <wire x2="3248" y1="1616" y2="1616" x1="3200" />
        </branch>
        <branch name="LEDDT">
            <wire x2="3248" y1="1648" y2="1648" x1="3200" />
        </branch>
        <branch name="LEDEN">
            <wire x2="3248" y1="1680" y2="1680" x1="3200" />
        </branch>
        <iomarker fontsize="28" x="3248" y="1616" name="LEDCLK" orien="R0" />
        <iomarker fontsize="28" x="3248" y="1648" name="LEDDT" orien="R0" />
        <iomarker fontsize="28" x="3248" y="1680" name="LEDEN" orien="R0" />
        <branch name="SEGCLK">
            <wire x2="2784" y1="128" y2="128" x1="2720" />
        </branch>
        <branch name="SEGDT">
            <wire x2="2784" y1="192" y2="192" x1="2720" />
        </branch>
        <branch name="SEGEN">
            <wire x2="2784" y1="256" y2="256" x1="2720" />
        </branch>
        <iomarker fontsize="28" x="2784" y="128" name="SEGCLK" orien="R0" />
        <iomarker fontsize="28" x="2784" y="192" name="SEGDT" orien="R0" />
        <iomarker fontsize="28" x="2784" y="256" name="SEGEN" orien="R0" />
        <iomarker fontsize="28" x="224" y="368" name="K_ROW(4:0)" orien="R180" />
        <branch name="XLXN_559(31:0)">
            <wire x2="1344" y1="2320" y2="2320" x1="1104" />
            <wire x2="1344" y1="1696" y2="2320" x1="1344" />
            <wire x2="1664" y1="1696" y2="1696" x1="1344" />
        </branch>
        <branch name="XLXN_556(31:0)">
            <wire x2="1248" y1="2112" y2="2112" x1="480" />
            <wire x2="480" y1="2112" y2="2400" x1="480" />
            <wire x2="656" y1="2400" y2="2400" x1="480" />
            <wire x2="1248" y1="1552" y2="2112" x1="1248" />
            <wire x2="1664" y1="1552" y2="1552" x1="1248" />
        </branch>
        <branch name="XLXN_557(0:0)">
            <wire x2="1280" y1="2144" y2="2144" x1="528" />
            <wire x2="528" y1="2144" y2="2320" x1="528" />
            <wire x2="656" y1="2320" y2="2320" x1="528" />
            <wire x2="1280" y1="1600" y2="2144" x1="1280" />
            <wire x2="1664" y1="1600" y2="1600" x1="1280" />
        </branch>
        <branch name="XLXN_558(9:0)">
            <wire x2="1312" y1="2176" y2="2176" x1="576" />
            <wire x2="576" y1="2176" y2="2256" x1="576" />
            <wire x2="656" y1="2256" y2="2256" x1="576" />
            <wire x2="1312" y1="1648" y2="2176" x1="1312" />
            <wire x2="1664" y1="1648" y2="1648" x1="1312" />
        </branch>
        <instance x="656" y="1744" name="U2" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" attrname="InstName" x="192" y="146" type="instance" />
        </instance>
        <instance x="656" y="2176" name="U3" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" attrname="InstName" x="192" y="104" type="instance" />
        </instance>
        <instance x="1632" y="1760" name="U4" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" attrname="InstName" x="272" y="-272" type="instance" />
        </instance>
        <instance x="2784" y="1360" name="U5" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" attrname="InstName" x="240" y="-416" type="instance" />
        </instance>
        <instance x="2336" y="416" name="U6" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" attrname="InstName" x="160" y="-268" type="instance" />
        </instance>
        <instance x="2736" y="1744" name="U7" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" attrname="InstName" x="192" y="-196" type="instance" />
        </instance>
        <instance x="784" y="336" name="U9" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" attrname="InstName" x="160" y="-200" type="instance" />
        </instance>
        <instance x="1648" y="2464" name="U10" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" attrname="InstName" x="192" y="-272" type="instance" />
        </instance>
        <instance x="1584" y="352" name="M4" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(0,0,255)" attrname="InstName" x="128" y="-224" type="instance" />
        </instance>
        <instance x="1616" y="624" name="XLXI_72" orien="R0" />
        <branch name="clk200N">
            <wire x2="384" y1="640" y2="640" x1="176" />
            <wire x2="384" y1="592" y2="640" x1="384" />
            <wire x2="880" y1="592" y2="592" x1="384" />
        </branch>
        <branch name="Clk_CPU">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:24;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="1360" y="592" type="branch" />
            <wire x2="672" y1="1072" y2="1200" x1="672" />
            <wire x2="688" y1="1200" y2="1200" x1="672" />
            <wire x2="704" y1="1200" y2="1200" x1="688" />
            <wire x2="1216" y1="1072" y2="1072" x1="672" />
            <wire x2="1216" y1="592" y2="592" x1="1168" />
            <wire x2="1216" y1="592" y2="1072" x1="1216" />
            <wire x2="1360" y1="592" y2="592" x1="1216" />
            <wire x2="1616" y1="592" y2="592" x1="1360" />
        </branch>
        <branch name="Div(31:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:26;fontname:Arial;textcolor:rgb(255,0,0)" attrname="Name" x="1520" y="480" type="branch" />
            <wire x2="1488" y1="480" y2="480" x1="1168" />
            <wire x2="1520" y1="480" y2="480" x1="1488" />
            <wire x2="1488" y1="480" y2="2112" x1="1488" />
            <wire x2="1488" y1="2112" y2="2176" x1="1488" />
            <wire x2="1488" y1="2176" y2="2240" x1="1488" />
        </branch>
        <branch name="clk200P">
            <wire x2="352" y1="576" y2="576" x1="176" />
            <wire x2="880" y1="560" y2="560" x1="352" />
            <wire x2="352" y1="560" y2="576" x1="352" />
        </branch>
        <branch name="SW_OK(2)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:20;fontname:Arial" attrname="Name" x="704" y="528" type="branch" />
            <wire x2="880" y1="528" y2="528" x1="704" />
        </branch>
        <instance x="880" y="608" name="U8" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" attrname="InstName" x="96" y="-32" type="instance" />
        </instance>
        <iomarker fontsize="28" x="176" y="640" name="clk200N" orien="R180" />
        <iomarker fontsize="28" x="176" y="576" name="clk200P" orien="R180" />
        <instance x="752" y="1712" name="XLXI_74" orien="R0">
        </instance>
    </sheet>
    <sheet sheetnum="2" width="1760" height="1360">
        <branch name="SEGMENT(7:0)">
            <wire x2="976" y1="128" y2="128" x1="944" />
            <wire x2="1488" y1="48" y2="48" x1="976" />
            <wire x2="976" y1="48" y2="128" x1="976" />
        </branch>
        <branch name="AN(3:0)">
            <wire x2="976" y1="256" y2="256" x1="944" />
            <wire x2="976" y1="256" y2="384" x1="976" />
            <wire x2="1584" y1="384" y2="384" x1="976" />
        </branch>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1644" y="128" height="88" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1548" y="128" height="88" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1644" y="216" height="96" />
        <text style="fontsize:40;fontname:Arial" x="1652" y="172">b</text>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="1580" y="284" height="28" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1548" y="216" height="96" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="1580" y="128" height="28" />
        <text style="fontsize:40;fontname:Arial;textcolor:rgb(0,0,0)" x="1552" y="260">e</text>
        <text style="fontsize:40;fontname:Arial;textcolor:rgb(0,0,0)" x="1604" y="300">d</text>
        <text style="fontsize:40;fontname:Arial" x="1556" y="180">f</text>
        <text style="fontsize:40;fontname:Arial" x="1652" y="260">c</text>
        <text style="fontsize:40;fontname:Arial" x="1608" y="140">a</text>
        <line x2="1540" y1="348" y2="112" x1="1540" />
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="16" cx="1700" cy="296" />
        <text style="fontsize:28;fontname:Arial" x="1684" y="296">dp</text>
        <rect style="linewidth:W;linecolor:rgb(0,0,255);linestyle:Dot" width="724" x="996" y="112" height="236" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1464" y="128" height="88" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1368" y="128" height="88" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1464" y="216" height="96" />
        <text style="fontsize:40;fontname:Arial" x="1472" y="172">b</text>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="1400" y="284" height="28" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1368" y="216" height="96" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="1400" y="128" height="28" />
        <text style="fontsize:40;fontname:Arial;textcolor:rgb(0,0,0)" x="1372" y="260">e</text>
        <text style="fontsize:40;fontname:Arial" x="1376" y="180">f</text>
        <text style="fontsize:40;fontname:Arial" x="1472" y="260">c</text>
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="16" cx="1520" cy="300" />
        <text style="fontsize:28;fontname:Arial" x="1504" y="300">dp</text>
        <text style="fontsize:40;fontname:Arial;textcolor:rgb(0,0,0)" x="1424" y="300">d</text>
        <text style="fontsize:28;fontname:Arial" x="1404" y="332">AN1</text>
        <text style="fontsize:40;fontname:Arial" x="1420" y="140">a</text>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="1400" y="200" height="32" />
        <text style="fontsize:40;fontname:Arial" x="1424" y="212">g</text>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="1580" y="200" height="32" />
        <text style="fontsize:40;fontname:Arial" x="1604" y="212">g</text>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1288" y="128" height="88" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1192" y="128" height="88" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1288" y="216" height="96" />
        <text style="fontsize:40;fontname:Arial" x="1296" y="172">b</text>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="1224" y="284" height="28" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1192" y="216" height="96" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="1224" y="128" height="28" />
        <text style="fontsize:40;fontname:Arial;textcolor:rgb(0,0,0)" x="1196" y="260">e</text>
        <text style="fontsize:40;fontname:Arial" x="1200" y="180">f</text>
        <text style="fontsize:40;fontname:Arial" x="1296" y="260">c</text>
        <text style="fontsize:40;fontname:Arial" x="1240" y="140">a</text>
        <text style="fontsize:40;fontname:Arial;textcolor:rgb(0,0,0)" x="1244" y="300">d</text>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="1224" y="200" height="32" />
        <text style="fontsize:40;fontname:Arial" x="1248" y="212">g</text>
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="16" cx="1340" cy="296" />
        <text style="fontsize:28;fontname:Arial" x="1324" y="296">dp</text>
        <line x2="1184" y1="348" y2="112" x1="1184" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1112" y="128" height="88" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1016" y="128" height="88" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1112" y="216" height="96" />
        <text style="fontsize:40;fontname:Arial" x="1120" y="172">b</text>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="1048" y="284" height="28" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="32" x="1016" y="216" height="96" />
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="1048" y="128" height="28" />
        <text style="fontsize:40;fontname:Arial;textcolor:rgb(0,0,0)" x="1020" y="260">e</text>
        <text style="fontsize:40;fontname:Arial" x="1024" y="180">f</text>
        <text style="fontsize:40;fontname:Arial" x="1120" y="260">c</text>
        <rect style="fillcolor:rgb(255,0,0);fillstyle:Solid" width="64" x="1048" y="200" height="32" />
        <text style="fontsize:40;fontname:Arial" x="1072" y="212">g</text>
        <circle style="fillcolor:rgb(255,0,0);fillstyle:Solid" r="16" cx="1164" cy="296" />
        <text style="fontsize:28;fontname:Arial" x="1148" y="296">dp</text>
        <text style="fontsize:40;fontname:Arial;textcolor:rgb(0,0,0)" x="1068" y="300">d</text>
        <text style="fontsize:40;fontname:Arial" x="1068" y="140">a</text>
        <text style="fontsize:28;fontname:Arial" x="1052" y="332">AN3</text>
        <text style="fontsize:28;fontname:Arial" x="1228" y="332">AN2</text>
        <line x2="1360" y1="348" y2="112" x1="1360" />
        <text style="alignment:CENTER;fontsize:40;fontname:Times New Roman;textcolor:rgb(255,0,0)" x="1352" y="84">Four-Digit: Seven-Segment LED Display</text>
        <text style="fontsize:28;fontname:Arial" x="1584" y="328">AN0</text>
        <branch name="SW_OK(1),Div(19:18)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:20;fontname:Arial" attrname="Name" x="224" y="112" type="branch" />
            <wire x2="592" y1="112" y2="112" x1="224" />
        </branch>
        <branch name="Div(25)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="112" y="176" type="branch" />
            <wire x2="592" y1="176" y2="176" x1="112" />
        </branch>
        <branch name="SW_OK(0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="160" y="144" type="branch" />
            <wire x2="592" y1="144" y2="144" x1="160" />
        </branch>
        <iomarker fontsize="28" x="1584" y="384" name="AN(3:0)" orien="R0" />
        <iomarker fontsize="28" x="1488" y="48" name="SEGMENT(7:0)" orien="R0" />
        <branch name="Disp_num(31:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="224" y="224" type="branch" />
            <wire x2="592" y1="224" y2="224" x1="224" />
        </branch>
        <branch name="point_out(7:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="192" y="256" type="branch" />
            <wire x2="592" y1="256" y2="256" x1="192" />
        </branch>
        <branch name="LE_out(7:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="176" y="288" type="branch" />
            <wire x2="592" y1="288" y2="288" x1="176" />
        </branch>
        <branch name="LED(7:0)">
            <wire x2="1424" y1="576" y2="576" x1="1408" />
            <wire x2="1600" y1="576" y2="576" x1="1424" />
        </branch>
        <iomarker fontsize="28" x="1600" y="576" name="LED(7:0)" orien="R0" />
        <branch name="CPU2IO(31:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="224" y="672" type="branch" />
            <wire x2="960" y1="672" y2="672" x1="224" />
        </branch>
        <branch name="GPIOF0">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="160" y="608" type="branch" />
            <wire x2="960" y1="608" y2="608" x1="160" />
        </branch>
        <branch name="IO_clk">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="112" y="480" type="branch" />
            <wire x2="960" y1="480" y2="480" x1="112" />
        </branch>
        <branch name="rst">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="96" y="544" type="branch" />
            <wire x2="960" y1="544" y2="544" x1="96" />
        </branch>
        <instance x="592" y="320" name="U61" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" attrname="InstName" x="128" y="-48" type="instance" />
        </instance>
        <instance x="928" y="704" name="U71" orien="R0">
            <attrtext style="fontsize:58;fontname:Arial;textcolor:rgb(255,0,0)" attrname="InstName" x="144" y="-208" type="instance" />
        </instance>
    </sheet>
</drawing>