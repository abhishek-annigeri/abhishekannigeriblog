var f1=0,f2=1,f3,i;

var res="Fibonacci series"+"\n";

alert("Welcome to javascript");

var n=parseInt(prompt("enter a number"));


if(n==0)

{

res+=f1+"<br />";

}

else if(n==1)

{

res+=f1+"<br />"+f2+"<br />";

}

else

{

res+=f1+"<br />"+f2+"<br />";

for(i=2;i<n;i++)

{

f3=f1+f2;

res+=f3+"<br />";

f1=f2;
f2=f3;
}

}

//alert(res);

document.getElementById("xy").innerHTML=res;
