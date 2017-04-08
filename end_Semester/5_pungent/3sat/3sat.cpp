#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <stdio.h>
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


	//// ---------- MAIN DECESION PART ----------
	// generate truth values and find weather any exist
	int soln=0;

	int n=var_count;

	//int graph[k];
	int vertex[n+1]={0};

	vertex[n+1-1]=1;

	/*int i;
	for (i = 0; i < k; ++i)
	{
		scanf("%1d",&graph[i]);
	}

	for (i = 0; i < k; ++i)
	{
		printf("%d ",graph[i]);
	}
	printf("\n");*/

	//graph_to_adj(graph,adj,n);

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
		for (int i = 1; i < n+1; ++i)
		{
			printf("%d:%d ",i,vertex[i]);		
		}
		printf("\n");
		
	}
	else
	cout<<"no truth assignment exists"<<endl;




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







	/*int k=n*n;
	int ctr=0;
	int graph_cp[k];

	int i,j;
	for (i = 0; i < k; ++i)		//duplicate graph
	{
		graph_cp[i]=graph[i];
	}


	for (i = 0; i < n; ++i)			//vertex include list..
	{
	  		if(vertex[i]==1)
			{		
				row_zero(graph_cp,i,n);
			}
	}
		
	if(is_zero(graph_cp,n))
		return(1);

	else 
		return(0);*/
}