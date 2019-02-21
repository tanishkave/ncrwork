#include<iostream>
using namespace std;

struct node 
{
	int data;
	struct node * prev;
	struct node * next;
};

class DLL
{
	struct node * start;

	public:

	DLL();

	void insert_beg(int);
	void insert_end(int);
	void insert_after(int,int);
	void insert_before(int,int);
	
	int delete_beg();
	int delete_end();
	void delete_spec(int);
	
	void travel_forward();
	void travel_backward();

	~DLL();

};

DLL::DLL()
{
	start=NULL;
}

void DLL::insert_beg(int ele)
{
	struct node *temp;
	temp = new node;
	
	temp->data=ele;
	temp->prev=NULL;
	temp->next=start;
	if(start!=NULL)
		start->prev=temp;
	start=temp;	
}

void DLL::insert_end(int ele)
{
	struct node *temp;
	temp = new node;
	
	temp->data=ele;
	temp->next=NULL;

	if(start==NULL)
	{	
		temp->prev=NULL;
		start=temp;
	}
	else
	{
		struct node *curr;
		curr=start;
		
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next=temp;
		temp->prev=curr;
	}
}

void DLL::insert_after(int ele,int sele)
{
	if(start!=NULL)
	{
		struct node *curr;
		curr=start;
	
		while(curr!=NULL && curr->data!=sele)
			curr=curr->next;
		
		if(curr!=NULL)
		{
			struct node * temp;
			temp = new node;
		
			temp->data=ele;
			temp->prev=curr;
			temp->next=curr->next;
			//curr->next=temp;
			if(curr->next!=NULL)
				curr->next->prev=temp;
			curr->next=temp;	
		}
		else
			cout<<"Element not found"<<endl;
	}
	else
		cout<<"Linked List is empty"<<endl;
}

void DLL::insert_before(int ele,int sele)
{
	if(start!=NULL)
	{	
		struct node *curr;
		curr=start;
		while(curr->next!=NULL && curr->next->data!=sele)
			curr=curr->next;
		if(curr->next!=NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data=ele;
			temp->prev=curr->prev;
			temp->next=curr;
			
			if(curr->prev!=NULL)
				curr->prev->next=temp;
			else
				start=temp;
			curr->prev=temp;	
		}
		else
			cout<<"Element not found"<<endl;
	}
	else
		cout<<"Linked List is empty"<<endl;
}

int DLL::delete_beg()
{
	int x = -9999;
	if(start!=NULL)
	{
		struct node *temp;
		temp=start;
		
		if(temp->next!=NULL)
			temp->next->prev=NULL;
		start=temp->next;
		
		x=temp->data;
		delete temp;
	}
	else
		cout<<"Linked List is empty"<<endl;
	
	return x;
}

int DLL::delete_end()
{
	int x = -9999;
	if(start!=NULL)
	{
		struct node *curr;
		curr=start;
	
		while(curr->next!=NULL)
			curr=curr->next;

		if(curr->prev!=NULL)
			curr->prev->next=NULL;
		else
			start=NULL;

		x=curr->data;
		delete curr;
	}

	else
		cout<<"Linked List is empty"<<endl;
		
	return x;
}

void DLL::delete_spec(int ele)
{
	if(start!=NULL)
	{
		struct node *curr;
		curr=start;
		while(curr!=NULL && curr->data!=ele)
			curr=curr->next;
		if(curr!=NULL)
		{	
			if(curr->prev!=NULL)
				curr->prev->next=curr->next;
			else
				start=curr->next;
			if(curr->next!=NULL)
				curr->next->prev=curr->prev;
		
			delete curr;
		}
		else
			cout<<"Element not found"<<endl;
	}
	else
		cout<<"Linked List is empty"<<endl;
		
}

void DLL::travel_forward()
{
	if(start!=NULL)
	{
		struct node *curr;
		curr=start;
		while(curr!=NULL)
		{
			cout<<curr->data<<"-->";
			curr=curr->next;
		}
	}
	cout<<"NULL"<<endl;
}

void DLL::travel_backward()
{
	cout<<"NULL  ";
	if(start!=NULL)
	{
		struct node *curr;
		curr=start;
		while(curr->next!=NULL)
			curr=curr->next;
		while(curr!=NULL)
		{
			cout<<curr->data<<"  ";
			curr=curr->prev;
		}
	}
	cout<<endl;
}


DLL::~DLL()
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
	int ch,num,p,res;
	DLL L;
	
	cout<<"Operation"<<endl<<endl;
	cout<<"1.Insertion at beginning"<<endl;
	cout<<"2.Insertion at end"<<endl;
	cout<<"3.Insertion after element"<<endl;
	cout<<"4.Insertion before element"<<endl;
	cout<<"5.Deletion from beginning"<<endl;
	cout<<"6.Deletion from end"<<endl;
	cout<<"7.Deletion of an element"<<endl;
	cout<<"8.Traverse Forward"<<endl;
	cout<<"9.Traverse Backward"<<endl;
	cout<<"10.Exit"<<endl;
	
	while(1)
	{
		cout<<"Select option:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Enter element to insert: ";
				cin>>num;
				L.insert_beg(num);
			       break;
			case 2: cout<<"Enter element to insert: ";
				cin>>num;
				L.insert_end(num);
			       break;
			case 3: cout<<"Enter element to insert: ";
				cin>>num;
				cout<<"Enter element after which to insert:";
				cin>>p;
				L.insert_after(num,p);
				break;
			case 4: cout<<"Enter element to insert: ";
				cin>>num;
				cout<<"Enter element before which to insert:";
				cin>>p;
				L.insert_before(num,p);
				break;
			case 5:res=L.delete_beg();
				cout<<"Deleted from the beginning = "<<res<<endl;
				break;
			case 6:res=L.delete_end();
				cout<<"Deleted from the end= "<<res<<endl;
				break;
			case 7: cout<<"Enter element to delete: ";
				cin>>num;
				L.delete_spec(num);
				break;
			case 8:L.travel_forward();
				break;
			case 9:L.travel_backward();
				break;
			case 10:exit(0);
				break;
			default:cout<<"Wrong Option"<<endl;
		};		
	}
	return 0;

}
