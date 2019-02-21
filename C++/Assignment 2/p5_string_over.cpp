#include<iostream>
#include<cstring>
using namespace std;

class String
{
	char *str;
	int len;

	public:

	String()
	{
		str=NULL;	
		len=0;
	}

	String(char *s)
	{
		len=strlen(s);
		str=new char[len];
		strcpy(str,s);
	}

	String(String &s)
	{
		len=s.len;
		str=new char[len];
		strcpy(str,s.str);
	}

	friend ostream& operator<<(ostream &,String);
	friend istream& operator >>(istream &,String &);

	String operator+(String);
	char& operator[](int);
	String operator=(String);
	
	~String()
	{ }
};

ostream& operator<<(ostream &cout,String s)
{
	cout<<s.str;
	return cout;
}

istream& operator >>(istream &cin,String &s)
{
	char temp[50];
	scanf("%[^\n]s",temp);
	s.len=strlen(temp);
	s.str=new char[s.len];
	strcpy(s.str,temp);
			
	return cin;
}

String String::operator+(String s)
{
	String temp;
	temp.len=len+s.len;
	temp.str=new char[len];

	strcpy(temp.str,str);
	strcat(temp.str,s.str);

	return temp;
}

char& String::operator[](int n)
{
	try
	{
		if(n<len)
			return str[n];
		else
			throw str[n];
	}
	catch(char e)
	{	
		cout<<"Index out of bound"<<endl;
	}
	
}

String String::operator=(String s)
{
	if(str!=NULL)
		free(str);
				
	len=s.len;
	str= new char[len];
				
	strcpy(str,s.str);
	return *this;
}


int main()
{
	String s1("hello"),s2(s1);
	String s3,s4,s5;

	s3=s1+s2;

	cout<<"Enter s4: ";
	cin>>s4;
	
	s5=s4+s1;
	

	cout<<endl<<"s1 = "<<s1<<endl;
	cout<<endl<<"s2 = "<<s2<<endl;
	cout<<endl<<"s3 = s1 + s2 = "<<s3<<endl;
	cout<<endl<<"s4 = "<<s4<<endl;
	cout<<endl<<"s1[3] = "<<s1[3]<<endl;
	cout<<endl<<"s5 = s4 = "<<s5<<endl;

	return 0;
}