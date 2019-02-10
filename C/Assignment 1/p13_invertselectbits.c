#include<stdio.h>

int invertponwards(int,int,int);

int main()
{
	int n,p,b;
	
	printf("Enter integer: ");
	scanf("%d",&n);
		
	printf("Enter invert begin position: ");
	scanf("%d",&p);
	
	printf("Enter number of bits to invert: ");
	scanf("%d",&b);

	printf("%d inverted by %d bits starting from %d position = %d",n,b,p,invertponwards(n,p,b));
	
	return 0;
}

int invertponwards(int n,int p,int b)
{
	int num = ((1 << (b+p)) - 1) ^ ((1 << (p - 1)) - 1);
	return n^num;
}


/*
C:\Users\tanis\Desktop\cdac_cprog\Assignment 1>p13_invertselectbits
Enter integer: 50
Enter invert begin position: 2
Enter number of bits to invert: 3
50 inverted by 3 bits starting from 2 position = 44

50 = 110010
44 = 101100


*/