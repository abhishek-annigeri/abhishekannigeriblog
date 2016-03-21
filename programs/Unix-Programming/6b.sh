clear
if [ -f outfile ]
then
rm outfile
fi
for i in `ls`
do
leng=`expr "$i" : '.*'`
if [ $leng -ge 10 ]
then
echo $i >> outfile
fi
done
echo "the file names having more than 10 characters are:"
cat outfile

