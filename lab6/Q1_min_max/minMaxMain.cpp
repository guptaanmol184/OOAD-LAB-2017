#include <iostream>
using namespace std;

#include "./INCLUDE_MIN_MAX/minMaxTemplate.h"

main()
{
	int size,i,choice;
	cout<<"Enter size of array"<<endl;
	cin>>size;

	cout<<"\nEnter your DATATYPE choice"<<endl;
	cout<<"1. Integers"<<endl;
	cout<<"2. Floating point"<<endl;
	cout<<"3. Characters"<<endl;

	cin>>choice;

	switch(choice)
	{
		case 1:
		{
			/*Finding Min and Max in Integer array --start*/
			int array[size];

			cout<<"\nENTER "<<size<<" INTEGERS"<<endl;
			for(i=0;i<size;++i)
				cin>>array[i];

			int *minAndMax=minMax(array,size);
			cout<<"Min = "<<minAndMax[0]<<endl;
			cout<<"Max = "<<minAndMax[1]<<endl;

			/*Finding Min and Max in Integer array --end*/
		}
			
		break;

		case 2:
		{
			/*Finding Min and Max in Float array --start*/
			float array[size];

			cout<<"\nENTER "<<size<<" FLOATING POINT NUMBERS"<<endl;
			for(i=0;i<size;++i)
				cin>>array[i];

			float *minAndMax=minMax(array,size);
			cout<<"Min = "<<minAndMax[0]<<endl;
			cout<<"Max = "<<minAndMax[1]<<endl;

			/*Finding Min and Max in Integer array --end*/
			
		}
			
		break;

		case 3:
		{
			/*Finding Min and Max in Character array --start*/
			char array[size];

			cout<<"\nENTER "<<size<<" CHARACTERS"<<endl;
			for(i=0;i<size;++i)
				cin>>array[i];

			char *minAndMax=minMax(array,size);
			cout<<"Min = "<<minAndMax[0]<<endl;
			cout<<"Max = "<<minAndMax[1]<<endl;

			/*Finding Min and Max in Character array --end*/
		}
			
		break;
	}

}