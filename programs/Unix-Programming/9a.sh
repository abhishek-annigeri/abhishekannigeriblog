if [ $# -ne 3 ]
then
echo "Error:Invalid number of arguments..."
exit
fi
if [ $2 -gt $3 ]
then
echo "Error:Invalid range of values.."
exit
fi
l=`expr $3 - $2 + 1`
cat $1 | tail -n+$2 | head -$l
exit

