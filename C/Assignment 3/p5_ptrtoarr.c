#include<stdio.h>

int main()
{
	
	int x[8]={10,20,30,40,50,60,70,80};

	printf("x = %x\n",x);			// Base address of array x
	
	printf("x+2 = %x\n",x+2);		// Address of x[2]

	printf("*x = %d\n",*x);			// Content of base address of array x i.e., x[0]

	printf("(*x+2) = %d\n",(*x+2));		// x[0]+2	

	printf("*(x+2) = %d\n",*(x+2));		// Content of x[2]

	return 0;

}