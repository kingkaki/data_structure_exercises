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
			cout << "请输入第" << i+1 <<"个元素"<<endl; 
			cin >> x;
			if(!is_full())
			 {
			 	top++;
			 	data[top]=x;
			  } 
		}
		cout << "栈创建成功" <<endl; 
		
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
	 	top++;				//push中先+top后增加数据 
	 	data[top]=value;	 	
	 	cout << "数据压入成功" <<endl;
	 	
	  } 
	else
	{
		cout << "数据压入错误" <<endl;	

	}
 }
 
 
int SeqStack::pop ()
{
	if(!is_empty())
	{
		int t;		
		t=data[top];		//pop中先减少数据后-top 
		top--;
		return t;
		//cout << "数据弹出成功" <<endl;
	}
	else
	{
		cout << "数据弹出错误" <<endl;
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
