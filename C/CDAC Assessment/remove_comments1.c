#include<stdio.h>
#include<stdlib.h>

void remove_comments()
{
	FILE *fp1,*fp2;
	char ch1;

	
	fp1=fopen("hello2.txt","r");
	fp2=fopen("hello2out.txt","w");
	
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

		if(ch1=='/')		// check for beginning of comment with '/'
		{
			ch1=fgetc(fp1);
		
			if(ch1=='/')	//check if single line comment
			{
				while(ch1!='\n')	//single line comment ends with new line character
					ch1=fgetc(fp1);	

			}
			
			if(ch1=='*')	//check if multi-line comment
			{
				ch1=fgetc(fp1);
				while(ch1!='/')		//check for end of multiline comment
				{
					ch1=fgetc(fp1);
					
				}
				ch1=fgetc(fp1);
			}
			
		}
		fputc(ch1,fp2);
	}

	printf("Comments replaced in new file hello2out.txt\n");
	fclose(fp1);
	fclose(fp2);
	return;

}