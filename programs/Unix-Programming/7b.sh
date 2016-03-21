if [ $# -lt 2 ]
then
echo "Error : Insufficient number of arguments"
exit
fi
str=`cat $1 | tr '\n' ' '`
for i in $*
do
echo "In $i file the count is...."
for a in $str
do
echo "word=$a,count=`grep -c "$a" $i `"
done
echo "-------------------"
done

