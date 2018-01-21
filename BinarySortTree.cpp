#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

class BTreeNode
{
public:
	int data;
	BTreeNode *lchild,*rchild;
};


class BSTree
{
public:
	BTreeNode *root;
	BSTree()
	{	
		
		create_bstree(root);
		cout<<endl<<"二叉排序树创建成功"<<endl; 
	}
	void show();


	void show(BTreeNode* t);
	void create_bstree(BTreeNode* t);
	void insert(BTreeNode* &t,int x);
};

void BSTree::insert(BTreeNode* &t,int x) 
{
	if(t == NULL)
	{
		t = new BTreeNode;
		t->data = x;
		t->lchild = NULL;
		t->rchild = NULL;
		return ;		

	}
	if(x<t->data)
		insert(t->lchild,x);
	else
		insert(t->rchild,x);
	
}


void BSTree::create_bstree(BTreeNode* t)
{
	root=NULL;
	int ch;
	while(1)
	{
		ch = getch();
		printf("%c",ch);
		if(ch=='*')
			break;
		insert(root,ch);
		 
	}

}

void BSTree::show(BTreeNode *t)
{
	
	if(t==NULL)
	{
		return;
	}
		
	else
	{		
		show(t->lchild);
		printf("%c",t->data);
		show(t->rchild);
	}
}

void BSTree::show()
{
	
	show(root);
	cout<<endl;
 } 
 
 
main()
{
	BSTree t;
	t.show();
}
