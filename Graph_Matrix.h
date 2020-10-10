#include<iostream>
#include<string.h>
#define NUMVERTICES 100
#define INF 0X6FFFFFFF//INF�궨�� 
int flag;
using namespace std;
int min(int *D,bool *S);
class Graph_Matrix//�ڽӾ���洢ͼ�ඨ�� 
{
public:
	int AdjMatrix[NUMVERTICES+1][NUMVERTICES+1];//�ڽӾ��� 
	string VexList[NUMVERTICES+1];//���label�洢 
	int n,e;//���ͱߵĸ��� 
	Graph_Matrix();//���캯�� 
	void Add_Vertex(string s,int i){VexList[i]=s;AdjMatrix[i][i]=0;};//����ڵ� 
	void Add_Edge(int i,int j,int w){AdjMatrix[i][j]=w;};//����� 
	void Dijkstra(int src,int dst);//Dijkstra�����·�� 
	void view(int *P,int src,int dst,int OGdst);	
	min(int *D,bool *S);//Ѱ�ҵ�ǰ��src·����̵ĵ� 
	void view_Matrix();	
};
Graph_Matrix::Graph_Matrix()//���ڽӾ����ʼ��ΪINF 
{
	for (int i=1;i<=NUMVERTICES;i++)
	{
		for (int j=1;j<=NUMVERTICES;j++)
		{
			AdjMatrix[i][j]=INF;
		}
	}
}
void Graph_Matrix::Dijkstra(int src,int dst)//Dijkstra�㷨 
{
	int *D = new int[n+1];//�洢src�����㵱ǰ��̾��� 
	bool *S = new bool[n+1];//�洢src���������̾����Ƿ���ȷ�� 
	int *P =new int[n+1];//�洢src���õ���󾭹��ĵ㣬�ɵݹ����·�� 
	flag=1;
	for (int i=1;i<=n;i++)//��ʼ�������� 
	{
		D[i]=AdjMatrix[src][i];
		S[i]=false;
		P[i]=src;
	}
	S[src]=true;//��ȷ���õ㵽�������̾��� 
	for (int i=1;i<=n;i++)
	{
		int k = min(D,S);//Ѱ�ҵ�ǰD����Сֵ�±� 
		if (k==-1)//��δ�ҵ�����˵�����е����·����ȷ�� 
			break;
		S[k]=true;//ȷ���þ���Ϊ��̾��� 
		int j=1;
		while(j<=n)//����D 
		{
			if (S[j])
			{
				j++;
				continue;
			}
			if ((D[k]+AdjMatrix[k][j])<D[j])//��������ȷ���ĵ�ʹ�þ����̣������D��P 
			{
				D[j]=D[k]+AdjMatrix[k][j];
				P[j]=k;
			}
			j++;
		}		
	}
	view(P,src,dst,dst);//�ݹ���ʾ���·�� 
	cout<<"Shortest Path is "<<D[dst]<<endl;//��ʾ���·������ 

	
}
int Graph_Matrix::min(int *D,bool *S)//��δȷ���ĵ���·����̵ĵ� 
{
	int temp=INF;
	int i=2;
	int k=-1;
	while(i<=n)
	{
		if ((D[i]<=temp)&&!S[i]) 
		{
			temp = D[i];
			k = i;	
		}
		i++;
	}
	return k;//�����±� 
}
void Graph_Matrix::view(int *P,int src,int dst,int OGdst)//��������P�ݹ���ʾ���·�� 
{
	if (src==dst)
	{
		cout<<VexList[src]<<"->";
		return;
	}
	else
	{
		view(P,src,P[dst],OGdst);
		if (dst!=OGdst)
		cout<<VexList[dst]<<"->";
		else//�յ����Ҫ��ʾ��ͷ�����Բ����д���һ������ݹ�ı����OGdst��OriginalGangster�� 
		cout<<VexList[dst]<<endl;
		return;
	}
}
void Graph_Matrix::view_Matrix()//��ӡ�ڽӾ��� 
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (AdjMatrix[i][j]==INF)
				cout<<"Inf"<<'\t';
			else
				cout<<AdjMatrix[i][j]<<'\t';
		}
		cout<<endl;
	}
}
