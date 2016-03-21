clear
if [ $# -ne 1 ]
then
echo "Invalid number of arguments"
exit
fi 
if [ -d $1 ]
then
cd $1
echo "The directory value is $1"
set -- `ls -lR|grep -v "^d"|sort -k 5 -rn`
echo "Size of file $9 is $5 block"
else
echo "Invalid directory name" 
fi
exit
