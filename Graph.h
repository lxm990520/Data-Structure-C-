#include<iostream>
#include"Stack.h" 
#define NumVertices 100
using namespace std;
int judge_finish(int * visited,int n);
template<class cost_type>
class EdgeNode
{
	public:
		int adjvex;
		cost_type   cost;
		EdgeNode* next;
};

template<class cost_type,class vertex_type>
class VertexNode
{
	public:
		vertex_type	vertex;
		EdgeNode<cost_type>* firstedge;
};

template<class cost_type,class vertex_type>
class AdjGraph
{
//	private:
//		int n,e;
	public:
		VertexNode<cost_type,vertex_type> vexlist[NumVertices];
		int n,e;
		void CreateGraph();
		void DisplayGraph();
		void Display_indegree();
		void DFS_nonrecursive();
};

template<class cost_type,class vertex_type>
void AdjGraph<cost_type,vertex_type>::CreateGraph()
{
	cout<<"请输入结点个数，有向边数:"<<endl;
	cin>>n>>e;
	for (int i=0;i<n;i++)
	{
		cout<<"请输入结点名称:"<<endl;
		cin>>vexlist[i].vertex;
		vexlist[i].firstedge = NULL;
	}
	for (int i=0;i<e;i++)
	{
		int tail,head;
		cost_type weight;
		cout<<"请输入弧尾，弧头，权值:"<<endl;
		cin>>tail>>head>>weight;
		EdgeNode<cost_type>* p =new EdgeNode<cost_type>;
		p->adjvex = head;
		p->cost   = weight;
		p->next   = vexlist[tail].firstedge;
		vexlist[tail].firstedge = p;
	}
}
template<class cost_type,class vertex_type>
void AdjGraph<cost_type,vertex_type>::DisplayGraph()
{
	for (int i=0;i<n;i++)
	{
		vertex_type tail = vexlist[i].vertex;
		EdgeNode<cost_type>* temp = vexlist[i].firstedge;
		while(temp)
		{
			cout<<tail<<"->";
			cout<<vexlist[temp->adjvex].vertex;
			cout<<' ';
			temp = temp->next;
		}
		cout<<endl;
	}	
}

template<class cost_type,class vertex_type>
void AdjGraph<cost_type,vertex_type>::Display_indegree()
{
	int* count = new int[n];//动态分配数组 
	for (int i=0;i<n;i++)//数组清零 
		count[i]=0;
	for (int i=0;i<n;i++)//遍历邻接表，计算入度 
	{
		EdgeNode<cost_type>*temp = vexlist[i].firstedge;
		while(temp)
		{
			count[temp->adjvex]++;//每有一条边被指向，该结点入度+1 
			temp = temp->next;//指向下一个边 
		}
	}
	cout<<"各顶点入度:"<<endl;
	for (int i=0;i<n;i++)
		cout<<i<<'\t'<<count[i]<<endl;
	return;
}

template<class cost_type,class vertex_type>
void AdjGraph<cost_type,vertex_type>::DFS_nonrecursive()
{
	Stack<int> s={-1,100,{}};
	Stack<int>*stack_pointer = &s;
	int* visited = new int[n];
	for (int i=0;i<n;i++)
		visited[i]=0;
	int i;
	bool first = true;
	while((i=judge_finish(visited,n))!=-1)
	{
		EdgeNode<int>* temp;
		if (first)
		{
			first=!first;
			cout<<"请选择DFS起点:"<<endl;
			cin>>i;
			push(stack_pointer,i);
			cout<<vexlist[i].vertex<<' ';
			visited[i]=1;
			temp = vexlist[i].firstedge;
		}
		else
		{
			push(stack_pointer,i);
			cout<<vexlist[i].vertex<<' ';
			visited[i]=1;
			temp = vexlist[i].firstedge;
		}
//		cout<<"check1"<<endl;
		while(s.top>=0)
		{
//			cout<<"temp = "<<temp<<endl;
//			cout<<"s.top = "<<s.top<<endl;
			if (!temp)
			{
				int* unwanted;
//				cout<<"unwanted = "<<unwanted<<endl;
				s.top--;
				if (s.top>=0)
					temp = vexlist[get_top(stack_pointer)].firstedge;
			}
			else if (!visited[temp->adjvex])				
			{
				push(stack_pointer,temp->adjvex);
				cout<<vexlist[temp->adjvex].vertex<<' ';
				visited[temp->adjvex]=1;
				temp = vexlist[temp->adjvex].firstedge;				
			}

			else
			{
				temp = temp->next;
			}
//			cout<<"check2"<<endl;	
		}
//		cout<<"check3"<<endl;	

	}
//	cout<<"check4"<<endl;	
	return;
}
int judge_finish(int * visited,int n)
{
//	cout<<"check5"<<endl;
	for (int i=0;i<n;i++)
	{
		if (!visited[i])
		{
			return i;
		}
	}
	return -1;
}
