#include<stdio.h>

int main()
{
	FILE *fp;
	char f[20];
	char s[50];
	char ch;
	int i;
	long pos;

	printf("Enter file name: ");
	gets(f);
	
	if((fp=fopen(f,"w"))==NULL)
	{
		printf("Error in creating file");
		return -1;
	}
	
	printf("Enter data: ");	
	gets(s);

	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='a' && s[i]<='z')
			s[i]=s[i]-32;
		else
		{
			if(s[i]>='A' && s[i]<='Z')
			s[i]=s[i]+32;
		}

		fputc(s[i],fp);

	}

	fclose(fp);

	if((fp=fopen(f,"r"))==NULL)
	{
		printf("Error in opening file");
		return -1;
	}

	ch=fgetc(fp);
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fp);
	}

	fclose(fp);

	if((fp=fopen(f,"r"))==NULL)
	{
		printf("Error in opening file");
		return -1;
	}
	fgetc(fp);
	ch=fgetc(fp);
	
	pos=ftell(fp);
	printf("\nPosition from ftell(): %ld\n",pos);
	printf("\nCharacter at position returned by ftell(): %c\n",ch);
	
	
	fseek(fp,0L,SEEK_SET);
	ch=fgetc(fp);
	printf("\nCharacter at beginning pos after fseek(): %c\n",ch);
	
	return 0;
}