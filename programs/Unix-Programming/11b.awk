BEGIN{
printf "Enter the basic pay: Rs:"
getline bp < "/dev/tty"
if(bp<10000)
{
hra=0.15*bp
da=0.45*bp
}
else
{
hra=0.2*bp
da=0.5*bp
}
gs=bp+hra+da
printf "Hra= %.2f\n",hra
printf "DA=%.2f\n",da
printf "Gross Salary = Rs. %.2f\n",gs}
