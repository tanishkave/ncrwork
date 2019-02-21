#include<iostream>
using namespace std;

class Time;
void check_time(Time *);
class Time
{
	int hr;
	int min;
	int sec;

	public:
	
	friend void check_time(Time *);

	Time()
	{
		hr=min=sec=0;
		check_time(this);
	}

	Time(int h,int m,int s)
	{
		hr=h;
		min=m;
		sec=s;	
		check_time(this);	
	}

	void display_time()
	{
		cout<<"Time:\t"<<hr<<":"<<min<<":"<<sec<<endl;
	}

	void add_time(Time t1,Time t2)
	{
		hr=t1.hr+t2.hr;
		min=t1.min+t2.min;
		sec=t1.sec+t2.sec;	
		check_time(this);
	}	

};

void check_time(Time *t)
{
	if(t->sec>60)
	{
		t->min+=t->sec/60;
		t->sec=t->sec%60;			
	}

	if(t->min>60)
	{
		t->hr+=t->min/60;
		t->min=t->min%60;			
	}

	if(24<=t->hr)
	{
		t->hr=t->hr%24;
	}
}

int main()
{
	Time t1(4,20,12),t2(23,5,11),t3;
	
	t3.add_time(t1,t2);
	
	t3.display_time();

	return 0;
}