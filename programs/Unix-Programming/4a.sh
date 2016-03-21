clear
if [ $# -eq 0 ]
then
echo "Error:Insufficient arguments" 
exit
fi
for i in $*
do
if [ -f $i ]
then
echo "Its valid file"
echo "Contents of file before converting are:"
cat $i
echo "contents of file after converting are:"
tr '[a-z]' '[A-Z]' < $i | tee $i
k=`ls $i | tr '[a-z]' '[A-Z]'`
mv $i $k
echo file $i renamed as $k
echo "deirectory listing"
ls
else
echo "File doesn't exist"
fi
done
