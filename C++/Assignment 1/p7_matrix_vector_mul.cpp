#include<iostream>
#include<vector>
using namespace std;

class Matrix
{
	vector<vector<int>> mat;

	public:
	
	Matrix()
	{ }
    
	Matrix(int m,int n)
	{
        	cout<<"Enter "<<m+m<<" elements: ";
        	for(int i=0;i<m;i++)
        	{
           		vector<int> row;
           		for(int j=0;j<n;j++)
           		{
                		int in;
                		cin>>in;
                		row.push_back(in);
            		}
            		mat.push_back(row);
        	}
   	}
   
    	void display()
    	{
        	for(int i=0;i<mat.size();i++)
        	{
            		for(int j=0;j<mat[i].size();j++)
                		cout<<mat[i][j]<<" ";
            		cout<<endl;
        	}
    	}

	friend Matrix multiply(const Matrix &,const Matrix &);

};

Matrix multiply(const Matrix &a,const Matrix &b)
{
    	Matrix res;
    	
	int m1=a.mat.size();
    	int n1=a.mat[0].size();
    	int m2=b.mat.size();
    	int n2=b.mat[0].size();
    
	if(n1!=m2)
    	{
        	cout<<"Cannot multiply";
        	exit(-1);
    	}
    
	vector<vector<int> > t1;
	for(int i=0;i<m1;i++)
    	{
        	vector<int> t2;
        	
		for(int j=0;j<n2;j++)
        	{
        	    int temp=0;
        	    for(int k=0;k<m2;k++)
        	    {
        	        temp=temp+(a.mat[i][k]*b.mat[k][j]);
        	    }
        	    t2.push_back(temp);
        	}
        	t1.push_back(t2);
    	}
    	res.mat=t1;

	return res;
}
int main()
{

	int m,n;
    
	cout<<"Enter size of Matrix 1: "<<endl;
    	cin>>m>>n;
    	Matrix m1(m,n);
    	
	cout<<"Enter size of Matrix 2: "<<endl;
    	cin>>m>>n;
    	Matrix m2(m,n);
    
	cout<<"Matrix m1: "<<endl;
    	m1.display();
    
	cout<<"Matrix m2: "<<endl;
   	m2.display();
    
	Matrix res=multiply(m1,m2);
    
	cout<<" m1 + m2 = "<<endl;
    	res.display();
   
	return 0;
}
