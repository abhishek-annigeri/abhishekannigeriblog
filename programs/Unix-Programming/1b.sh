temp=IFS
IFS=/
for i in $*
do
if [ -d $i ]
then
cd $i
else
mkdir $i
cd $i
fi
done
IFS=$temp
d=`pwd`
echo "directory is $d"
exit
