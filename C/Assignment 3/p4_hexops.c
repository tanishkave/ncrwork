#include<stdio.h>
//int hex = 255;
int main()
{
	int hex;
	int bits,mask,out;
	int ch;

	printf("Enter a hexadecimal number: ");
	scanf("%X",&hex);
	out=hex;

	printf("Menu:\n 1.1's Complement\n 2.Mask\n 3.Shift\n 4.Exit\n Select Option: ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:{	out=~hex;
				printf("1's complement of %X = %X\n",hex,out);
			
			 }break;
 
		case 2:{
				int ch1;
				printf("Mask:\n 1.Bitwise AND\n 2.Bitwise XOR\n 3.Bitwise OR\n Select Option: ");
				scanf("%d",&ch1);
				printf("Enter mask value: ");
				scanf("%X",&mask);
				switch(ch1)
				{
					case 1: out=hex&mask;
						printf("%X AND mask by %X = %X\n",hex,mask,out);
						break;
					case 2: out=hex^mask;
						printf("%X XOR mask by %X = %X\n",hex,mask,out);
						break;
					case 3: out=hex|mask;
						printf("%X OR mask by %X= %X\n",hex,mask,out);
						break;
					default: printf("Invalid option");
						 break;
				};	
			  }break;

		case 3:{
				int ch2;
				printf("Shift:\n 1.Left\n 2.Right\n Select Option: ");
				scanf("%d",&ch2);
				printf("Enter number of bits: ");
				scanf("%d",&bits);
				switch(ch2)
				{
					case 1: out=hex<<bits;
						printf("%X left shifted by %d bits = %X\n",hex,bits,out);
						break;
					case 2: out=hex>>bits;
						printf("%X right shifted by %d bits = %X\n",hex,bits,out);
						break;
					default: printf("Invalid option");
						 break;
				};	
			  }break;

		case 4:break;

		default:printf("Invalid Option\n");
			break;
	};
	return 0;

}
	