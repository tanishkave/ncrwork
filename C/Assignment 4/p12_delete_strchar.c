#include<stdio.h>
#include<string.h>

void delete(char s1[], char s2[]);
int main()
{
	char s1[20],s2[20];
	
	printf("Enter string s1: ");
	gets(s1);
	printf("Enter string s2: ");
	gets(s2);

	delete(s1,s2);

	printf("s1 after deleting s2 matching chars: %s\n",s1);

	return 0;
}
void delete(char s1[], char s2[])
{
	int i,j,k;
	k=0;
	for(i=0; s1[i]!='\0';++i)
	{
		for(j=0; (s1[i]!=s2[j]) && s2[j]!='\0' ; ++j)
		if(s2[j] == '\0')
		s1[k++] = s1[i];
	}
	s1[k]='\0';
}

//check