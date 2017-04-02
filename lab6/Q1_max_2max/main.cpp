#include <iostream>
using namespace std;

#include "./linkedList.cpp"

main()
{
	int i,n,choice;

	cout<<"Enter n"<<endl;
	cin>>n;

	cout<<"\nEnter your DATATYPE choice"<<endl;
	cout<<"1. Integers"<<endl;
	cout<<"2. Floating point"<<endl;
	cout<<"3. Characters"<<endl;

	cin>>choice;

	switch(choice)
	{
		case 1:
		{
			//DATATYPE : int --start
			int value;

			//initialise with empty
			linkedList<int> LL;

			cout<<"\nEnter "<<n<<" INTEGERS"<<endl;
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
				cout<<"FIRST MAXIMUM   = "<<max<<endl;

			if(max2==-1)
				cout<<"SECOND MAX DOESN'T EXIST"<<endl;
			else
				cout<<"SECOND MAXIMUM  = "<<max2<<endl;
			//DATATYPE : int --end
		}
		break;

		case 2:
		{
			//DATATYPE : float --start
			float value;

			//initialise with empty
			linkedList<float> LL;

			cout<<"\nEnter "<<n<<" FLOATING POINT NUMBERS"<<endl;
			for(i=0;i<n;++i)
			{
				cin>>value;
				LL.insert(value);
			}

			LL.runKnockout();

			float max=LL.getMax();
			float max2=LL.getSecondMax();

			if(max==-1)
				cout<<"LIST IS EMPTY !!!"<<endl;
			else
				cout<<"FIRST MAXIMUM   = "<<max<<endl;

			if(max2==-1)
				cout<<"SECOND MAX DOESN'T EXIST"<<endl;
			else
				cout<<"SECOND MAXIMUM  = "<<max2<<endl;
			//DATATYPE : float --end
		}
		break;

		case 3:
		{
			//DATATYPE : char --start
			char value;

			//initialise with empty
			linkedList<char> LL;
			
			cout<<"\nEnter "<<n<<" CHARACTERS"<<endl;
			for(i=0;i<n;++i)
			{
				cin>>value;
				LL.insert(value);
			}

			LL.runKnockout();

			char max=LL.getMax();
			char max2=LL.getSecondMax();

			if(max==-1)
				cout<<"LIST IS EMPTY !!!"<<endl;
			else
				cout<<"FIRST MAXIMUM   = "<<max<<endl;

			if(max2==-1)
				cout<<"SECOND MAX DOESN'T EXIST"<<endl;
			else
				cout<<"SECOND MAXIMUM  = "<<max2<<endl;
			//DATATYPE : char --end
		}
		break;
	}
	

	
}