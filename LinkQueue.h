#include<iostream>
using namespace std;
template<class datatype>
class LinkNode//�����㶨�� 
{
public:
	datatype  data;//������ 
	LinkNode<datatype>* next;//ָ���� 
	LinkNode(datatype ele){data=ele;next=NULL;};//���캯�� 
};
template<class datatype>
class LinkQueue//��ʽ���ж��� 
{
public:
	LinkNode<datatype>* head;//ͷ���ָ�� 
	LinkNode<datatype>* rear;//β���ָ�� 
	LinkQueue(){head = new LinkNode<datatype>(-1);rear =head;};//��ͷ���������Ϊ-1����ʾ���� 
	void Enqueue(datatype ele);//��Ӻ��� 
	datatype Dequeue();//���Ӻ��� 
	bool QueueEmpty(){if (head==rear) return true;else return false;};//�ж϶ӿպ��� 
	void view();//���ӻ����Ժ��� 
};
template<class datatype>
void LinkQueue<datatype>::view(){//���ӻ����Ժ��� 
LinkNode<datatype>* temp = head;
while(temp!=NULL)
{
	cout<<temp->data<<' ';
	temp = temp->next;
}
cout<<endl;
}
template<class datatype>
void LinkQueue<datatype>::Enqueue(datatype ele)//��Ӻ��� 
{
	LinkNode<datatype>* newnode = new LinkNode<datatype>(ele);
	rear->next = newnode;//�½������β 
	rear = newnode;	
}
template<class datatype>
datatype LinkQueue<datatype>::Dequeue()
{
	datatype temp;
	if (!head->next)//���ӿգ��򷵻�-1 
		return -1;
	else
	{
		temp = head->next->data;//��ͷ����ɾ����� 
		head->next=head->next->next;
		if (!head->next)
			rear=head;
		return (temp);		
	}
}
