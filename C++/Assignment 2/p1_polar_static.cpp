#include<iostream>
using namespace std;

class Polar
{
	float angle;
	float radius;
	
	public:
	
	static int count;

	Polar()
	{
		angle=radius=0;
		count++;
	}

	Polar(float a,float r)
	{
		angle=a;
		radius=r;
		count++;
	}

	static void check_count()
	{
		cout<<"Active objects = "<<count<<endl;
	}

	void increase_active()
	{
		Polar p;
		cout<<"\nInside increase_active():\n";
		check_count();
	}

	~Polar()
	{
		count--;
	}
};

int Polar::count=0;

int main()
{
	Polar p1,p2(45,7);

	cout<<"\nAfter creating p1,p2:\n";
	Polar::check_count();

	Polar p3(60,3);
	
	cout<<"\nAfter creating p3:\n";
	Polar::check_count();
	
	p1.increase_active();
	
	cout<<"\nAfter exiting increase_active:\n";
	Polar::check_count();
	

	return 0;
}