#include<stdio.h>

void delete(char *,char);
int main()
{
	char s[20];
	char c;
	
	printf("Enter string: ");
	scanf("%s",s);
	
	printf("Enter character to delete: ");
	scanf("%s",&c);
	
	delete(s, c);
	
	printf("String after deleting char %c: %s",c,s);
	
	return 0;
}

void delete(char *s,char c)
{
	int i,j;
    	
	for (i=0,j=0; i<strlen(s); i++) 
       	{
		if (s[i] != c) 
       		{
			s[j] = s[i];
			j++;
		} 
		else 
			i++;
	}
	s[j]='\0';
}

//check