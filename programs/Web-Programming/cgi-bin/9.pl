#!/usr/bin/perl
print"content-type:text/html\n\n";
print("<center><h1>RV College of Enginnering</h1></center>");
print("<center><h2>Department of MCA</h2></center>");
print("<center><h3>Course Details");
@class=("Web technology","Introduction to unix","operating system");
print("the subjects for mca are:");
print("<br/>");
foreach $i(@class){
print "$i,";
}
print("<br/>");
print"Adding some more extra classes for the day\n";
print("<br/>");
@moreclass=("Seminar","c programming","discrete maths");
unshift(@class,@moreclass);
foreach $i(@class){
print "$i";
print("<br/>");
print("<br/>");
}

$x=scalar(@class);
print("<br/>");
print"The length of array is : $x\n\n";
print("<br/>");
$elt=shift(@class);
print"the first class is $elt\n\n";
print("<br/>");
$elt=pop(@class);
print("<br/>");
print"The last class is $elt\n\n";
