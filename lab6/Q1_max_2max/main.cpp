#include <iostream>
using namespace std;

#include "./linkedList.cpp"

main()
{
	int i,n,value;

	cout<<"Enter n"<<endl;
	cin>>n;

	//initialise with empty
	linkedList<int> LL;
	
	cout<<"\nEnter elements"<<endl;
	for(i=0;i<n;++i)
	{
		cin>>value;
		LL.insert(value);
	}

	LL.runKnockout();

	int max=LL.getMax();
	int max2=LL.getSecondMax();

	if(max==-1)
		cout<<"LIST IS EMPTY !!!"<<endl;
	else
		cout<<"FISRT MAXIMUM   = "<<max<<endl;

	if(max2==-1)
		cout<<"SECOND MAX DOESN'T EXIST"<<endl;
	else
		cout<<"SECOND MAXIMUM  = "<<max2<<endl;

	
}