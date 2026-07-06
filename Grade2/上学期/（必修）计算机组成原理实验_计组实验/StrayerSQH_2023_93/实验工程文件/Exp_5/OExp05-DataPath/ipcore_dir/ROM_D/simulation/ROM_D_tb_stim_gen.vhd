  --------------------------------------------------------------------------------
--
-- DIST MEM GEN Core - Stimulus Generator For ROM Configuration
--
--------------------------------------------------------------------------------
--
-- (c) Copyright 2006_3010 Xilinx, Inc. All rights reserved.
--
-- This file contains confidential and proprietary information
-- of Xilinx, Inc. and is protected under U.S. and
-- international copyright and other intellectual property
-- laws.
--
-- DISCLAIMER
-- This disclaimer is not a license and does not grant any
-- rights to the materials distributed herewith. Except as
-- otherwise provided in a valid license issued to you by
-- Xilinx, and to the maximum extent permitted by applicable
-- law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
-- WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
-- AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
-- BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
-- INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
-- (2) Xilinx shall not be liable (whether in contract or tort,
-- including negligence, or under any other theory of
-- liability) for any loss or damage of any kind or nature
-- related to, arising under or in connection with these
-- materials, including for any direct, or any indirect,
-- special, incidental, or consequential loss or damage
-- (including loss of data, profits, goodwill, or any type of
-- loss or damage suffered as a result of any action brought
-- by a third party) even if such damage or loss was
-- reasonably foreseeable or Xilinx had been advised of the
-- possibility of the same.
--
-- CRITICAL APPLICATIONS
-- Xilinx products are not designed or intended to be fail-
-- safe, or for use in any application requiring fail-safe
-- performance, such as life-support or safety devices or
-- systems, Class III medical devices, nuclear facilities,
-- applications related to the deployment of airbags, or any
-- other applications that could lead to death, personal
-- injury, or severe property or environmental damage
-- (individually and collectively, "Critical
-- Applications"). Customer assumes the sole risk and
-- liability of any use of Xilinx products in Critical
-- Applications, subject only to applicable laws and
-- regulations governing limitations on product liability.
--
-- THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
-- PART OF THIS FILE AT ALL TIMES.

--------------------------------------------------------------------------------
--
-- Filename: ROM_D_tb_stim_gen.vhd
--
-- Description:
--  Stimulus Generation For ROM
--
--------------------------------------------------------------------------------
-- Author: IP Solutions Division
--
-- History: Sep 12, 2011 - First Release
--------------------------------------------------------------------------------
--
--------------------------------------------------------------------------------
-- Library Declarations
--------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_MISC.ALL;

LIBRARY work;
USE work.ALL;
USE work.ROM_D_TB_PKG.ALL;


ENTITY REGISTER_LOGIC_ROM IS
  PORT(
    Q   : OUT STD_LOGIC;
    CLK   : IN STD_LOGIC;
    RST : IN STD_LOGIC;
    D   : IN STD_LOGIC
    );
END REGISTER_LOGIC_ROM;

ARCHITECTURE REGISTER_ARCH OF REGISTER_LOGIC_ROM IS
  SIGNAL Q_O : STD_LOGIC :='0';
BEGIN
  Q <= Q_O;
FF_BEH: PROCESS(CLK)
BEGIN
  IF(RISING_EDGE(CLK)) THEN
    IF(RST /= '0' ) THEN
	   Q_O <= '0';
    ELSE
      Q_O <= D;
    END IF;
  END IF;
END PROCESS;
END REGISTER_ARCH;

LIBRARY STD;
USE STD.TEXTIO.ALL;

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
--USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_MISC.ALL;

 LIBRARY work;
USE work.ALL;
USE work.ROM_D_TB_PKG.ALL;

ENTITY ROM_D_TB_STIM_GEN IS
  GENERIC ( C_ROM_SYNTH : INTEGER := 0
      );
  PORT (
    CLK : IN STD_LOGIC;
    RST : IN STD_LOGIC;
    A   : OUT  STD_LOGIC_VECTOR(10-1 downto 0) := (OTHERS => '0');
    DATA_IN : IN STD_LOGIC_VECTOR (31 DOWNTO 0);   --OUTPUT VECTOR 
        
    STATUS : OUT STD_LOGIC:= '0'
    	  );
END ROM_D_TB_STIM_GEN;


ARCHITECTURE BEHAVIORAL OF ROM_D_TB_STIM_GEN IS

  FUNCTION std_logic_vector_len(
    hex_str       : STD_LOGIC_VECTOR;
    return_width  : INTEGER)
  RETURN STD_LOGIC_VECTOR IS
    VARIABLE tmp   : STD_LOGIC_VECTOR(return_width DOWNTO 0) := (OTHERS => '0');
    VARIABLE tmp_z : STD_LOGIC_VECTOR(return_width-(hex_str'LENGTH) DOWNTO 0) := (OTHERS => '0');

  BEGIN
    tmp := tmp_z & hex_str;
    RETURN tmp(return_width-1 DOWNTO 0);
  END std_logic_vector_len;

  CONSTANT ZERO : STD_LOGIC_VECTOR(31 DOWNTO 0) := (OTHERS => '0');
  SIGNAL READ_ADDR_INT : STD_LOGIC_VECTOR(9 DOWNTO 0) := (OTHERS => '0');
  SIGNAL READ_ADDR : STD_LOGIC_VECTOR(31 DOWNTO 0) := (OTHERS => '0');
  SIGNAL CHECK_READ_ADDR : STD_LOGIC_VECTOR(31 DOWNTO 0) := (OTHERS => '0');
  SIGNAL EXPECTED_DATA : STD_LOGIC_VECTOR(31 DOWNTO 0) := (OTHERS => '0');
  SIGNAL DO_READ : STD_LOGIC := '0';
  SIGNAL CHECK_DATA : STD_LOGIC_VECTOR(2 DOWNTO 0) := (OTHERS => '0');
  CONSTANT DEFAULT_DATA  : STD_LOGIC_VECTOR(31 DOWNTO 0):= std_logic_vector_len("0",32);

BEGIN

SYNTH_COE:  IF(C_ROM_SYNTH =0 ) GENERATE

type mem_type is array (1023 downto 0) of std_logic_vector(31 downto 0);

  FUNCTION bit_to_sl(input: BIT) RETURN STD_LOGIC IS
    VARIABLE temp_return : STD_LOGIC;
  BEGIN
    IF(input = '0') THEN
      temp_return := '0';
    ELSE
      temp_return := '1';
    END IF;
    RETURN temp_return;
  END bit_to_sl;

  function char_to_std_logic (
    char : in character)
  return std_logic is
    variable data : std_logic;
  begin
    if char = '0' then
      data := '0';
    elsif char = '1' then
      data := '1';
    elsif char = 'X' then
      data := 'X';
    else
      assert false
      report "character which is not '0', '1' or 'X'."
      severity warning;
      data := 'U';
    end if;

      return data;

  end char_to_std_logic;

impure FUNCTION init_memory(
  C_USE_DEFAULT_DATA : INTEGER;
  C_LOAD_INIT_FILE : INTEGER ;
  C_INIT_FILE_NAME : STRING ;
  DEFAULT_DATA   :  STD_LOGIC_VECTOR(31 DOWNTO 0);
  width : INTEGER;
  depth         : INTEGER)
RETURN mem_type IS
  VARIABLE init_return   : mem_type := (OTHERS => (OTHERS => '0'));
  FILE     init_file     : TEXT;
  VARIABLE mem_vector    : BIT_VECTOR(width-1 DOWNTO 0);
  VARIABLE bitline     : LINE;
  variable bitsgood    : boolean := true;
  variable bitchar     : character;
  VARIABLE i             : INTEGER;
  VARIABLE j             : INTEGER;
BEGIN

  --Display output message indicating that the behavioral model is being
  --initialized
  ASSERT (NOT (C_USE_DEFAULT_DATA=1 OR C_LOAD_INIT_FILE=1)) REPORT " Distributed Memory Generator CORE Generator module loading initial data..." SEVERITY NOTE;

  -- Setup the default data
  -- Default data is with respect to write_port_A and may be wider
  -- or narrower than init_return width.  The following loops map
  -- default data into the memory
  IF (C_USE_DEFAULT_DATA=1) THEN
    FOR i IN 0 TO depth-1 LOOP
      init_return(i) := DEFAULT_DATA;
    END LOOP;
  END IF;

  -- Read in the .mif file
  -- The init data is formatted with respect to write port A dimensions.
  -- The init_return vector is formatted with respect to minimum width and
  -- maximum depth; the following loops map the .mif file into the memory
  IF (C_LOAD_INIT_FILE=1) THEN
    file_open(init_file, C_INIT_FILE_NAME, read_mode);
    i := 0;
    WHILE (i < depth AND NOT endfile(init_file)) LOOP
      mem_vector := (OTHERS => '0');
      readline(init_file, bitline);
--     read(file_buffer, mem_vector(file_buffer'LENGTH-1 DOWNTO 0));

      FOR j IN 0 TO width-1 LOOP
		  read(bitline,bitchar,bitsgood);
        init_return(i)(width-1-j) := char_to_std_logic(bitchar);
      END LOOP;
      i := i + 1;
    END LOOP;
      file_close(init_file);
  END IF;
  RETURN init_return;

END FUNCTION;


--***************************************************************
-- convert bit to STD_LOGIC
--***************************************************************

constant c_init : mem_type := init_memory(1,
                                          1,
										            "ROM_D.mif",
                                          DEFAULT_DATA,
                                          32,
                                          1024);


constant rom : mem_type := c_init;
BEGIN

 EXPECTED_DATA <= rom(conv_integer(unsigned(check_read_addr)));

 CHECKER_RD_AGEN_INST:ENTITY work.ROM_D_TB_AGEN
   GENERIC MAP( C_MAX_DEPTH =>1024 )

   PORT MAP(
     CLK => CLK,
     RST => RST,
     EN  => CHECK_DATA(2),
     LOAD => '0',
     LOAD_VALUE => ZERO,
     ADDR_OUT => check_read_addr
     );
 

  PROCESS(CLK)
  BEGIN
    IF(RISING_EDGE(CLK)) THEN
      IF(CHECK_DATA(2) ='1') THEN
    	  IF(EXPECTED_DATA = DATA_IN) THEN
	       STATUS<='0';
    	  ELSE
	       STATUS <= '1';
     	  END IF;
      END IF;
	 END IF;
  END PROCESS;
END GENERATE; 
-- Simulatable ROM 

--Synthesizable ROM
SYNTH_CHECKER: IF(C_ROM_SYNTH = 1) GENERATE
  PROCESS(CLK)
  BEGIN
    IF(RISING_EDGE(CLK)) THEN
	   IF(CHECK_DATA(2)='1') THEN
		  IF(DATA_IN=DEFAULT_DATA) THEN
		    STATUS <= '0';
	     ELSE
		    STATUS <= '1';
		  END IF;
	   END IF;
	 END IF;
  END PROCESS;

END GENERATE;


  READ_ADDR_INT(9 DOWNTO 0) <= READ_ADDR(9 DOWNTO 0);
  A <= READ_ADDR_INT ;

  CHECK_DATA(0) <= DO_READ;

  RD_AGEN_INST:ENTITY work.ROM_D_TB_AGEN
    GENERIC MAP( C_MAX_DEPTH => 1024 )

    PORT MAP(
      CLK => CLK,
     	RST => RST,
      EN  => DO_READ,
      LOAD => '0',
     	LOAD_VALUE => ZERO,
    	ADDR_OUT => READ_ADDR
      );

RD_PROCESS: PROCESS (CLK)
BEGIN
  IF (RISING_EDGE(CLK)) THEN
    IF(RST='1') THEN
      DO_READ <= '0';
	 ELSE
      DO_READ <= '1';
	 END IF;
  END IF;
END PROCESS;


BEGIN_EN_REG: FOR I IN 0 TO 2 GENERATE
BEGIN
  DFF_RIGHT: IF I=0 GENERATE
  BEGIN
    SHIFT_INST_0: ENTITY work.REGISTER_LOGIC_ROM
      PORT MAP(
        Q   => CHECK_DATA(1),
        CLK => CLK,
        RST => RST,
        D   => CHECK_DATA(0)
      );
  END GENERATE DFF_RIGHT;
  DFF_CE_OTHERS: IF ((I>0) AND (I<2)) GENERATE
  BEGIN
    SHIFT_INST: ENTITY work.REGISTER_LOGIC_ROM
      PORT MAP(
        Q   => CHECK_DATA(I+1),
        CLK => CLK,
        RST => RST,
        D   => CHECK_DATA(I)
        );
  END GENERATE DFF_CE_OTHERS;
END GENERATE BEGIN_EN_REG;

END ARCHITECTURE;
