#include<stdio.h>

int main()
{
	char *color[6] = {"red", "green", "blue", "white", "black", "yellow"}; 

	printf("color = %X\n",color);	
	printf("color+2 = %X\n",color+2);
	printf("*color = %s\n",*color);
	printf("*(color+2) = %s\n",*(color+2));
	printf("color[5] = %s\t *(color + 5) = %s",color[5],*(color + 5));
	
	return 0;
}
