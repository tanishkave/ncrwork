#include<iostream>
using namespace std;

class Distance2;

class Distance1
{
	int m;
	int cm;

	public:

	friend Distance1 addinm(Distance1 d1,Distance2 d2);
	friend Distance2 addinft(Distance1 d1,Distance2 d2);

	friend void check_m(Distance1 *);

	Distance1()
	{
		m=cm=0;
	}

	Distance1(int m1,int cm1)
	{
		m=m1;
		cm=cm1;
		check_m(this);
	}

	void display()
	{
		cout<<"Meters: "<<m;
		cout<<"\tCentimeters: "<<cm<<endl;
	}
};


class Distance2
{
	int ft;
	int in;
	
	public:
	
	friend Distance1 addinm(Distance1 d1,Distance2 d2);
	friend Distance2 addinft(Distance1 d1,Distance2 d2);

	friend void check_ft(Distance2 *);

	Distance2()
	{
		ft=in=0;
	}

	Distance2(int ft1,int in1)
	{
		ft=ft1;
		in=in1;
		check_ft(this);
	}

	void display()
	{
		cout<<"Feet: "<<ft;
		cout<<"\tInches: "<<in<<endl;
	}
};

Distance1 addinm(Distance1 d1,Distance2 d2)
{
	d1.m=d1.m+((d2.ft*12*2.54)/100);
	d1.cm=d1.cm+(d2.in*2.54);
	check_m(&d1);
	return d1;
}

Distance2 addinft(Distance1 d1,Distance2 d2)
{
	d2.ft=d2.ft+(d1.m*100/(12*2.54));
	d2.in=d2.in+(d1.cm/2.54);
	check_ft(&d2);
	return d2;
}

void check_m(Distance1 *d)
{
	if(d->cm>100)
	{
		d->m+=d->cm/100;
		d->cm=d->cm%100;
	}
}

void check_ft(Distance2 *d)
{
	if(d->in>12)
	{
		d->ft+=d->in/12;
		d->in=d->in%12;
	}
}


int main()
{
	Distance1 a1(2,101),a2;
	Distance2 b1(3,5),b2;

	a2=addinm(a1,b1);

	b2=addinft(a1,b1);

	cout<<"a1 = ";
	a1.display();
	
	cout<<"b1 = ";
	b1.display();

	cout<<"a1 + b1 (in Distance1) = ";
	a2.display();

	cout<<"a1 + b1 (in Distance2) = ";
	b2.display();
	
	return 0;
}
	
//Convert into proper format after adding. i.e 12 inches = 1ft and 100cm = 1m