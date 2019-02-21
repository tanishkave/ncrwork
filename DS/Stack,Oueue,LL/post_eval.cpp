#include<iostream>
#include<cstring>
#include<cctype>
#include<stack>

using namespace std;

int getpriority(char ch)
{
	switch (ch)
	{
     		case '/':
         	case '*': return 2;
         	case '+':
     		case '-': return 1;
            	default : return 0;
   	}
}


int eval(int  op1,int op2,char ch)
{
        switch(ch)
        {
        case  '^':return op2^op1;
        case  '*':return op2*op1;
        case '/':return op2/op1;
        case '+':return op2+op1;
        case '-':return op2-op1;
        default: return 0;
        }
}

int postEval(char *post)
{
	stack<int> s;
	int i=0;
	char ch;
	int res;
        
	for(i=0;i<strlen(post);i++)
	{
		ch=post[i];
                
		if(isdigit(ch))
	                s.push(ch-'0');
                
		else
    		{
    			int op1=s.top();
   			s.pop();
  			int op2=s.top();
  			s.pop();
  			res=eval(op1,op2,ch);
  			s.push(res);
  		}
	}

	return res;
}


int main()
{
	char *post = new char[30];   	
	
	cout<<"Enter a postfix expression: ";
	cin>>post;

	int res = postEval(post);

	cout<<endl<<post<<" = "<<res<<endl;

	return 0;
		
}