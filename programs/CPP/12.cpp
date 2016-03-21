#include<iostream>
#include<cstring>
using namespace std;
class String
{
public : char str[20];
String()
{
strcpy(str," ");
}
String(const char *s)
{
strcpy(str,s);
}

String operator+(String ss)
{
String temp;
strcpy(temp.str,str);
strcat(temp.str," ");
strcat(temp.str,ss.str);
return temp;
}
friend ostream& operator <<(ostream&,String);
};

ostream& operator <<(ostream& o,String ss)
{
o<<ss.str;
return o;
}

int main()
{
String s1="VTU";
String s2="BELGAUM";
cout<<"\n1st String is\n"<<s1;
cout<<"\n2nd String is:\n"<<s2;
String s3=s1+s2;
cout<<"\nConcat of 2 Strings : "<<s3<<endl;
return 0;
}
