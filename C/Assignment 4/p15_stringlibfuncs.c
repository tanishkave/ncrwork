#include<stdio.h>

void strcpy(char *,char *);
void strcat(char *,char *);
void strrev(char *);
int strcmp(char *,char *);

int main()
{
	char s1[20],s2[20],s3[10],s4[10];
	int res;

	strcpy(s1,"hello");
	printf("s1: %s\n",s1);
	
	strcpy(s2,"cat");
	strcat(s1,s2);
	printf("s1 cat: %s\n",s1);
	
	strrev(s1);
	printf("s1 reversed: %s\n",s1);
	
	strcpy(s3,"compare");
	strcpy(s4,"compare");

	if(!strcmp(s3,s4))
		printf("s3 and s4 are equal\n");
	else
		printf("s3 and s4 are not equal\n");
	
	if(!(res=strcmp(s1,s2)))
		printf("s1 and s2 are equal\n");
	else
		printf("s1 and s2 vary by %d\n",res);
	return 0;
		
}

void strcpy(char *s1,char *s2)
{
	while((*s1++=*s2++)!='\0');

}

void strcat(char *s1,char *s2)
{
	while(*s1!='\0')	
		s1++;	
	while((*s1=*s2)!='\0')
	{
		s1++;  s2++;
	}
	
}

void strrev(char *s1)
{
	int i,j;
	char temp;
	for(i=0 , j=strlen(s1)-1; i<j; i++,j-- )
	{
		temp = s1[i];
		s1[i] = s1[j];
		s1[j] = temp;
	}
}

int strcmp(char *s1, char *s2)
{
	int i=0;
	while( s1[i] == s2[i] )
	{
		if(s1[i] == '\0')
			return 0;
		++i;
	}
	return (s1[i] - s2[i]);
}

