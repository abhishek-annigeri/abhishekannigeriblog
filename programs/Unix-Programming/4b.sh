clear
if [ $# -eq 1 ]
then
tm=`pwd`
echo "Directory not given using pwd:$tm"
else
tm=$2
echo "Searching from the giving directory : $tm"
fi
t1=`ls -aliR | grep "$1" | cut -d " " -f1 | head -1`
echo "the linked files are"
ls -liaR $tm | grep "$t1"
