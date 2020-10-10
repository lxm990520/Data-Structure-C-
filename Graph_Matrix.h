#include<iostream>
#include<string.h>
#define NUMVERTICES 100
#define INF 0X6FFFFFFF//INF宏定义 
int flag;
using namespace std;
int min(int *D,bool *S);
class Graph_Matrix//邻接矩阵存储图类定义 
{
public:
	int AdjMatrix[NUMVERTICES+1][NUMVERTICES+1];//邻接矩阵 
	string VexList[NUMVERTICES+1];//结点label存储 
	int n,e;//结点和边的个数 
	Graph_Matrix();//构造函数 
	void Add_Vertex(string s,int i){VexList[i]=s;AdjMatrix[i][i]=0;};//加入节点 
	void Add_Edge(int i,int j,int w){AdjMatrix[i][j]=w;};//加入边 
	void Dijkstra(int src,int dst);//Dijkstra求最短路径 
	void view(int *P,int src,int dst,int OGdst);	
	min(int *D,bool *S);//寻找当前与src路径最短的点 
	void view_Matrix();	
};
Graph_Matrix::Graph_Matrix()//将邻接矩阵初始化为INF 
{
	for (int i=1;i<=NUMVERTICES;i++)
	{
		for (int j=1;j<=NUMVERTICES;j++)
		{
			AdjMatrix[i][j]=INF;
		}
	}
}
void Graph_Matrix::Dijkstra(int src,int dst)//Dijkstra算法 
{
	int *D = new int[n+1];//存储src到各点当前最短距离 
	bool *S = new bool[n+1];//存储src到各点的最短距离是否已确定 
	int *P =new int[n+1];//存储src到该点最后经过的点，可递归输出路径 
	flag=1;
	for (int i=1;i<=n;i++)//初始化各数组 
	{
		D[i]=AdjMatrix[src][i];
		S[i]=false;
		P[i]=src;
	}
	S[src]=true;//先确定该点到自身的最短距离 
	for (int i=1;i<=n;i++)
	{
		int k = min(D,S);//寻找当前D中最小值下标 
		if (k==-1)//若未找到，则说明所有点最短路径已确定 
			break;
		S[k]=true;//确定该距离为最短距离 
		int j=1;
		while(j<=n)//更新D 
		{
			if (S[j])
			{
				j++;
				continue;
			}
			if ((D[k]+AdjMatrix[k][j])<D[j])//若经过刚确定的点使得距离变短，则更新D和P 
			{
				D[j]=D[k]+AdjMatrix[k][j];
				P[j]=k;
			}
			j++;
		}		
	}
	view(P,src,dst,dst);//递归显示最短路径 
	cout<<"Shortest Path is "<<D[dst]<<endl;//显示最短路径距离 

	
}
int Graph_Matrix::min(int *D,bool *S)//找未确定的点中路径最短的点 
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
	return k;//返回下标 
}
void Graph_Matrix::view(int *P,int src,int dst,int OGdst)//根据数组P递归显示最短路径 
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
		else//终点后不需要显示箭头，所以参数中带了一个不随递归改变的量OGdst（OriginalGangster） 
		cout<<VexList[dst]<<endl;
		return;
	}
}
void Graph_Matrix::view_Matrix()//打印邻接矩阵 
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
