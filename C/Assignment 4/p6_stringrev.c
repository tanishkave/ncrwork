#include<stdio.h>

void recrev(char *,int,int);
int main()
{
	char s[30];

	printf("Enter a string: ");
	gets(s);
	
	recrev(s,0,strlen(s)-1);

	printf("Reversed String: %s",s);

	return 0;
}

void recrev(char *s,int i,int j)
{
	if(i>=j)
		return;
	else
	{
		char temp;
		temp=s[j];
		s[j]=s[i];
		s[i]=temp;
		recrev(s,++i,--j);
	}	
}

