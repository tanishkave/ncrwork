#include<stdio.h>
int main()
{
	int i=0;
	int letter, digit, space, tab;
	char a[80];

	printf("Enter a string: ");
	scanf("%c",&a);

	while(a[i]!= '\0')
	{
		if(a[i]>='A'&& a[i] <='Z' || a[i]>='a && a[i]<='z')
			letter++;
		else
			if(a[i]>='0' && a[i]<='9')
				digit++;
			else
				if(a[i]==' ')
					space+=;
				else
					tab+=;
	}

	printf("Number of Letters:%d\n",letter);
	printf("Number of Digits: %d\n",digit);
	printf("Number of Spaces: %d\n", space);
	printf("Number of Tabs: %d\n",tab);
	
	return 0;
}