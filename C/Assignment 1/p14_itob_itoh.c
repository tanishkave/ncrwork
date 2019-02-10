#include<stdio.h>
#include<math.h>
#include<string.h>

void itob(int,char[]);
void itoh(int,char[]);

int main()
{
	int n;
	int dec=0;
	int r,i=0;
	char res1[10];
	char res2[10];

	printf("Enter n: ");
	scanf("%d",&n);

	itob(n,res1);
	printf("Binary: %s\n",res1);

	itoh(n,res2);
	printf("Hexadecimal: %s\n",res2);

	return 0;
}

void itob(int dec,char *s1)
{
	char bin[10];
	int r,i=0;

	while(dec!=0)
	{
		r=dec%2;
		bin[i]=r+'0';
		dec=dec/2;
		i++;
	}
	bin[i]='\0'
	strrev(bin);
	strcpy(s1,bin);		
}

void itoh(int dec,char *s2)
{
	char hex[10];
	int r,i=0;

	while(dec!=0)
	{
		r=dec%16;
		if(r<10)
			hex[i]=r+'0';
		if(r>=10)
			hex[i]=r+'57';
		dec=dec/16;
		i++;
	}

	hex[i]='\0';
	strrev(hex);
	strcpy(s2,hex);
}

/*Handle input=0 case*/