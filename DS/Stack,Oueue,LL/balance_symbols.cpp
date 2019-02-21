#include<iostream>
using namespace std;

struct __Stack__
{
	int top;
	char *s;
	int size;
};

class _Stack_
{
	struct __Stack__ sta;
	
	public:
	
	_Stack_()
	{
		sta.top=-1;
		sta.size=0;
		sta.s=NULL;
	}

	void getSize(int n)
	{
		sta.size=n;	
		sta.s=new char[n];
	}

	bool isFull()
	{
		return(sta.top == (sta.size-1));
	}

	bool isEmpty()
	{
		return(sta.top==-1);
	}
	
	void push(int ele)
	{
		if(!isFull())
			sta.s[++sta.top]=ele;
		else
			cout<<"Stack Overflow"<<endl;
	}

	char pop()
	{
		if(!isEmpty())
			return sta.s[sta.top--];
		else
			cout<<"Stack Underflow"<<endl;
		return -1;
	}

	char peek()
	{
		if(!isEmpty())
			return sta.s[sta.top];
		else
			cout<<"Stack Underflow"<<endl;;
		return -1;
	}

	void display()
	{
		if(!isEmpty())
			for(int i=0;i<= sta.top;i++)
				cout<<sta.s[i]<<"  ";
		else
			cout<<"Stack is empty"<<endl;
	}

	~_Stack_()
	{
		delete sta.s;
	}
};


void checkBalance(char *);


int main()
{
	char *e;
	e = new char[30];

	cout<<"Enter expression: ";
	cin>>e;

	checkBalance(e);
	
	delete e;

	return 0;
}

void checkBalance(char *e)
{
	_Stack_ s;
	s.getSize(strlen(e));

	int flag=0;
	char ch;
		
	for(int i=0;i<strlen(e);i++)
	{
		ch = e[i];	// cout<<endl<<"ch = "<<ch<<endl;

		switch(ch)
		{
			case '(':
			case '[':
			case '{':  s.push(ch); 
				   //cout<<endl<<"pushed= "<<ch<<endl; 
				   break;
		
			case ')':
			case ']':
			case '}':if(!s.isEmpty())
				 {	
					if((ch==')' && s.peek() == '(')|| (ch==']' && s.peek() == '[') || (ch=='}' && s.peek() == '{') )
						s.pop(); 	
				  	else
				    		flag=1; 
				  }
				  else
					flag=1;	 
				  break;
			default:;
		}
		if(flag==1)	//cout<<endl<<"broken"<<endl;	
			break;	
	
	}
	if(s.isEmpty() && flag!=1)
		cout<<"Balanced"<<endl;
	else
		cout<<"Not Balanced"<<endl;

}
