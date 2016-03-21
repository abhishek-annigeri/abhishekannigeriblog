clear
if [ $# -ne 1 ]
then
echo "insufficient arguments"
exit
fi
dir=mydir
if [ -d $dir ]
then
echo "directory $dir already exists.. Not creating again"
else
mkdir $dir
fi
echo "the files matching the pattern $1 are :"
ls *$1* > filenames.txt
cat filenames.txt
echo "the contents of files are:"
for i in `cat filenames.txt`
do
echo "filename : $i"
echo "_________________________"
cat $i
echo "_________________________"
cp $i ./mydir/$i
done
echo the files copied into ~/mydir
cd mydir
ls -l
