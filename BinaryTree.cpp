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

class BTree
{
public:
	BTreeNode *root;//根节点 
	BTreeNode* create_btree();//前序创建二叉树 
	BTree()
	{		
		root = create_btree();
	}
	void show_inorder();//中序遍历 
	void show_preorder();//前序遍历 
	void show_traorder();//后序遍历 
	

	//求二叉树深度 
	int depth();

	
	//求二叉树节点个数
	int size();
	 
protected:	
		//重载形式 
	void show_inorder(BTreeNode *t);//中序遍历 
	void show_preorder(BTreeNode *t);//前序遍历 
	void show_traorder(BTreeNode *t);//后序遍历 
	int depth(BTreeNode *t);
	void size(BTreeNode *t,int &x);
	
	

};



BTreeNode* BTree::create_btree()
{
	int ch;
	BTreeNode* t;
	ch = getch();
	printf("%c\n",ch); 
	if(ch=='*')
	{
		return NULL;
	}
	else 
	{
		t = new BTreeNode;
		t->data = ch;
				
		printf("请输入%c的左孩子\n",t->data);
		t->lchild = create_btree();
		printf("请输入%c的右孩子\n",t->data);
		t->rchild = create_btree();
		return t;
	}
	
}

void BTree::show_inorder(BTreeNode *t)
{
	if(t==NULL)
		return;
	else
	{		
		show_inorder(t->lchild);
		printf("%c",t->data);
		show_inorder(t->rchild);
	}
}


void BTree::show_inorder()
{
	show_inorder(root);
	cout<<endl;
 } 
 
 void BTree::show_preorder(BTreeNode *t)
{
	if(t==NULL)
		return;
	else
	{
		printf("%c",t->data);
		show_preorder(t->lchild);
		show_preorder(t->rchild);
	}
}


void BTree::show_preorder()
{
	show_preorder(root);
	cout<<endl;
 } 
 
  void BTree::show_traorder(BTreeNode *t)
{
	if(t==NULL)
		return;
	else
	{	
		show_traorder(t->lchild);
		show_traorder(t->rchild);
		printf("%c",t->data);
	}
}


void BTree::show_traorder()
{
	show_traorder(root);
	cout<<endl;
 } 

int BTree::depth()
{
	return depth(root);
}

int BTree::depth(BTreeNode *t)
{
	if(t==NULL)
		return 0;
	else		//深度为max{左子树，右子树}+1 
	{
		int ldepth = depth(t->lchild);
		int rdepth = depth(t->rchild);
		return (ldepth>rdepth?ldepth:rdepth)+1; //返回大的子树值 
	}
}


int BTree::size()
{
	int x=0;
	int &t=x;
	size(root,t);
	return t;
}

void BTree::size(BTreeNode *t,int &x)
{
	if(t==NULL)
		return;
	else//若不为空，节点数量t++ 
	{
		x++;
		size(t->lchild,x);
		size(t->rchild,x);
	}
}




int main(void)
{
	BTree t;
	t.create_btree();
	t.show_inorder();
	t.show_preorder();
	t.show_traorder();
	cout << t.depth()<<endl; 
	cout << t.size();
}

