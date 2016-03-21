#!/usr/bin/perl
use CGI;
$q=new CGI;
@last_day=$q->cookie('last_time');
($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst)=localtime;
$day_of_week_name=(qw(Sunday Monday Tuesday Thrusday Friday Saturday))[$wday];
$month_name=(qw(Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dem))[$mon];
@dayDetails=($day_of_week,$mday,$month_name);
$daycookie=$q->cookie(-name=>'last_time',-value=>\@dayDetails,-expires=>'+2d');
print $q->header(-cookie=>$daycookie);
print $q->start_html("This is last visit cookie.pl");
if(scalar(@last_day)==0)
{
print "This must be your first visit to this site!<br/>";}
else
{
($day_of_week_name,$day_of_month,$month_name)=@last_day;
print "Your last visit was on $day_of_week_name $month_name $day_of_month";
}
print $q->end_html
