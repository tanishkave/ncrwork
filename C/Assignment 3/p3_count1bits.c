#include<stdio.h>

int main()
{
	long int bit8;
	int count=0;

	printf("Enter 8 bit number: ");
	scanf("%ld",&bit8);

	while(bit8!=0)
	{
		if(bit8%10==1)
		 count++;
		bit8=bit8/10;
	}

	printf("Number of bit '1': %d",count);
	return 0;

}


/*
Take input only up to 2 power 8. Convert to binary and then try
*/