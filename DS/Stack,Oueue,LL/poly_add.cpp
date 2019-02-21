#include<iostream>
using namespace std;

struct node 
{
	int coeff;
	int pow;
	struct node * next;
};

class LL
{
	public:
	struct node * start;

	//public:

	LL()
	{
		start=NULL;
	}	

	void insert_beg(int,int);
	void insert_end(int,int);
	
	void delete_beg();
	void delete_end();
		
	void display();

	friend void add(LL,LL,LL &);

	~LL();

	//void insert_after(int,int);
	//void insert_before(int,int);
	//void delete_spec(int);
};


void LL::insert_beg(int c,int p)
{
	struct node *temp;
	temp = new node;
	
	temp->coeff=c;
	temp->pow=p;
	temp->next=start;
	start=temp;	
}

void LL::insert_end(int c,int p)
{
	struct node *temp;
	temp = new node;
	
	temp->coeff=c;
	temp->pow=p;
	temp->next=NULL;

	if(start==NULL)
		start=temp;
	else
	{
		struct node *curr;
		curr=start;
		
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next=temp;
	}
}

void LL::delete_beg()
{
	//int x = -9999;
	if(start!=NULL)
	{
		struct node *temp;
		temp=start;
		//x=temp->data;
		start=start->next;
		delete temp;
		
	}
	else
		cout<<"Linked List is empty"<<endl;
	
	//return x;
}

void LL::delete_end()
{
	//int x = -9999;
	if(start!=NULL)
	{
		if(start->next==NULL)
		{
			//x=start->data;
			delete start;
			start=NULL;
		}
		else
		{
			struct node *curr;
			curr=start;
		
			while(curr->next->next!=NULL)
				curr=curr->next;
			//x=curr->next->data;
			delete curr->next;
			curr->next=NULL;
		}
	}
	else
		cout<<"Linked List is empty"<<endl;
		
	//return x;
}

void LL::display()
{
	if(start!=NULL)
	{
		struct node *curr;
		curr=start;
		while(curr!=NULL)
		{
			cout<<"("<<curr->coeff<<")x^"<<curr->pow<<" + ";
			curr=curr->next;
		}
	}
}

void add(LL l1,LL l2,LL &l3)
{
	struct node *c1,*c2;
	c1=l1.start;
	c2=l2.start;
		
	while(c1!=NULL && c2!=NULL)
	{
		if(c1->pow==c2->pow)
		{
			l3.insert_end((c1->coeff+c2->coeff),c1->pow);
			c1=c1->next;
			c2=c2->next;
		}	
		else 
		{
			if(c1->pow > c2->pow)
			{
				l3.insert_end(c1->coeff,c1->pow);
				c1=c1->next;
			}
			else
			{
				l3.insert_end(c2->coeff,c2->pow);	
				c2=c2->next;	
			}
		}
	}
	
	while(c1!=NULL)
	{
		l3.insert_end(c1->coeff,c1->pow);
			c1=c1->next;
	}
	while(c2!=NULL)
	{
		l3.insert_end(c2->coeff,c2->pow);	
			c2=c2->next;	
	}
	
	delete c1;
	delete c2;
			
}

LL::~LL()
{
	struct node *temp;
	while(start!=NULL)
	{
		temp=start;
		start=temp->next;
		delete temp;	
	}
}

int main()
{
	LL l1,l2,res;
	
	l1.insert_beg(-3,0);
	l1.insert_beg(4,1);
	l1.insert_beg(5,3);
	
	l2.insert_beg(3,1);
	l2.insert_beg(4,2);

	//add(l1,l2,res);
	
	cout<<" { ";
	l1.display();
	cout<<" } + { ";
	l2.display();
	cout<<" } = ";
	//res.display();
	

	return 0;
}
