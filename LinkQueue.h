#include<iostream>
using namespace std;
template<class datatype>
class LinkNode//链表结点定义 
{
public:
	datatype  data;//数据域 
	LinkNode<datatype>* next;//指针域 
	LinkNode(datatype ele){data=ele;next=NULL;};//构造函数 
};
template<class datatype>
class LinkQueue//链式队列定义 
{
public:
	LinkNode<datatype>* head;//头结点指针 
	LinkNode<datatype>* rear;//尾结点指针 
	LinkQueue(){head = new LinkNode<datatype>(-1);rear =head;};//设头结点数据域为-1，以示区别 
	void Enqueue(datatype ele);//入队函数 
	datatype Dequeue();//出队函数 
	bool QueueEmpty(){if (head==rear) return true;else return false;};//判断队空函数 
	void view();//可视化调试函数 
};
template<class datatype>
void LinkQueue<datatype>::view(){//可视化调试函数 
LinkNode<datatype>* temp = head;
while(temp!=NULL)
{
	cout<<temp->data<<' ';
	temp = temp->next;
}
cout<<endl;
}
template<class datatype>
void LinkQueue<datatype>::Enqueue(datatype ele)//入队函数 
{
	LinkNode<datatype>* newnode = new LinkNode<datatype>(ele);
	rear->next = newnode;//新结点插入队尾 
	rear = newnode;	
}
template<class datatype>
datatype LinkQueue<datatype>::Dequeue()
{
	datatype temp;
	if (!head->next)//若队空，则返回-1 
		return -1;
	else
	{
		temp = head->next->data;//在头结点后删除结点 
		head->next=head->next->next;
		if (!head->next)
			rear=head;
		return (temp);		
	}
}
