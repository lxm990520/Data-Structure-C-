#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef int T;
typedef struct Node{
	T data;
	struct Node* next;//���ṹ�嶨�� 
}LNode,*pNode,*LinkList;
int InitList(LinkList * L)//��ʼ������ 
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if (!L)//�ռ����ʧ���������ʾ 
	{
		printf("Error!\n");
		return 0;
	}
	(*L)->next = NULL;
	return 1;
	
}
int Find(LinkList L,pNode L2)//��������Ѱ��L2��㣬�����±� 
{
	int i=0;
	pNode temp = L->next;
	while (temp)
	{
		if (temp == L2)
			return i;
		temp = temp->next;
		i++;
	}
}

int Add(LinkList L,T x)//����������ӽ�� 
{
	pNode pointer = L;
	while (pointer->next)
		pointer = pointer->next;
	pNode temp = (pNode)malloc(sizeof(LNode));
	pointer->next = temp;
	temp->data = x;
	temp->next = NULL;
	return 1;	
}
int Delete(LinkList L,int pos)//��������ɾ����� 
{
	pNode pointer = L->next;
	int i=0;
	while (i++<=pos-2)
		pointer = pointer->next;
	LNode temp = *(pointer->next);
	free(pointer->next);
	pointer->next=temp.next;
	return 1;	
}
int getElement(LinkList L,int pos)//�����±�ȡ�������н������ 
{
	pNode pointer = L;
	int i=0;
	while (i++<=pos)
		pointer = pointer->next;
	return pointer->data;
}
void view(LinkList L)//��������������� 
{
	pNode pointer = L;
	while (pointer->next)
	{
		pointer = pointer->next;
		printf("%d  ",pointer->data);
	}
	printf("\n");
}
