BEGIN{system("clear");
da="312831303130313130313031"
mo="JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC"
mm=substr(ARGV[1],1,2)
dd=substr(ARGV[1],4,2)
yy=substr(ARGV[1],7,4)
if( dd > substr(da,2*mm-1,2) || (mm > 12) || ARGC!=2 )
print"INVALID DATE"
else
printf "The day is %d\n The month is %s\n The year is %d\n",dd,substr(mo,3*mm-2,3),yy
}
