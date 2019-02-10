#include<stdio.h>
#include<math.h>

int rotate_right(int, int);

void main()
{
	int n,b;
	
	printf("Enter the number: ");
	scanf("%d", &n);
	
	printf("Enter number of bits to be rotated: ");
	scanf("%d", &b);

	printf("%d rotated by %d bits = %d",n,b,rotate_right(n,b));
}
int rotate_right(int n, int b)
{
	int q,r,res;
	r=n%100;
	q=n/100;
	res=(r*pow(10,b))+q;
	return res;
}