#include<stdio.h>

int any(char *,char *);
int main()
{
	char s1[15],s2[15];
	int res;

	printf("Enter String s1:");
	gets(s1);
	printf("Enter String s2:");
	gets(s2);
	
	res=any(s1,s2);
	
	if(res==-1)
		printf("No matching found");
	else
		printf("%d location of s1 matches location in s2\n",res);

	return 0;
}

int any(char *s1, char *s2)
{
	int i,j;
	for(i=0;i<strlen(s1);i++)
	for(j=0;j<strlen(s2);j++)
	if(s1[i]==s2[j])
		return i;

	return -1;
}