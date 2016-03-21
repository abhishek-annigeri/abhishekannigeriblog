#!/usr/bin/perl
use CGI":standard";
print "content-type:text/html","\n\n";
$count_file="count.txt";
if(open(FILE,"<" . $count_file))
{
$no_access=<FILE>;
close(FILE);
if(open(FILE,">" . $count_file))
{
$no_access++;
print FILE $no_access;
close(FILE);
print"This webpage has been accessed ";
print $no_access;
print " TIMES\n";
}
else
{
print"can't open the data file","\n\n";
print $no_access;
}
}
else
{
print "sorry cant read from file\n";
}
exit(0);
