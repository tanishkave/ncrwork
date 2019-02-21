#include<iostream>
using namespace std;

inline float add(float a,float b)
{
	return a+b;
}

inline float sub(float a,float b)
{
	return a-b;
}

inline float div(float a,float b)
{
	return a/b;
}

inline int modu(int a,int b)
{
	return a%b;
}

inline double mul(float a,float b)
{
	return a*b;
}

int main()
{
	float a,b;

	cout<<"Enter a: ";
	cin>>a;
	cout<<"Enter b: ";
	cin>>b;

	cout<<"a + b = "<<add(a,b)<<endl;
	cout<<"a - b = "<<sub(a,b)<<endl;
	cout<<"a x b = "<<mul(a,b)<<endl;
	cout<<"a / b = "<<div(a,b)<<endl;
	cout<<"a % b = "<<modu(a,b)<<endl;
	
	return 0;
}