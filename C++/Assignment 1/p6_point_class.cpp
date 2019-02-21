#include<iostream>
#include<cmath>
using namespace std;

class Point
{
	int x;
	int y;

	public:

	friend float distance(Point &,Point &);

	Point()
	{}
	
	void getdata()
	{
		cout<<"\nEnter x: ";
		cin>>x;
		cout<<"Enter y: ";
		cin>>y;
	}

	void display()
	{
		cout<<"("<<x<<","<<y<<") ";
	}

};

float distance(Point &p1,Point &p2)
{
	return(sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2)));
}


int main()
{
	Point p1,p2;
	//Point p1(8,6), p2(4,3);

	cout<<"\nEnter point p1: ";
	p1.getdata();

	cout<<"\nEnter point p2: ";
	p2.getdata();

	//cout<<"Distance between p1(8,6) & p2(4,3) = "<<distance(p1,p2);
	cout<<"\nDistance between ";
	p1.display();
	cout<<"and ";
	p2.display();
	cout<<"= ";
	cout<<distance(p1,p2)<<endl;

	return 0;
}

	