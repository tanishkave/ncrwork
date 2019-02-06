#include <stdio.h>
#include<math.h>

int main()
{
	int p=10000,t=10,r=2;
	float SI,CI,CIHY,CIQ,CIM,CID;
	float a,b,c,d,e;
    
	SI = (p*t*r)/100;

    	a = 1+(r/100);
    	CI = p*pow(a,t);

    	b = 1+ (r/200);
    	CIHY = p*pow(b,2*t);
    
	c = 1 + (r/400);
    	CIQ = p* pow(c,4*t);
    
	d = 1 + (r/1200);
    	CIM = p * pow(d, 12*t);
    
	e = 1+ (r/36500);
    	CID = p * pow(e, 365 * t);
	
	printf("Simple Interest = %f\n", SI);
    	printf("Compound Interest Annually= %f\n", CI);
    	printf("Compound Interest Half yearly= %f\n", CIHY);
    	printf("Compound Interest Quarterly= %f\n", CIQ);
    	printf("Compound Interest Monthly= %f\n", CIM);
    	printf("Compound Interest Daily= %f\n", CID);

	return 0;
}