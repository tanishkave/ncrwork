#include<stdio.h>

void rotate_word()
{

	char ch1,ch;
	char s[8]="happy";
	FILE *fp1,*fp2;
	int i,j;
	int flag=0;
	
	fp1=fopen("hello3.txt","r");
	fp2=fopen("hello3out.txt","w");
	
	if ( fp1 == NULL || fp2 == NULL )  
	{   
		printf( "Cannot open file\n" ) ;  
		return;
	}
	
	while(1)
	{
		ch1=fgetc(fp1);
		
		if(ch1==EOF)
		break;

		if(ch1==s[0])
		{
		
			for(i=0;i<strlen(s);i++)	//check if whole word present in file
			{
				ch1=fgetc(fp1);
				if(ch1!=s[i+1])
				break;
				flag=1;
			}
			if(flag==1)			//rotate the word
			{
				ch = s[0];
				for(j=0;j<strlen(s) - 1;j++)
					s[j] = s[j+1];
				s[j] = ch;
				
				for(i=0;i<strlen(s);i++)	//place rotated word in the file
					fputc(s[i],fp2);
			}
	
		
		}
	
		fputc(ch1,fp2);					
	}
	

	
	printf("Word replaced with rotation");
	fclose(fp1);
	fclose(fp2);
	
	return;
}