echo "enter the login name of a user"
read user
count=`who | grep -wo "$user" | wc -l`
if [ $count -eq 0 ]
then
echo "Invalid user"
exit
fi
if [ $count -gt 1 ]
then 
echo "multiple login"
exit
fi
lt=`who | tr -s " " | grep "$user" | cut -d " " -f4`
lh=`echo $lt | cut -d ":" -f1`
lm=`echo $lt | cut -d ":" -f2`
ch=`date +%H`
cm=`date +%M`
if [ $lh = $ch ]
then
hr=0
if [ $cm -gt $lm ]
then
min=`expr $cm - $lm`
else
min=`expr $cm - $lm + 60`
fi
echo "The user is logged in from $hr hour $min minutes"
exit
fi

if [ $cm -gt $lm ]
then
min=`expr $cm-$lm`
hr=`expr $ch-$lh`
else
min=`expr $cm - $lm + 60`
hr=`expr $ch - $lh - 1`
fi
echo "The user is logged in from "$hr" hours "$min" minutes"
exit
