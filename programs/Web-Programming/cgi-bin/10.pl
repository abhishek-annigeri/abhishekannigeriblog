#!/usr/bin/perl
print"content-type:text/html","\n\n";
print"<html>
<body><h3>About the server</h3><hr>
Server Name:$ENV{'SERVER_NAME'}<br/>
Server Port:$ENV{'SERVER_PORT'}<br/>
Server Software:$ENV{'SERVER_SOFTWARE'}<br/>
Server Protocol:$ENV{'SERVER_PROTOCOL'}<br/>
CGI VERSION:$ENV{'GATEWAY_INTERFACE'}<br/>
<hr></body></html>";

