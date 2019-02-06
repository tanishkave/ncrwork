#include<stdio.h>

int main()
{
	int num,i;
	unsigned long fact =1;
	printf("Enter number: ");
	scanf("%d",&num);

		if(n<0)
			printf("Factorial of a negative number doesn't exist\n");
		else 
		{
			for(i=1;i<n;i++)
				fact * = i;
			printf("Factorial of %d = %lu\n", num, fact);
		}
	return 0;
}
