#include<stdio.h>

void mgetline(char *,int);
void expand(char *,char *);

int main()
{
	char s1[50],s2[50];

	printf("Enter notation to expand: ");

	mgetline(s1,50);

	expand(s1,s2);

	printf("%s",s2);

	return 0;
}

void mgetline(char *s,int max)
{
	int i,c;

	for(i=0;i<max-1 && (c=getchar())!=EOF && c!='\n';++i)
		s[i]=c;

	if(c=='\n')
        s[i++]=c;
    
	s[i]='\0';
}

void expand(char *s1,char *s2)
{
	int c,i=0,j=0;

	while((c=s1[i++]) != '\0')
        
	if(s1[i]=='-' && s1[i+1] >=c)
        {
        	i++;
        	while(c<s1[i])
        		s2[j++]=c++;
        }
        else
        	s2[j++]=c;

    	s2[j]='\0';
}