#include<iostream>
using namespace std;


class student
{

	char * student_name;
	char grade;
	float marks1;
	float marks2;
	float marks3;

	public:
	
	void setData(char name[],char g,int m1,int m2,int m3)
	{
		student_name=(char *)malloc(sizeof(char)*strlen(name));
		strcpy(student_name,name);
		grade=g;
		marks1=m1;
		marks2=m2;
		marks3=m3;		
	}

	float calculateAverage()
	{
		return((marks1+marks2+marks3)/3);
	}

	void computeGrade()
	{
		cout<<endl<<"Computing Grade"<<endl;
		float avg=calculateAverage();
		if(avg>60)
		{
			grade='1';
			cout<<"First Class"<<endl;
		}
		else
		{
			if(50<avg&& avg<60)
			{
				grade='2';
				cout<<"Second Class"<<endl;
			}
			else
			{
				if(40<avg && avg<50)
				{
					grade='3';	
					cout<<"Third Class"<<endl;
				}
				else
				if(avg<40)
				{
					grade='F';
					cout<<"Fail"<<endl;
				}
			}
		}
	}

	void display()
	{
		cout<<"Student Name: "<<student_name<<endl;
		cout<<"Grade: "<<grade<<endl;
		cout<<"Marks1: "<<marks1<<endl;
		cout<<"Marks2: "<<marks2<<endl;
		cout<<"Marks3: "<<marks3<<endl;		
	
	}

};


int main()
{
	student s;
	char name[50];
	int m1,m2,m3;
	
	cout<<"Enter name: ";
	cin>>name;
	
	cout<<"Enter Subject 1 marks: ";
	cin>>m1;
	cout<<"Enter Subject 2 marks: ";
	cin>>m2;
	cout<<"Enter Subject 3 marks: ";
	cin>>m3;

	s.setData(name,'-',m1,m2,m2);
	cout<<endl<<"Before computing grade:"<<endl;
	s.display();

	s.computeGrade();
	cout<<endl<<"After computing grade:"<<endl;
	s.display();
	
	return 0;
}	