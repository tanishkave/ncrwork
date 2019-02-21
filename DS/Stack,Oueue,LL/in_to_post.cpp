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
			//cout<<"Stack Underflow"<<endl;
		return -1;
	}

	char peek()
	{
		if(!isEmpty())
			return sta.s[sta.top];
		else
			//cout<<"Stack Underflow"<<endl;;
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


char * infixToPostfix(char *);

int getPriority(char);

int main()
{
	char *in = new char[40];
	
	cout<<"Enter infix expression: ";
	cin>>in;

	cout<<endl<<"Postfix expression: ";

	cout<<infixToPostfix(in)<<endl;	

	delete in;
	
	return 0;
}

char * infixToPostfix(char *in)
{
	_Stack_ s;
	s.getSize(strlen(in));
	char *post = new char[strlen(in)];
	int p,j=0;
	char ch;

	for(int i=0;i<strlen(in);i++)
	{
		ch=in[i];

		switch(ch)
		{
			case '(': s.push(ch); 
				  break;
			case ')': while(s.peek()!='(')
	                           {    
					post[j++]=s.peek();
					s.pop();
				   }
				   s.pop();
				  break;
          
               		default: p=getPriority(ch);
                       		 if(p==0)
          				post[j++]=ch;
	                        else
				{
					while(p<=getPriority(s.peek()))
                                	{       
						post[j++]=s.peek();
						s.pop();
                                        }
					s.push(ch);
				}
		};
	}
	while(!s.isEmpty())
	{
		post[j++]=s.peek();
		s.pop();
	}
	post[j]='\0';
	return post;
}

int getPriority(char ch)
{
	switch(ch)
	{
                case '^':return 3;
                        break;
                case '*':return 2;
                        break;
                case '/':return 2;
                        break;
                case '+':return 1;
                        break;
		case '-':return 1;
			 break;
		default: return 0;
	}
}