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
	BTreeNode *root;//���ڵ� 
	BTreeNode* create_btree();//ǰ�򴴽������� 
	BTree()
	{		
		root = create_btree();
	}
	void show_inorder();//������� 
	void show_preorder();//ǰ����� 
	void show_traorder();//������� 
	

	//���������� 
	int depth();

	
	//��������ڵ����
	int size();
	 
protected:	
		//������ʽ 
	void show_inorder(BTreeNode *t);//������� 
	void show_preorder(BTreeNode *t);//ǰ����� 
	void show_traorder(BTreeNode *t);//������� 
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
				
		printf("������%c������\n",t->data);
		t->lchild = create_btree();
		printf("������%c���Һ���\n",t->data);
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
	else		//���Ϊmax{��������������}+1 
	{
		int ldepth = depth(t->lchild);
		int rdepth = depth(t->rchild);
		return (ldepth>rdepth?ldepth:rdepth)+1; //���ش������ֵ 
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
	else//����Ϊ�գ��ڵ�����t++ 
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

