#include <iostream>
using namespace std;

int ways(int n);

main()
{
	int n=0,count;
	while(n<=0)
	{
		cout<<"enter the number of steps in the ladder: ";
		cin>>n;
	}
	
	count = ways(n);
	cout<<"the number of ways to climb "<<n<<" steps is: "<<count<<endl;
}

int ways(int n)
{
	if(n==1||n==2)
		return(n);
	else
		return(ways(n-1)+ways(n-2));
}