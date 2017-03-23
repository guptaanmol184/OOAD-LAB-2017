#include "../swap.h"
#include "../arrayOpns.h"
/*Find the next lowest pemutation of array in LEXICOGRAPHICAL ORDERING*/
int nxtPermutation(int *arrayStart,int *arrayEnd)
{
	int perm_next=0;

	if(arrayStart!=arrayEnd)
	{
		int *ptr_K,*ptr_L;
		ptr_K=ptr_L=arrayEnd;

		do
		{
			ptr_K--;
			if(*ptr_K>*(ptr_K+1))
			{
				perm_next=1;
			}

		}while((ptr_K!=arrayStart)&&(perm_next==0));

		if(perm_next==1)
		{
			while(*ptr_L>=*ptr_K)
				ptr_L--;

			swap_TEMP(ptr_K,ptr_L);
			arrayReverse(ptr_K+1,arrayEnd);
		}
	}

	return perm_next;
}