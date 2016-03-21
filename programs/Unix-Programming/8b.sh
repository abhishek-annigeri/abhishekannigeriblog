echo "Enter the login name of the user"
read user
time=0
who | grep "$user" > /dev/null
if [ $? -eq 0 ]
then
echo "$user has already logged in.. give a different username"
exit
fi
while [ true ] 
do
sleep 1
time=`expr $time + 1`
who | grep "$user" > /dev/null
if [ $? -eq 0 ]
then
echo "$user logged in $time seconds..."
exit
fi
if [ $time -eq 61 ] 
then
echo "$user did not logged in within 1 min"
exit
fi
done

