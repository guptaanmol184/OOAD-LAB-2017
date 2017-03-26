#include <iostream>
using namespace std;

#include "./INCLUDE_MIN_MAX/minMaxTemplate.h"

main()
{
	int size,i;
	cout<<"Enter size of array"<<endl;
	cin>>size;

	/*Finding Min and Max in Integer array --start*/
	int arrayInt[size];
	cout<<"\nInput "<<size<<" integers"<<endl;
	for(i=0;i<size;++i)
		cin>>arrayInt[i];

	int *minAndMaxInt=minMax(arrayInt,size);
	cout<<"Min = "<<minAndMaxInt[0]<<endl;
	cout<<"Max = "<<minAndMaxInt[1]<<endl;

	/*Finding Min and Max in Integer array --end*/


	/*Finding Min and Max in Character array --start*/
	char arrayChar[size];
	cout<<"\nInput "<<size<<" characters"<<endl;
	for(i=0;i<size;++i)
		cin>>arrayChar[i];

	char *minAndMaxChar=minMax(arrayChar,size);
	cout<<"Min = "<<minAndMaxChar[0]<<endl;
	cout<<"Max = "<<minAndMaxChar[1]<<endl;

	/*Finding Min and Max in Character array --end*/


	/*Finding Min and Max in Float array --start*/
	float arrayFloat[size];
	cout<<"\nInput "<<size<<" floating point numbers"<<endl;
	for(i=0;i<size;++i)
		cin>>arrayFloat[i];

	float *minAndMaxFloat=minMax(arrayFloat,size);
	cout<<"Min = "<<minAndMaxFloat[0]<<endl;
	cout<<"Max = "<<minAndMaxFloat[1]<<endl;

	/*Finding Min and Max in Integer array --end*/

}