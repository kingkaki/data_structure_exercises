#include <iostream>
#define MAXLEN 100
using namespace std;

class SeqList
{	

public:
	SeqList(int x)
	{
		len=0;
		int i,t;
		for(i=0;i<x;i++)
		{
			cout << "�������" << i+1 <<"��Ԫ��"<<endl; 
			cin >> t;
			if (len<MAXLEN)
			{
				data[len]=t;
				len++;
			}
		}
		cout << "˳������ɹ�"<<endl;
		
	};
	void insert_list(int key,int value);
	int delete_list(int key);
	void show_list();
	int search_list(int key);


private:
	int data[MAXLEN];
	int len;
	
	
};


void SeqList::insert_list(int key,int value)
{
	int i;
	
	if(len<MAXLEN&&key>0&&key<=len)
	{
		for (i=len;i>=key-1;i--)
		{
			data[i]=data[i-1];
		}
		data[key-1]=value;
		len++;
		cout << "����Ԫ�سɹ�"<<endl;
	}
	else
		cout << "����Ԫ��ʧ��"<<endl;
	
}


void SeqList::show_list()
{
	int i;
	for(i=0;i<len;i++)
	{
		cout << data[i] <<" ";
	}
	cout <<endl;
}


int SeqList::delete_list(int key)
{
	int i,t;
	if(key<0||key>len)
	{
		return 0;
		cout << "ɾ��ʧ��"<<endl;
	}

	t=data[key-1];
	for (i=key-1;i<len;i++)
	{
		data[i]=data[i+1];
	}
	len--;
	cout << "ɾ�����ݳɹ�"<<endl; 
	return t;
}


int SeqList::search_list(int key)
{
	if(key<0||key>len)
	{
		return 0;
		cout << "��ѯʧ��"<<endl;
	}
		
	
	cout << "��"<<key<<"λ����Ϊ"<<data[key-1]<<endl;
	return data[key-1]; 
}


int main (void)
{
	SeqList s(5);
	s.show_list();
	s.insert_list(2,9);
	s.delete_list(4);
	s.show_list();
	s.search_list(5);
 } 
