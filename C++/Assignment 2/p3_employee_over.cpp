#include<iostream>
using namespace std;

class Employee
{
	int empno;
	char name[20];
	float salary;

	public:
	
	friend istream & operator >> (istream &,Employee &);

	Employee()
	{ }

	~Employee()
	{ }

	/*void set_data()
	{
		
	}*/

	void read_data()
	{
		cout<<endl<<"Employee no.: "<<empno<<endl;
		cout<<"Employee name: "<<name<<endl;
		cout<<"Employee salary: "<<salary<<endl;
	}

};

istream & operator >> (istream &cin,Employee &e)
{
		cout<<endl<<"Enter Employee no.: ";
		cin>>e.empno;
		cout<<"Enter Employee name: ";
		cin>>e.name;
		cout<<"Enter Employee salary: ";
		cin>>e.salary;

		return cin;
}

int main()
{
	Employee e[5];
	int i;

	cout<<"Enter details for 5 employees: "<<endl;
	for(i=0;i<5;i++)
		cin>>e[i];

	cout<<endl<<"Dispalying employee details: "<<endl;
	for(i=0;i<5;i++)
		e[i].read_data();	

	return 0;
}

/*

Define a class named Employee with data members empno, name, & salary and 
appropriate member functions for setting and reading the data, constructors and destructor.
Create an array of 5 Employee objects, populate it with data by overloading >> operator 

*/
