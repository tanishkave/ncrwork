#include<stdio.h>
#include<math.h>

int main()
{
	long int bin;
	int dec=0;
	int r;

	printf("Enter binary number: ");
	scanf("%ld",&bin);
	int i=0;

	while(bin!=0)
	{
		r=bin%10;
		dec=dec+r*pow(2,i);
		bin=bin/10;
		i++;
	}

	printf("Decimal: %d\n",dec);

	i=0;
	while(dec!=0)
	{
		r=dec%2;
		bin=bin + r*pow(10,i);
		dec=dec/2;
		i++;
	}
	
	printf("Binary: %ld\n",bin);
	return 0;
		
}
