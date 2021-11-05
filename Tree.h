#ifndef _TREE_H_
#define _TREE_H_
#include<iostream>
using namespace std;
//========================================
//Structs
//Tree's Node
template<class T>
struct TNode
{
	T info;
	TNode<T>* left;
	TNode<T>* right;
};
//Tree's structure
template<class T>
struct BTree
{
	TNode<T>* root;
};
//========================================
//Functions
template<class T>
void initBTree(BTree<T>& tree)
{
	tree.root = NULL;
}
template<class T>
TNode<T>* createTNode(T x)
{
	TNode<T>* p = new TNode<T>;
	if (!p)
	{
		return NULL;
	}
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
template<class T>
int insertTNode(TNode<T>*& root, TNode<T>* p)
{
	if (!p)
	{
		return 0;
	}
	if (!root)
	{
		root = p;
		return 1;
	}
	if (!root->left)
	{
		insertTNode(root->left, p);
	}
	else
	{
		if (!root->right)
		{
			insertTNode(root->right, p);
		}
		else
		{
			int x = rand() % 2;// Rand chan le 
			if (x == 0)
			{
				insertTNode(root->left, p);// Rand chan
			}
			else
			{
				insertTNode(root->right, p);// Rand le
			}
		}
	}
	return 1;
}

//Prefix
//Ap dung con tro ham
template<class T>
void NLR(TNode<T>* root, void (*show)(TNode<T>*))
{
	if (root == NULL)
	{
		return;
	}
	//Xu ly
	show(root);
	NLR(root->left, show);
	NLR(root->right, show);
}
template<class T>
void NRL(TNode<T>* root, void (*show)(TNode<T>*))
{
	if (root == NULL)
	{
		return;
	}
	//Xu ly
	show(root);
	NRL(root->right,show);
	NRL(root->left,show);
}
//Infix
template<class T>
void LNR(TNode<T>* root, void (*show)(TNode<T>*))
{
	if (root == NULL)
	{
		return;
	}
	LNR(root->left,show);
	//Xu ly
	show(root);
	LNR(root->right,show);
}
template<class T>
void RNL(TNode<T>* root, void (*show)(TNode<T>*))
{
	if (root == NULL)
	{
		return;
	}
	RNL(root->left,show);
	//Xu ly
	show(root);
	RNL(root->right,show);
}
//Postfix
template<class T>
void LRN(TNode<T>* root, void (*show)(TNode<T>*))
{
	if (root == NULL)
	{
		return;
	}
	LRN(root->left,show);
	LRN(root->right,show);
	//Xu ly
	show(root);
}
template<class T>
void RLN(TNode<T>* root, void (*show)(TNode<T>*))
{
	if (root == NULL)
	{
		return;
	}
	RLN(root->left,show);
	RLN(root->right,show);
	//Xu ly
	show(root);
}
template<class T>
int insertTNodeLeft(TNode<T>* root, TNode<T>* p)
{
	if (!root || !p)
	{
		return 0;// Fail
	}
	if (root->left != NULL)// Node left already exist
	{
		return 0;
	}
	root->left = p;
	return 1;// Ok
}
template<class T>
int insertTNodeRight(TNode<T>* root, TNode<T>* p)
{
	if (!root || !p)
	{
		return 0;
	}
	if (root->right != NULL)
	{
		return 0;
	}
	root->right = p;
	return 1;
}
template<class T>
int countTNode(TNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + countTNode(root->left) + countTNode(root->right);
}
template<class T>
int countTNodeLeaf(TNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int s = countTNodeLeaf(root->left) + countTNodeLeaf(root->right);
	return root->left == NULL && root->right == NULL ? 1 + s : s;
}
template<class T>
int countTNode1ChildNode(TNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int s = countTNode1ChildNode(root->left) + countTNode1ChildNode(root->right);
	return root->left == NULL || root->right == NULL ? 1 + s : s;
}
template<class T>
int countTNode2ChildNode(TNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int s = countTNode2ChildNode(root->left) + countTNode2ChildNode(root->right);
	return root->left != NULL && root->right != NULL ? 1 + s : s;
}
template<class T> 
double sumOfTNode(TNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int s = sumOfTNode(root->left) + sumOfTNode(root->right);
	return s + root->info;
}
template<class T>
double sumOfTNodeLeaf(TNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int s = sumOfTNodeLeaf(root->left) + sumOfTNodeLeaf(root->right);
	return root->left == NULL && root->right == NULL ? s + root->info : s;
}
template<class T>
double sumOfTNode1Child(TNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int s = sumOfTNode1Child(root->left) + sumOfTNode1Child(root->right);
	return root->left == NULL || root->right == NULL ? s + root->info : s;
}
template<class T>
double sumOfTNode2Child(TNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int s = sumOfTNode2Child(root->left) + sumOfTNode2Child(root->right);
	return root->left != NULL && root->right != NULL ? s + root->info : s;
}
template<class T>
int heightOfTree(TNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int hl = heightOfTree(root->left);
	int hr = heightOfTree(root->right);
	return hl > hr ? hl + 1 : hr + 1;
}
#endif // !_TREE_H_
