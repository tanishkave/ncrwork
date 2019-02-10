#include<stdio.h>
#include<string.h>

int main()
{
	char s[20];
	int i,j;
	char ch;
	
	printf("Enter string: ");
	scanf("%s",s);
	
	i=strlen(s);
	
	while(i!=0)
	{
		ch = s[0];
		
		for(j=0;j<strlen(s) - 1;j++)
			s[j] = s[j+1];
	
		s[j] = ch;
		
		printf("\n %s",s);
		i--;
	}

	return 0;
}