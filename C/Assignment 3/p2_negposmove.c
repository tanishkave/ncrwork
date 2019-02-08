#include<stdio.h>

int main()
{
	
	int arr[10];
	int i,j,temp;
	
	printf("Enter 10 integers: ");
	
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);

	for(i=0;i<=10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(arr[j]<0&&0<=arr[i])
			{
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	
	}

	printf("Negative and Positive separated: \n");
	for(i=0;i<10;i++)
		printf("%d  ",arr[i]);
	
	return 0;
}