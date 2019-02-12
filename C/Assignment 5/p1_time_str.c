#include<stdio.h>

struct time
{
	int hr;
	int min;
	int sec;

};

int main()
{
	struct time t;
	
	printf("Enter time(hr): ");
	scanf("%d",&t.hr);
		
	printf("Enter time(min): ");
	scanf("%d",&t.min);
	
	printf("Enter time(sec): ");
	scanf("%d",&t.sec);

	printf("Details stored in struct time: ");
	printf("\nhr:min:sec\t%d:%d:%d",t.hr,t.min,t.sec);
	return 0;
}