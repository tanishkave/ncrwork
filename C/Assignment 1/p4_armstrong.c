#include<stdio.h>

int main()
{
	int num,arm,r,check;
	arm=0;
	
	printf("Enter a number: ");
	scanf("%d",&num);
	test=num;
	
	while(num!=0)
	{	
		r=num%10;
		num=num/10;
		arm = arm +r*r*r;
	}

	if(arm==check)
		printf("It is armstrong number");
	else
		printf("It is not armstrong number");
	
	return 0;
}