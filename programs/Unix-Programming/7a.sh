clear
hournow=`date | cut -c 12-13`
user=`echo $HOME | cut -d "/" -f4`
case $hournow in
[0-1][0-1]|0[2-9]) echo "Good Morning Mr/Ms : $user" ;;
1[2-5]) echo "Good Afternoon Mr/Ms : $user" ;;
1[6-9]) echo "Good evening Mr/Ms : $user" ;;
esac 
exit

