#ifndef tree_H
#define tree_H

class treeNode
{
	public:
		int data;
		treeNode *leftChild;
		treeNode *rightChild;

		treeNode();
};

treeNode::treeNode()
{
	leftChild=NULL;
	rightChild=NULL;
}

/*Binary Search Tree : starts here*/
class binarySearchTree
{
	public:
		treeNode *root;
		binarySearchTree();
		void insert(int value);
		//assuming tree has atleast one element
		int maximum();
};

binarySearchTree::binarySearchTree()
{
	root=NULL;
}

void binarySearchTree::insert(int value)
{
	treeNode *new_node=(treeNode *)malloc(sizeof(treeNode));
	new_node->data=value;

	if(root==NULL)
		root=new_node;

	else
	{
		treeNode *node_focus=root;
		while(((value<node_focus->data)&&(node_focus->leftChild!=NULL))
			||((value>node_focus->data)&&(node_focus->rightChild!=NULL)))
		{
			if(value<node_focus->data)
				node_focus=node_focus->leftChild;

			else if(value>node_focus->data)
				node_focus=node_focus->rightChild;
		}

		if(value<node_focus->data)
			node_focus->leftChild=new_node;

		else if(value>node_focus->data)
			node_focus->rightChild=new_node;
	}
}

int binarySearchTree::maximum()
{
	treeNode *node_focus=root;
	while(node_focus->rightChild!=NULL)
		node_focus=node_focus->rightChild;

	return node_focus->data;
}
/*Binary Search Tree : ends here*/

#endif