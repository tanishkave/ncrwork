#include<stdio.h>
#include<string.h>

int main()
{
	char *s[20];
	char name[30];
	int i,j,n;

	printf("Enter number of strings: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{	
		printf("Enter name for string %d: ",i);
		scanf("%s",name);
		s[i]=(char *)malloc((strlen(name)+1)*sizeof(char));
	
		if(s[i]==NULL)
		{
			for(j=i;j>=0;j--)
			free(s[j]);
			return -1;
		}
		strcpy(s[i],name);
	}

	printf("The strings are: \n");
	for(i=0;i<n;i++)
		printf("%s\n",s[i]);
	
	return 0;
}