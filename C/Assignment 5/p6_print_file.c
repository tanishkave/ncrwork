#include<stdio.h>

int main()
{
	FILE *fp;
	char *f[20];
	char ch;
	
	printf("Enter file name: ");
	gets(f);
	
	fp=fopen(f,"r");
	if(fp==NULL)
	{
		printf("File not found");
		return -1;
	}
	
	ch=fgetc(fp);

	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fp);
	}
	
	fp.close();	

	return 0;

}