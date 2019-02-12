#include<stdio.h>

struct test1
{
	int num;
	char ch;
};

union test2
{
	int num;
	char ch;
};

int main()
{
	printf("Size of struct test: %d bytes",sizeof(struct test1));
	
	printf("\nSize of union test: %d bytes",sizeof(union test2));

	return 0;
}