#include<iostream>
using namespace std;

struct __Stack__
{
	int top;
	int *s;
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
		sta.s=new int[n];
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
		int x = -9999;
		if(!isEmpty())
			x = sta.s[sta.top--];
		else
			cout<<"Stack Underflow"<<endl;
		return x;
	}

	char peek()
	{
		int x = -9999;
		if(!isEmpty())
			x=sta.s[sta.top];
		else
			cout<<"Stack Underflow"<<endl;;
		return x;
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

int main()
{
    	_Stack_ s;
    	int ch,n;

	cout<<"Enter stack size: ";
	cin>>n;	
	s.getSize(n);
	
	while(1)
	{
        	cout<<endl<<"Operations:"<<endl;
        	cout<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Peek"<<endl<<"4.Display"<<endl<<"5.Exit"<<endl;
        	cout<<"Enter your choice: ";
        	cin>>ch;
        	
		switch(ch)
		{
            		case 1: {  int ele;
				   cout<<"Enter element to push: ";
				   cin>>ele;
				   s.push(ele);
				}break;
			case 2:	{int x=s.pop();
				cout<<"Popped element = "<<x;}
				break;
			case 3:	{int x=s.peek();
				cout<<"Top element = "<<x;}
				break;
			case 4: s.display();
				break;
			case 5: exit(0);
				break;
			default:cout<<"Wrong option"<<endl;
		}
	}
	return 0;
}
     