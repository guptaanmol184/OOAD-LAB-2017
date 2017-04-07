#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// typedef vector of vectors
typedef vector< vector<int> > matrix;

int is_truth_assignment(int *vertex,matrix clauses,int var_count);

int main(void)
{
	// get the number of variables and clauses
	int var_count;
	cout<<"enter the number of variables: ";
	cin>>var_count;

	int  clause_count;
	cout<<"enter the number of clauses: ";
	cin>>clause_count;

	// get clauses
	int value;
	vector<int> one_clause;
	matrix clauses;
	for(int i=0; i<clause_count; i++)
	{
		cout<<"clause "<<i+1<<" : ";
		for(int j=0;j<3;j++)
		{
			cin>>value;
			one_clause.push_back(value);
		}
		clauses.push_back(one_clause);
		one_clause.clear();
	}

	// print the clause array
	/*cout<<"input clauses: "<<endl;
	for(int i=0;i<clause_count;i++)
	{
		for(int j=0;j<3;j++)
			cout<<clauses[i][j]<<" ";
		cout<<endl;
	}*/


	//// ---------- MAIN DECESION PART ( DECCESION 3 SAT )----------
	// generate truth values and find weather any exist
	int soln=0;

	int n=var_count;

	int vertex[n+1]={0};

	vertex[n+1-1]=1;

	for (int i = 1; i < n+1; ++i)
	{
		do{
			if(is_truth_assignment(vertex,clauses,var_count))
			{
				soln=1;
				/*for(int l=1;l<n+1;++l)
					printf("%d ",vertex[l] );
				printf("\n");*/
				break;
			}

		  }while(next_permutation(vertex+1,vertex+n+1));

		if(soln==1)
			break;	

		vertex[(n+1)-i-1]=1;				
	}

	if(soln==1)
	{
		/*for (int i = 1; i < n+1; ++i)
		{
			printf("%d ",vertex[i]);		
		}
		printf("\n");*/
		cout<<"truth assignment exists"<<endl;
		
	}
	else
	{
		cout<<"no truth assignment exists"<<endl;
		exit(0);	
	}
	
	// -------------- FINDING SOLUTION USING DECESION 3 SAT AS BB ------------
	// initialie vectex array as 0 again
	for(int i=0;i<n+1;i++)
		vertex[i]=0;

	// change values of variables and check
	for(int k=1;k<n+1;k++)
	{
		// assume xi to be 1 and check if truth assignment exists
		vertex[k]=1;
		// assume soln does not exist
		soln=0;

		// check truth assignment
		for (int i = 1; i < n+1; ++i)
		{
			do{
				if(is_truth_assignment(vertex,clauses,var_count))
				{
					soln=1; // solution exists
					/*for(int l=1;l<n+1;++l)
						printf("%d ",vertex[l] );
					printf("\n");*/
					break;
				}

			  }while(next_permutation(vertex+1+k,vertex+n+1));  // pass only part of array that needs to be permuted

			if(soln==1)
				break;	

			vertex[(n+1)-i-1]=1;				
		}

		if(soln!=1)
			vertex[k]=0;
		// else 
			// our assumption is true

	}

	// print solutin using decesion 3 sat
	cout<<"decision 3 sat solution: "<<endl;
	for (int i = 1; i < n+1; ++i)
	{
		printf("%d:%d ",i,vertex[i]);		
	}
	printf("\n");

}

int is_truth_assignment(int *vertex,matrix clauses,int var_count)
{	

	/*cout<<"print bool array: ";
	for(int i=1;i<var_count+1;i++)
		cout<<vertex[i]<<" ";
	cout<<endl;*/

	int flag=1;

	for(int i=0; i<clauses.size();i++)
	{
		int clause_result=0;
		int var0result;
		int var1result;
		int var2result;

		//cout<<

		// evaluate clauses
		if(clauses[i][0]>0)
			var0result=vertex[clauses[i][0]];
		else
			var0result=!vertex[-clauses[i][0]];

		if(clauses[i][1]>0)
			var1result=vertex[clauses[i][1]];
		else
			var1result=!vertex[-clauses[i][1]];

		if(clauses[i][2]>0)
			var2result=vertex[clauses[i][2]];
		else
			var2result=!vertex[-clauses[i][2]];

		// clause or value
		clause_result=var0result+var1result+var2result;
		/*cout<<"var0result: "<<var0result<<endl;
		cout<<"var1result: "<<var1result<<endl;
		cout<<"var2result: "<<var2result<<endl;
		cout<<"clause_result: "<<clause_result<<endl;*/

		if(clause_result == 0)
		{
			flag=0;
			break;
		}
	}

	return flag;
}