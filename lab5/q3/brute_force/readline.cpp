/*Reads graphs line by line from a file
  to give input to other functons
 */

#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
using namespace std;

int VERTEX_COUNT=5;

void print(int a[])
{
	for(int i=0;i<VERTEX_COUNT*VERTEX_COUNT;i++)
		cout<<a[i];
	cout<<endl;

}


int main()
{
	char ch;
	string filename="../../extra_stuff/graphs_file_read/planar_conn_"+to_string(VERTEX_COUNT)+".txt";
	
	ifstream file;
	file.open(filename,ios::in);

	int graph[VERTEX_COUNT*VERTEX_COUNT];
	int i=-1;
	if(file.is_open())
	{
		while(file>>noskipws>>ch)
		{
			if(ch=='\n')
			{
				i=-1;
				print(graph);
			}
			else
				graph[++i]=ch-'0';
		}


	}
	else
		cout<<"Unable to open file\n";

	return 0;
}