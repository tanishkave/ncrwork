#include<stdio.h>

int main()
{
	int num,rev,r,check;
	rev=0;
	
	printf("Enter a number: ");
	scanf("%d",&num);
	test=num;
	
	while(num!=0)
	{	
		r=num%10;
		num=num/10;
		rev = rev*10+r;
	}

	printf("Reversed Number: %d\n",rev);
	
	if(rev==check)
		printf("It is a palindrome");
	else
		printf("It is not a palindrome");
	return 0;
}