#include<stdio.h>

int main()
{
	int arr[20];
	int N,sum,i,j;
	int sum1=0,flag = 0;

	printf("Enter number of elements: ");
	scanf("%d",&N);

	printf("Enter sum: ");
	scanf("%d",&sum);

	printf("Enter %d non-negative elements: ",N);

	for(i=0;i<N;i++)
		scanf("%d",&arr[i]);

	for(i=0;i<N;i++)
	{	
		sum1=0;
		for(j=i+1;j<=N;j++)
		{
			sum1=sum1+arr[j-1];
			if(sum1>sum)
			 break;
			if(sum1==sum)
			{   
				flag=1;
				printf("Sum found between indices: %d and %d\n",i,j-1);
				break;
			}
		}
		if(flag==1)
			break;
	}
	if(flag==0)
		printf("Subarray not found\n");

	return 0;
}