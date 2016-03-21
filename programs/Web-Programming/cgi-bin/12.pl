#!/usr/bin/perl

print "content-type:text/html","\n\n";

use CGI":standard";

$input=param("name");

print("<html<body><h3>Hi,$input</h3>");

my@msg=("Good","Welcome","Fine","Hello");

print ("<h3>The message received is :</h3>");

print "$msg[int rand scalar@msg]";

print"</body></html>";
