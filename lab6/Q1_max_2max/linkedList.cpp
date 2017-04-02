#include <iostream>
using namespace std;

#include <cmath>
#include "./linkedList.h"

//Functions of class node --start
template <typename C>
node<C>::node(C value)
{
	data=value;
	losers=NULL;
	next=NULL;
}

template <typename C>
void node<C>::setNextValue(node<C> *nxt_node)
{
	next=nxt_node;
}

template <typename C>
C node<C>::getData()
{
	return data;
}

template <typename C>
node<C> *node<C>::getNext()
{
	return next;
}

template <typename C>
node<C> *node<C>::getLosers()
{
	return losers;
}

template <typename C>
void node<C>::addLoser(node<C> *lost_node)
{
	lost_node->setNextValue(losers);
	losers=lost_node;
}
//Functions of class node --end


//Functions of class linkedList --start
template <typename C>
linkedList<C>::linkedList()
{
	root=NULL;
	size=0;
}

template <typename C>
void linkedList<C>::insert(C value)
{
	//new keyword is important
	node<C> *new_node= new node<C>(value);
	new_node->setNextValue(root);
	root=new_node;

	size++;
}

template <typename C>
void linkedList<C>::displayLL()
{
	node<C> *temp=root;

	while(temp!=NULL)
	{
		cout<<temp->getData()<<" ";
		temp=temp->getNext();
	}

	cout<<endl;
}

template <typename C>
void linkedList<C>::runKnockout()
{
	int i;
	node<C> *cur_node;
	node<C> *prev_node;

	while(size>1)
	{
		if(root->getData()<root->getNext()->getData())
		{
			cur_node=root;
			root=cur_node->getNext();
			root->addLoser(cur_node);
		}

		else
		{
			prev_node=root;
			cur_node=root->getNext();
			prev_node->setNextValue(cur_node->getNext());
			prev_node->addLoser(cur_node);
		}

		prev_node=root;

		for(i=3;i<size;i+=2)
		{
			cur_node=prev_node->getNext();

			if(cur_node->getData()>cur_node->getNext()->getData())
			{
				prev_node=cur_node;
				cur_node=cur_node->getNext();
				prev_node->setNextValue(cur_node->getNext());		
			}

			else
			{
				prev_node->setNextValue(cur_node->getNext());
				prev_node=prev_node->getNext();
			}

			prev_node->addLoser(cur_node);
		}

		size=ceil(size/2.00);
	}
}

template <typename C>
C linkedList<C>::getMax()
{
	if(root==NULL)
		return -1;

	else
		return root->getData();
}

template <typename C>
C linkedList<C>::getSecondMax()
{
	if((root==NULL)||(root->getLosers()==NULL))
		return -1;

	else
	{
		node<C> *cur_node=root->getLosers();
		C max2=cur_node->getData();

		cur_node=cur_node->getNext();
		while(cur_node!=NULL)
		{
			if(cur_node->getData()>max2)
				max2=cur_node->getData();

			cur_node=cur_node->getNext();
		}

		return max2;
	}


}

//Functions of class linkedList --end