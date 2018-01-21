#include <iostream>
using namespace std;
#define MAXLEN 100


class SeqStack
{
public:
	SeqStack(int n)
	{
		top=-1;
		int i,x;
		
		for (i=0;i<n;i++)
		{
			cout << "�������" << i+1 <<"��Ԫ��"<<endl; 
			cin >> x;
			if(!is_full())
			 {
			 	top++;
			 	data[top]=x;
			  } 
		}
		cout << "ջ�����ɹ�" <<endl; 
		
	};
	int is_full();
	int is_empty(); 
	void push(int value);
	int pop();
	void show();
	
		
private:
	int top;
	int data[MAXLEN];
	
	
 } ;
 
int SeqStack::is_full()
 {
 	if(top==(MAXLEN-1))
 	{
 		return 1;
	 }
	else
	{
		return 0;
	}
 }
 
int SeqStack::is_empty()
 {
 	if(top==-1)
 	{
 		return 1;
	 }
	else
	{
		return 0;
	}
 }
 
 
 
void SeqStack::push(int value)
 {
 	if(!is_full())
	 {
	 	top++;				//push����+top���������� 
	 	data[top]=value;	 	
	 	cout << "����ѹ��ɹ�" <<endl;
	 	
	  } 
	else
	{
		cout << "����ѹ�����" <<endl;	

	}
 }
 
 
int SeqStack::pop ()
{
	if(!is_empty())
	{
		int t;		
		t=data[top];		//pop���ȼ������ݺ�-top 
		top--;
		return t;
		//cout << "���ݵ����ɹ�" <<endl;
	}
	else
	{
		cout << "���ݵ�������" <<endl;
		return 0;
	}
}


 int main(void)
 {
 	SeqStack s(3);
// 	cout << s.top <<endl;
 	cout << s.pop() <<endl;
// 	cout << s.top <<endl;
 	cout << s.pop() <<endl;
//	cout << s.top <<endl;
 	cout << s.pop() <<endl;
// 	cout << s.top <<endl;
 	s.push(6);
// 	
 	cout << s.pop() <<endl;
 	
 }
