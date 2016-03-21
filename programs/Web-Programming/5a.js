function validate(usn)
{
var reg=/^[1-4][A-Z][A-Z][0-9][0-9][A-Z][A-Z][0-9][0-9][0-9]$/;
if(!usn.value.match(reg) || usn.value.length==0)
{
alert("Invalid USN");
return false;
}
else
alert("Valid USN");
}
