/*calculates GCD using Euclidean ALGORITHM
Input: 2 integers*/
int gcd(int a,int b)
{
	if(a<b)
		gcd(b,a);

	else
	{
		if((a==0)||(b==0))
			return a==0?b:a;

		else if(a%b==0)
			return b;

		else
			gcd(b,a%b);
	}
}

/*calculates GCD using Euclidean ALGORITHM
Input: An array of size 'n', n>=2*/
int gcd(int *array,int n)
{
	int hcf=gcd(array[0],array[1]);
	for(int i=2;i<n;++i)
		hcf=gcd(hcf,array[i]);

	return hcf;

}