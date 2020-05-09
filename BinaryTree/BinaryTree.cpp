#include<iostream>
#include<cstdlib>
#include<stack>
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

void InOrder(BTree root)
{
	if(root != NULL)
	{
		InOrder(root->left);
		visit(root);
		InOrder(root->right);
	}
}

void PreOrderWithStack(BTree root)
{
	stack<BTNode*> st;
	BTNode *p = root;
	while(p || !st.empty())
	{
		if(p)
		{
			visit(p);
			st.push(p);
			p = p->left;
		}
		else
		{
			p = st.top();
			st.pop();
			p = p->right;
		}
		
	}
}

int main()
{
	BTree tree = NULL;
	tree = CreateBinaryTree();	//测试用例：AB#C##DE##FG#H##I##
	if(tree == NULL)	cout << "NULL"<<endl;
	//PreOrderWithStack(tree);
	InOrder(tree);
}