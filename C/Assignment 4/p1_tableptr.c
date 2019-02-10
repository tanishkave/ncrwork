#include<stdio.h>

int main()
{
	
	float table[2][3] = { { 1.1,1.2,1.3},{2.1,2.2,2.3}};

	printf("table = %X\n",table);
	printf("table+1 = %X\n",table+1);
	printf("*(table+1) = %X\n",*(table+1));
	printf("(*(table+1)+1) = %X\n",(*(table+1)+1));
	printf("(*(table)+1) = %X\n",(*(table)+1));
	printf("*(*(table+1) +1) = %f\n",*(*(table+1) +1));
	printf("*(*(table)+1) = %f\n",*(*(table)+1));
	printf("*(*(table) + 1)+1 = %f\n",*(*(table) + 1)+1);
	
	return 0;
}

