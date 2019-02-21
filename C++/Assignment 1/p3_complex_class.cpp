#include<iostream>
using namespace std;

class Complex
{
	float real;
	float imag;

	public:

	friend Complex addComplex(Complex &,Complex &);

	friend Complex mulComplex(Complex &,Complex &);

	Complex()
	{
		real=imag=0;
	}

	Complex(float x)
	{
		real=imag=x;
	}

	Complex(float r,float i)
	{
		real=r;
		imag=i;
	}

	void display()
	{
		cout<<real<<"+ ("<<imag<<")i"<<endl;
	}


};

Complex addComplex(Complex &a,Complex &b)
{
	Complex temp;
	temp.real=a.real+b.real;
	temp.imag=a.imag+b.imag;
	return temp;
}

Complex mulComplex(Complex &a,Complex &b)
{
	Complex temp;
	temp.real=(a.real*b.real)-(a.imag*b.imag);
	temp.imag=(a.real*b.imag)+(a.imag*b.real);	
	return temp;
}

int main()
{
	Complex c1(5),c2(3,4),c3,c4;

	c3=addComplex(c1,c2);

	c4=mulComplex(c1,c2);

	cout<<"c1+c2 = ";
	c3.display();
	cout<<"c1*c2 = ";
	c4.display();

	return 0;
}

