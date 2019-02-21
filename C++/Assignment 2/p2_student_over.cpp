#include<iostream>
using namespace std;

class student
{
	int rno;
	char name[30];
	float marks1;
	float marks2;
	float totmarks;
	char grade;

	public:

	friend ostream & operator<< (ostream &,student);
	
	friend istream & operator>> (istream &,student &);

	friend void generate_results(student [],int n);
};

ostream & operator<< (ostream &cout,student s)
{
	cout<<endl;
	cout<<"Roll no: "<<s.rno<<endl;
	cout<<"Name: "<<s.name<<endl;
	cout<<"Total Marks: "<<s.totmarks<<endl;
	cout<<"Grade: "<<s.grade<<endl;
	cout<<endl;

	return cout;
}
	
istream & operator>> (istream &cin,student &s)
{
	cout<<"Enter roll number: ";
	cin>>s.rno;
	cout<<"Enter name: ";
	cin>>s.name;
	cout<<"Enter subject 1 marks: ";
	cin>>s.marks1;
	cout<<"Enter subject 2 marks: ";
	cin>>s.marks2;

	return cin;

}

char calculate_grade(float);

void generate_results(student s[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		s[i].totmarks=s[i].marks1+s[i].marks2;
		s[i].grade=calculate_grade(s[i].totmarks);	
	}
}

char calculate_grade(float total)
{
	float avg=total/2;

	if(avg>90)
		return 'A';
	if(avg>80)
		return 'B';
	if(avg>70)
		return 'C';
	if(avg>60)
		return 'D';
	if(avg>50)
		return 'E';
	else
		return 'F';
}

int main()
{
	student s[3];
	int i;
	
	cout<<"Enter details of 3 students: "<<endl;
	for(i=0;i<3;i++)
		cin>>s[i];
	
	generate_results(s,3);

	cout<<endl<<"Student details after generating results: "<<endl;
	for(i=0;i<3;i++)
		cout<<s[i];
	
	return 0;
}