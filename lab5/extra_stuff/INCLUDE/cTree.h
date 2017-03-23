#ifndef CTREE_H
#define CTREE_H

/*Complete tree using array*/
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <math.h>

class cTree
{
	public:
		int no_nodes;
		int *array;
		int last_index;

	public:
		cTree();
		void no_nodes_input();

		void insert(int value);
		int checkComplete();
		//find left child and right child index given an element index
		int leftChildIndex(int eleIndex);
		int rightChildIndex(int eleIndex);

		//height is same for all branches as it is complete tree
		int height();
		void displayTree();
};

void cTree::no_nodes_input()
{
	cout<<"Enter No. of nodes in complete Tree"<<endl;
	cin>>no_nodes;
}

cTree::cTree()
{
	no_nodes_input();
	array=(int *)malloc(sizeof(int)*no_nodes);
	last_index=-1;
}

void cTree::insert(int value)
{
	if(last_index>=no_nodes-1)
		cout<<"Tree size exhausted"<<endl;

	else
	{
		array[last_index+1]=value;
		last_index++;
	}
}

int cTree::leftChildIndex(int eleIndex)
{
	return eleIndex*2+1;
}

int cTree::rightChildIndex(int eleIndex)
{
	return eleIndex*2+2;
}

int cTree::height()
{
	return int(log2(no_nodes));
}

void cTree::displayTree()
{
	for(int i=0;i<=last_index;++i)
		cout<<array[i]<<" ";
	cout<<endl;
}

#include "../INCLUDE/typeCheck.h"

int cTree::checkComplete()
{
	if(isInteger(log2(no_nodes+1)))
		return 1;

	else
		return 0;
}

#endif