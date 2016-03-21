if [ $# -eq 0 ];
then
echo "No arguments entered"
exit
elif [ $# -lt 2 ];
then
echo "Enter 2 file names to compare"
exit
else
f1=`ls -l $1|cut -c 2-10`
f2=`ls -l $2|cut -c 2-10`
if [ "$f1" = "$f2" ];
then
echo "file permission are identical"
echo "file permission of 1st file is : $f1"
echo "file permission of 2nd file is : $f2"
else
echo "file permission are not identical"
echo "file permission of 1st file $1 is : $f1"
echo "file permission of 2nd file $2 is : $f2"
fi
fi
