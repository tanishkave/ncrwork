#include<iostream>
using namespace std;

//order of invocation of constructors and destructors

class Employee
{
	int empno;
	int salary;

	public:
	
	Employee()
	{
		empno=salary=0;
		cout<<endl<<"Default Constructor"<<endl;
	}

	Employee(int x)
	{
		empno=salary=x;
		cout<<endl<<"1 arg Constructor"<<endl;
	}

	Employee(int e,int s)
	{
		empno=e;
		salary=s;
		cout<<endl<<"2 args Constructor"<<endl;
	}

	Employee(Employee &e)
	{
		empno=e.empno;
		salary=e.salary;
		cout<<endl<<"Copy Constructor"<<endl;
	}	
	
	~Employee()
	{
		cout<<endl<<"Destructor"<<endl;
	}
	
};

int main()
{
	Employee e1,e2(2,3),e3(7);	//Call by value;
	Employee e4(e2);		//Call by reference
	
	cout<<endl<<"sizeof(Employee) = "<<sizeof(struct Employee)<<endl;
	
	return 0;


}