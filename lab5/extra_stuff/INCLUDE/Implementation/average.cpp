/*find the AVERAGE of an array[0 ... n-1]
OPTIMISED TO WORK FOR LARGE NUMBERS
D.S. An array of size 'n'*/
double average(int *array,int n,int threshold)
{
	int i=0;
	int size_threshold=0;

	for(i=0;i<n;++i)
		if(array[i]>=threshold)
			++size_threshold;

	double avg=0;
	for(i=0;i<n;++i)
		if(array[i]>=threshold)
			avg+=array[i]*1.00/size_threshold;

	return avg;
}