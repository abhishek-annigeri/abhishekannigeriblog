<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
xmlns="http://www.w3.org/1999/xhtml">

<xsl:template match="/">

<span style="font-size:20pt;color:blue;"> ==> </span>
<span><xsl:value-of select="stud/title"/><br /></span>

<span style="font-size:20pt;color:blue;">USN: </span>
<span><xsl:value-of select="stud/usn"/><br /></span>

<span style="font-size:20pt;color:blue;"> Name </span>
<span><xsl:value-of select="stud/name"/><br /></span>

<span style="font-size:20pt;color:blue;"> Branch </span>
<span><xsl:value-of select="stud/branch"/><br /></span>

<span style="font-size:20pt;color:blue;"> YOJ </span>
<span><xsl:value-of select="stud/yoj"/><br /></span>

<span style="font-size:20pt;color:blue;"> College </span>
<span><xsl:value-of select="stud/coll"/><br /></span>

</xsl:template>
</xsl:stylesheet>
