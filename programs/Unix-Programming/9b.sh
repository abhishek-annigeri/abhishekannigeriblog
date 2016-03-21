echo "Enter filename"
read file
lines=`wc -l < $file`
echo "File $file has $lines lines..."
count=1
if [ -f temp.txt ]
then
rm temp.txt
fi
while [ $count -le $lines ]
do
lb=1
ub=40
char=0
text=`tail -n+$count $file | head -1`
char=`echo $text | wc -c`
chartemp=$char
if [ $char -le 40 ]
then
echo $text >> temp.txt
else
while [ $char -gt 40 ]
do
t=`echo "$text" | cut -c $lb-$ub`
echo "$tr\\" >> temp.txt
char=`expr $char - 40`
if [ $char -le 40 ]
then
echo "$text" | cut -c $ub-$chartemp >> temp.txt
fi
lb=`expr $lb + 40`
ub=`expr $ub + 40`
done
fi
count=`expr $count + 1`
done
echo "Contents of file after folding are:"
cat temp.txt
exit

