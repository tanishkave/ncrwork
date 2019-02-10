#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int replace(char *);
int main()
{
	char *s="the cat sat on the hat";
	int spaces;
	
	//char *s
	//printf("Enter a string: ");
	//s=(char *)malloc(sizeof(char)*20);
	//scanf("%[^\n]s",name);
	//strcpy(s,gets());
	
	spaces=replace(s);

	printf("New string is: ");
	puts(s);
	printf("Spaces: %d",spaces);

	return 0;
}

int replace(char *str)
{
	int i,spaces=0;
	
	for(i=0;str[i]!='\0';i++)
	if(str[i]==' ')
	{
		str[i]='-';
		spaces++;
	}
	return spaces;
}















/*int len = strlen(str)+2;
	while((*str)!='\0')
	{
		//printf("%c\n",*str);
		if(*str==' ')
		{
			*str='-';
			printf("*str replaced=%c\n",*str);
			str++;
			spaces++;
		}
		printf("exit");
	
	
	for(i=0;i<len;i++)
	if(str[i]==' ')
	{
		str[i]='-';
		spaces++;
	}
*/