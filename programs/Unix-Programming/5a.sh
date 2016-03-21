clear
echo "Enter the file name to find the creation time"
read filename
if [ -f $filename ]
then
set -- `ls -l $filename`
echo "file $filename was created on $6 $7 $8"
else
echo "File $filename doesn't exist in current directory"
fi

