{a[n++]=$0}
END{for(i=0;i<n;i++){
flag=0;
for(j=0;j<i;j++)
{
if(a[i] == a[j])
{
flag=1;
break;
}
}
if(flag == 0)
printf"%s\n",a[i]
}
}
