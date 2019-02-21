#include<iostream>
using namespace std;

class Complex
{
	float real;
	float imag;

	public:

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

	Complex(Complex &c)
	{
		real=c.real;
		imag=c.imag;
	}
	
	/*void display()
	{
		cout<<real<<"+ ("<<imag<<")i"<<endl;
	}*/

	friend ostream & operator<< (ostream &,Complex);
	
	friend istream & operator>> (istream &,Complex &);

	Complex operator + (Complex);

	Complex operator -(Complex);

	Complex operator -();

	Complex operator ++ (); 

 	Complex operator ++(int);
	
	Complex operator ()(float,float);
	
	Complex* operator ->();

	Complex operator,(Complex);

	Complex operator=(Complex);

	~Complex()
	{
		//cout<<endl<<"Destructor Called"<<endl;
	}

};

ostream & operator<< (ostream &cout,Complex c)
{
	cout<<c.real<<"+ ("<<c.imag<<")i"<<endl;
	return cout;
}
	
istream & operator>> (istream &cin,Complex &c)
{
	cout<<"Enter Real: ";
	cin>>c.real;
	cout<<"Enter Imaginary: ";
	cin>>c.imag;
	
	return cin;
}

Complex Complex::operator +(Complex a)
{
	Complex temp;
	temp.real=real+a.real;
	temp.imag=imag+a.imag;
	return temp;
}

Complex Complex::operator -(Complex a)
{
	Complex temp;
	temp.real=real-a.real;
	temp.imag=imag-a.imag;
	return temp;
}

Complex Complex::operator -()
{
	Complex temp;
	temp.real=-real;
	temp.imag=-imag;
	return temp;
}

Complex Complex::operator++() 
{
	return (Complex(real++, imag++));
}
	
Complex Complex::operator++(int x)
{
	Complex temp;
	temp.real = ++real;
	temp.imag = ++imag;
	return temp;
}


Complex Complex::operator ()(float i,float j)
{
	real=i;
	imag=j;
	return *this;
}

Complex* Complex::operator ->()
{
	return this;
}

Complex Complex::operator,(Complex c)
{
	return c;
}

Complex Complex::operator=(Complex c)
{
	real=c.real;
	imag=c.imag;	
	return *this;
}

int main()
{
	Complex c1(5),c2(3,4),c3,c4,c5;

	c3=c1+c2;

	c4=c1-c2;

	cout<<endl<<"c1+c2 = "<<c3<<endl;
	cout<<endl<<"c1-c2 = "<<c4<<endl;
	cout<<endl<<"-c1 = "<<-c1<<endl;
	cout<<endl<<"c1++ = "<<c1++<<endl;
	cout<<endl<<"++c1 = "<<++c1<<endl;
	
	cout<<endl<<"c5(7,3) = "<<c5(7,3)<<endl;
	cout<<endl<<"c4 = c5 = "<<c4<<endl;
	
	return 0;
}

