function validate(sem)

{

var r;

var reg=/^[1-4][A-Z][A-Z][0-9][0-9][A-Z][A-Z][A-Z][0-9][0-9]$/;

if(!sem.value.match(reg) || sem.value.length==0)

{

alert("Invalid !");

return false;

}

else

{

var d=new Date();

var y=d.getFullYear();

var m=d.getMonth();

var sm=20+sem.value[3]+sem.value[4];

res=y-sm;

if(m<7)

{

r=res*2;

//alert("Semester="+r);

}

else

{

r=res*2+1;

//alert("Semester="+r);

}

if(r<=6)

alert("Valid Semester="+r);

else

alert("Invalid Semester="+r);

}

}