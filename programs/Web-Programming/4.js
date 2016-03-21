var r,low,up,i,res;

  r=parseInt(prompt("enter the range"));

  low=parseInt(prompt("enter the low limit"));

  up=prompt("enter the upper limit");

  res="";
  
for(i=1;i<=r;i++)

  {

 var random=Math.floor(Math.random()*(up-low+1)+low);
 
res+=random+"<br />";

 }

 document.getElementById("xy").innerHTML=res;
 

