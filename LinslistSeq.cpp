#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class List:public Node
{
public:	
	Node *head;
	List(int n)
	{
		head = new Node;
		head->next = NULL; //初始化head指针 
		
		Node *s,*last;
		last = head;
		int i;
		
		for (i=0;i<n;i++)
		{
			
			s = new Node;
			cout << "请输入第" << i+1 <<"个整数" << endl;
			cin >> s->data ;
			s->next=NULL;
			last->next = s;
			last = s;
			
		 } 
		 
		 cout << "链表创建成功"<<endl; 
	};
	void insert_list(int key,int value);
	int  delete_list(int key);
	int  search_list(int key);
	void show_list();
	void reverse();
	
	
};
void List::reverse()
{
	Node *t = head->next;
     if(NULL == t || NULL == t->next)  
    {  
        return;  
    }  
    Node *p1 = t, *p2 = t->next, *p3;  
    while(NULL != p2)  
    {  
        p3 = p2->next;  
        p2->next = p1;  
        p1 = p2;  
        p2 = p3;  
    }  
    t->next = NULL;
    head->next = p1;
    
    
}

void List::insert_list(int key,int value)
{
	int i;
	Node *p,*s;
	p=head;
	
	s=new Node;  //生成新节点 
	s->data=value;
	
	
	for(i=1;i<key;i++) //定位插入点 
	{
		if(p->next!=NULL)
		{
			p=p->next;
		}
	}
	
	if(p->next!=NULL&&i==key)
	{
		s->next = p->next;
		p->next = s;
		cout << "插入成功" <<endl; 	
	}
	else
		cout << "插入错误" <<endl; 
	
}

int  List::delete_list(int key)
{
	int i;
	Node *t,*p;
	p=head;
	
	for(i=1;i<key;i++)  //定位插入点 
	{
		if(p->next!=NULL)
		{
			p=p->next;
		}
	} 
	
	if(p->next!=NULL&&i==key)
	{
		int r;
		t = p->next;
		r=t->data;
		p->next = t->next;
		delete t;
		cout << "删除成功" <<endl;
		return r;		
		
	}	
	else
	{
		cout << "删除失败"<<endl; 
	}
		
		
		
}



int   List::search_list(int key)
{
	int i;
	Node *p;
	p=head;
	
	for(i=1;i<=key;i++)  //定位插入点 
	{
		if(p->next!=NULL)
		{
			p=p->next;
		}
	}
	if(key+1==i)
	{
		cout << "第" << key <<"位元素为"<<p->data;  
		return p->data;
	}
	else 
		cout << "索引失败" <<endl; 
}

void List::show_list()
{
	Node *p;
	p = head->next;
	while(p!=NULL)
	{
		cout << p->data <<endl;
		p = p->next;
	}
}



int main(void)
{
	List a(3);
	a.show_list();
	a.reverse();
	a.show_list();
//	int x=4,y=5;
//	List a(x),b(y);
//	int i,j;
//	
//	if(x>y)
//	{		
//		for(i=1;i<=x-y;i++)   //输出多余的 
//			cout<<a.search_list(i)<<" ";
//			
//		for (i=1;i<(x>y?x:y);i++)  //输出相加的
//		{
//			cout << a.search_list(i+x-y)+b.search_list(i)<<" ";
//		}
//		
//	}
//	else
//	{
//		for(i=1;i<=y-x;i++)   //输出多余的 
//			cout<<a.search_list(i)<<" ";
//			
//		for (i=1;i<(x>y?x:y);i++)  //输出相加的
//		{
//			cout << a.search_list(i)+b.search_list(i+y-x)<<" ";
//		}
//		
//	}
	
 } 
