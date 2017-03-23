/*swap two numbers by passing PARAMETER as REFERENCES
using temporary variable
Input: two integer pointers*/
void swap_TEMP(int *a,int *b)
{
	int temp;
	temp=*b;
	*b=*a;
	*a=temp;
}

/*swap two FLOATING numbers by passing PARAMETER as REFERENCES
using temporary variable
Input: two float type pointers*/
void swap_TEMP(float *a,float *b)
{
	float temp;
	temp=*b;
	*b=*a;
	*a=temp;
}

/*swap two characters values by passing PARAMETER as REFERENCES
using temporary variable
Input: two char type pointers*/
void swap_TEMP(char *a,char *b)
{
	char temp;
	temp=*b;
	*b=*a;
	*a=temp;
}

/*swap two numbers by passing PARAMETER as REFERENCES
using BOOLEAN XOR FUNCTION
Input: two integer pointers*/
void swap_XOR(int *a,int *b)
{
	int key=*a^*b;
	*a^=key;
	*b^=key;
}

/*swap two characters values by passing PARAMETER as REFERENCES
using BOOLEAN XOR FUNCTION
Input: two char type pointers*/
void swap_XOR(char *a,char *b)
{
	char key=*a^*b;
	*a^=key;
	*b^=key;
}

/*swap two FLOATING numbers by passing PARAMETER as REFERENCES
using temporary variable
Input: two float type pointers*/

#include <string>
using namespace std;
/*
void swap_XOR(float *a,float *b)
{
	int i;

	string strA=to_string(*a);
	string strB=to_string(*b);

	for(i=0;(strA[i]!='\0')&&(strB[i]!='\0');++i)
	{
		char key=strA[i]^strB[i];
		strA[i]=strA[i]^key;
		strB[i]=strB[i]^key;
	}
		
	*a=stof(strA);
	*b=stof(strB);	

}
*/

/*swap two numbers by passing PARAMETER as REFERENCES
without using TEMPORARY variable
Input: two integer pointers*/
#include "../mathINTERFACE.h"
void swap_W_O_TEMP(int *a,int *b)
{
	if(signum(*a)==signum(*b))
	{
		*a=*a-*b;
		*b=*a+*b;
		*a=*b-*a;
	}	

	else
	{
		*a=*a+*b;
		*b=*a-*b;
		*a=*a-*b;
	}
}

/*swap two characters by passing PARAMETER as REFERENCES
without using TEMPORARY variable
Input: two character pointers*/
void swap_W_O_TEMP(char *a,char *b)
{
	*a=*a-*b;
	*b=*a+*b;
	*a=*b-*a;
}


/*swap two FLOATING numbers by passing PARAMETER as REFERENCES
without using TEMPORARY variable
Input: two FLOAT pointers*/
void swap_W_O_TEMP(float *a,float *b)
{
	if(signum(*a)==signum(*b))
	{
		*a=*a-*b;
		*b=*a+*b;
		*a=*b-*a;
	}	

	else
	{
		*a=*a+*b;
		*b=*a-*b;
		*a=*a-*b;
	}
}

