#include<iostream>
using namespace std;

void swap_value(int,int);
void swap_ref(int &,int &);

int main()
{
	int a,b,ch;

	cout<<"Enter a: ";
	cin>>a;
	cout<<"Enter b: ";
	cin>>b;

	cout<<"Menu\n 1.Swap by Value\n 2.Swap by Reference\n Enter your choice: ";
	cin>>ch;

	switch(ch)
	{
		case 1:swap_value(a,b);
			cout<<"a = "<<a<<"\tb = "<<b<<endl;
			break;
		case 2:swap_ref(a,b);
			cout<<"a = "<<a<<"\tb = "<<b<<endl;
			break;
		default:cout<<"Invalid Choice"<<endl;
			break;
	};

	return 0;
}

void swap_value(int i,int j)
{
	i=i+j;
	j=i-j;
	i=i-j;
}

void swap_ref(int &i,int &j)
{
	i=i+j;
	j=i-j;
	i=i-j;
}