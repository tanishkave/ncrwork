#include<stdio.h>


int main(int argc,char *argv[])
{
	FILE *fp;
	char ch;
	unsigned char s[50];
	int i;

	fp=fopen(argv[1],"w");
	if(fp==NULL)
	{
		printf("Error in creating file");
		return -1;
	}

	printf("Enter data to insert into the file: ");
	gets(s);
	
	for(i=0;i<strlen(s);i++)
		fputc(~s[i],fp);
		
	fclose(fp);

	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("Error in opening file");
		return -1;
	}
	
	ch=fgetc(fp);
	printf("%c",ch);
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fp);
	}

	fclose(fp);

	return 0;
}
	
