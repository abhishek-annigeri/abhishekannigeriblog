if [ $# -eq 0 ];
then
echo "no arguments"
exit
fi

for nam in $*
do
y=`grep -w "$nam" /etc/passwd|cut -d ":" -f1`
if [ -n "$y" ]
then
if [ "$y" = "$nam" ]
then
x=`grep "$nam" /etc/passwd|cut -d ":" -f6`
echo "home directory of $nam is $x"
else
echo "$nam doesnt have an account"
fi
else
echo "$nam doent have an account"
fi
done 
