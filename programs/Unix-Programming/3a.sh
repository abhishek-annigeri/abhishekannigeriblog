echo "enter file name"
read file
if [ -f "$file" ];
then
set -- `ls -l $file`
echo "name of the file : $9"
echo "file permission : $1"
echo "number of link :$2"
echo "username : $3"
echo "owner name : $4"
echo "block size : $5"
echo "date of modification : $6 $7 `date +%Y`"
echo "time of modification  $8"
else
echo "file $file doesnt exist"
fi

