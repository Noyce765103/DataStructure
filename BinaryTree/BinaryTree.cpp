#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;
typedef char T;
typedef struct BTNode
{
	T data;
	BTNode* left;
	BTNode* right;
}BTNode, *BTree;

BTree CreateBinaryTree()
{

	T info;
	cin >> info;
	if(info != '#')
	{
		BTNode* node = new BTNode;
		node->data = info;
		node->left = CreateBinaryTree();
		node->right = CreateBinaryTree();
		return node;
	}
	else	return NULL;
}

void visit(BTNode* node)
{
	cout<< node->data << ' ';
}

void PreOrder(BTree root)
{
	if(root != NULL)
	{
		visit(root);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

int main()
{
	BTree tree = NULL;
	tree = CreateBinaryTree();
	if(tree == NULL)	cout << "NULL"<<endl;
	PreOrder(tree);
}