#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef int T;
typedef struct Node{
	T data;
	struct Node* next;//结点结构体定义 
}LNode,*pNode,*LinkList;
int InitList(LinkList * L)//初始化链表 
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if (!L)//空间分配失败则错误提示 
	{
		printf("Error!\n");
		return 0;
	}
	(*L)->next = NULL;
	return 1;
	
}
int Find(LinkList L,pNode L2)//在链表中寻找L2结点，返回下标 
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

int Add(LinkList L,T x)//在链表中添加结点 
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
int Delete(LinkList L,int pos)//在链表中删除结点 
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
int getElement(LinkList L,int pos)//根据下标取得链表中结点数据 
{
	pNode pointer = L;
	int i=0;
	while (i++<=pos)
		pointer = pointer->next;
	return pointer->data;
}
void view(LinkList L)//依次输出链表数据 
{
	pNode pointer = L;
	while (pointer->next)
	{
		pointer = pointer->next;
		printf("%d  ",pointer->data);
	}
	printf("\n");
}
