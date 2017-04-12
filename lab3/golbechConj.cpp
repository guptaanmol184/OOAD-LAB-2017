#include <iostream>
using namespace std;

#include "../INCLUDE/arrayOpns.h"

#include <math.h>
#include <stdlib.h>
//Max number checked for primality = UINT_MAX
#define PRIME_MAX 1000000

//MACRO pi(x)= (#primes less than or equal to x)
#define pi_PRIME_MAX int((PRIME_MAX*1.00/log(PRIME_MAX))*(1+1.2762/log(PRIME_MAX)))

main()
{
	
	int prime_len=1;

	//primes: List of all prime numberss
	int *primes=(int *)malloc(sizeof(int)*pi_PRIME_MAX);
	primes[0]=2;

	int num_is_prime;

	int number,prime_index;
	for(number=3;number<=(PRIME_MAX-1);number+=2)
	{
		num_is_prime=1;

		for(prime_index=0;prime_index<prime_len;++prime_index)
			if(number%primes[prime_index]==0)
			{
				num_is_prime=0;
				break;
			}

		if(num_is_prime==1)
			primes[prime_len++]=number;
	}
	/*
	for(prime_index=0;prime_index<prime_len;++prime_index)
		cout<<primes[prime_index]<<" ";
	cout<<endl;
	*/
	
	//4=2+2,i.e., sum of two primes

	//scan through all even numbers>=6 and check if they can be expressed as sum of 2 primes
	int is_exp_prime2sum;
	for(number=6;number<=2*primes[prime_len-1];number+=2)
	{
		is_exp_prime2sum=0;

		prime_index=0;
		while((primes[prime_index]<number)&&(prime_index<prime_len))
		{
			if(binarySearch(primes,prime_len,number-primes[prime_index])!=-1)
			{
				cout<<number<<" = "<<primes[prime_index]<<" + "<<number-primes[prime_index]<<endl;
				is_exp_prime2sum=1;
				break;
			}

			prime_index++;
		}

		if(is_exp_prime2sum==0)
			cout<<number<<" cannot be expressed as sum of two PRIMES <="<<primes[prime_len-1]<<endl;
	}

}
