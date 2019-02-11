#include<stdio.h>

int main()
{
	
	int ch;
	
	printf("Menu: \n1. Count contents\n2. Remove comments\n3. Rotate word\n4. Replace tabs\n Enter your choice: ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:count_contents();
			break;
		case 2:remove_comments();
			break;
		case 3:rotate_word();
			break;
		case 4:replace_tabs();
			break;
		default:printf("\nInvalid choice\n");
				break;
	};
	return 0;
}

