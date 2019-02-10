#include<stdio.h>

int main()
{
	char * s [ ] = { "we will teach you how to" , "Move a mountain" , "Level a building" , "Erase the past" , "Make a million"};	
	int i,j,len,count=0;
	
	for(i=0;i<5;i++)
		while(*s[i]!='\0')
			if(*s[i]++ == 'e')
				count++;
	
	printf("Count of 'e' = %d",count);

	return 0;
}