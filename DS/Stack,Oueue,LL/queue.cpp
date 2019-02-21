#include<iostream>
using namespace std;

class Queue
{
	int r;
	int f;
	int *q;
	int size;

	public:

	Queue()
	{
		r=f=-1;
		q=NULL;
	}

	void getSize(int n)
	{
		size=n;
		q=new int[n];
	}

	bool overflow()
	{
		if(r==size-1)
			return true;
		else 
			return false;
	}

	bool underflow()
	{
	
		if(f==r)
			return true;
		else
			return false;
	}
	
	void enqueue(int ele)
	{
		if(!overflow())
			q[++r]=ele;
		else
			cout<<"Queue is full"<<endl;
	}

	int dequeue()
	{
		int x= -9999;
		if(!underflow())
			x=q[++f];
		else 
		   cout<<"Queue is empty"<<endl;
		return x;
	}

	void display()
	{
		for(int i=f+1;i<=r;i++)
			cout<<q[i]<<"  ";
	}

	~Queue()
	{
		delete q;
	}
};

int main()
{
	Queue qu;
    	int ch;
	int n;
	
	cout<<"Enter size of queue: ";
	cin>>n;
	qu.getSize(n);

	while(1)
	{
        	cout<<endl<<"Operations:"<<endl;
        	cout<<"1.Enqueue"<<endl<<"2.Dequeue"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
        	cout<<"Enter your choice: ";
        	cin>>ch;
        	switch(ch)
		{
            		case 1: {	int ele;
					cout<<"Enter element to enqueue: ";
					cin>>ele;
					qu.enqueue(ele);
				}
				break;
			case 2: {	int x;
					x = qu.dequeue();
					cout<<endl<<"Dequeued: "<<x<<endl;
				}
				break;
			case 3: qu.display();
				break;
			case 4:exit(0);
			default:cout<<"Wrong option"<<endl;
		}
		
	}
	
	return 0;
}