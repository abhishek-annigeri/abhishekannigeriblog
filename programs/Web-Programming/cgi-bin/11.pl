#!/usr/bin/perl
print"content-type:text/html","\n\n";
use CGI":standard";
my($s,$m,$h)=localtime(time);
print("\n\n");
print"The current time is :";
print"$h:$m:$s";
