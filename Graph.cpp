#include<iostream>
using namespace std;
#define MAX 10

class Graph
{
public:
	int  n,e;//������ ���� 
	char vexs[MAX];
	int edges[MAX][MAX];
	int visited[MAX];//��¼�Ƿ񱻱����� 
	Graph(int n,int e); //���캯�� 
	void show();
	void DF_search(int i);
};

Graph::Graph(int n,int e)
{
	this->n=n;
	this->e=e;
	
	for(int i=0;i<n;i++) //�����������Ϣ 
	{
		cout<<"�������"<<i+1<<"���������Ϣ:";
		cin >> vexs[i];
	}
	cout<<"���㽨����ɣ�"<<endl; 
	
	for (int j=0;j<n;j++) //�ÿ� 
	{
		visited[j]=0;
		for (int k=0;k<n;k++)
			edges[j][k]=0; 
		
	}

	
	char ch1,ch2;
	for(int i=0;i<e;i++)//����ߵĹ�ϵ 
	{
		cout << "�뽨��"<<i+1<<"����"<<endl;
		cout<<"����1:";
		cin >> ch1;
		cout<<"����2:";
		cin >> ch2;
		cout << endl; 
		
		for (int j=0;j<n;j++)
		{
			for (int k=0;k<n;k++)
				if(ch1==vexs[j]&&ch2==vexs[k])
				{
					edges[j][k]=1;
					edges[k][j]=1;
				}
		}
		 
	}
	
	
	
}


void Graph::DF_search(int i)
{
	cout << vexs[i]<<" ";
	visited[i]=1;
	for(int j=0;j<n;j++)
		if (edges[i][j]=1&&visited[j]!=1)
			DF_search(j);	
 } 


void Graph::show()
{
	for(int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			cout<<edges[i][j]<<" ";
		cout << endl;
	}
	
		
}

int main(void)
{
	Graph g(4,5);
	g.show();
	g.DF_search(1);
}
