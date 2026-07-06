<xsl:stylesheet
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  version="1.0">
  
  <xsl:output method="html"/>
  
  <xsl:template match="/">
<b>
  <xsl:text>Current iMPACT Usage Statistics.</xsl:text>
  <br></br>
  <xsl:text>Copyright (c) 1995-2010 Xilinx, Inc. All rights reserved.</xsl:text>
</b>
  <br></br>
  <br></br>
  <xsl:text>This page displays the current iMPACT device usage statistics that will be sent to Xilinx using WebTalk.</xsl:text>

<table width = "100%" border="1" CELLSPACING="0" cols="50% 50%">
    <xsl:for-each select="document/application/section">
<tr>
<th COLSPAN="2" BGCOLOR="#99CCFF"><xsl:value-of select="@name"/></th>
      
</tr>
    		<xsl:for-each select="property">
<tr>
	<td><xsl:value-of select="@name"/></td>

	<td><xsl:value-of select="@value"/></td>
</tr>

        
        </xsl:for-each>

        <xsl:for-each select="item">
<tr>
          <td COLSPAN="2" BGCOLOR="#FFFF99"><b><xsl:value-of select="@name"/></b></td>
</tr>
          <xsl:value-of select="@value"/>
          <xsl:for-each select="property">    
<tr>
      			<td><xsl:value-of select="@name"/></td>
      			<td><xsl:value-of select="@value"/>&#x20;</td>
</tr>
      			 
    			</xsl:for-each>
          
    		</xsl:for-each>
    </xsl:for-each>
</table>
  </xsl:template>

</xsl:stylesheet>
      
      <!--
      <xsl:if test="position() != last()"> <h1><xsl:text> </xsl:text></h1></xsl:if>
      -->
