/*
* 用链表实现栈的链式存储，主要是将链表的头结点作为栈顶指针，然后在链表的头部进行插入和删除操作
* 需要注意的是因为使用的是链表，因此要遵循链表的业务结点模型（链表结点+业务），这就需要将栈的
* 业务结点作为链表的业务结点的一部分来实现栈结点和链表业务结点之间的转化。其中，包含栈业务结点的
* 链表业务结点（即栈结点）是需要malloc的，因此需要在删除的时候释放
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"
#include "linklist.h"

//因为是使用链表实现栈的链式存储，因此要符合链表的业务结点模型（链表结点+业务），此时的业务就是栈的业务
//typedef struct  teacher//链表的业务结点
//{
//	LinkListNode node;//链表结点
//	void *item;//栈的业务结点
//}teacher;

typedef struct  _Tag_LinkStackNode//链表的业务结点
{
	LinkListNode node;//链表结点
	void *item;//栈的业务结点
}TLinkStackNode;

LinkStack* LinkStack_Create() 
{
	return Linklist_Create();
}

void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);
	LinkList_Destory(stack);
}

//清空栈相当于清空一个线性表
//这将涉及到栈元素的生命周期的管理
//这是因为所有入栈的结点都是malloc的，因此清空时不仅
//要将栈元素弹出，并且要将它们全部释放
void LinkStack_Clear(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	while (LinkStack_Size(stack) > 0)
	{
		LinkStack_Pop(stack);//这个函数释放了栈结点
	}

	LinkList_Clear(stack);
}
//向栈添加元素相当于向线性表的头部插入元素
//void* item 栈的业务结点-----》链表的业务结点
int LinkStack_Push(LinkStack* stack, void* item)
{
	TLinkStackNode *temp = NULL;
	temp = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if (temp == NULL)
	{
		printf("malloc(sizeof(TLinkStackNode) error \n");
		return -1;
	}
	memset(temp,0,sizeof(TLinkStackNode));
	temp->item = item;

	int ret = LinkList_Insert(stack,(LinkListNode*)temp,0);
	if (ret != 0)
	{
		printf("LinkList_Insert() error \n");
		if(temp != NULL)
		{
			free(temp);
		}
		return ret;
	}

	return ret;
}

//从栈中删除元素相当于删除链表的头部元素（第一个业务结点）
//把线性表的业务结点  转化成 栈的业务结点
void* LinkStack_Pop(LinkStack* stack)
{
	void *item = NULL;
	TLinkStackNode *temp = NULL;
	temp = (TLinkStackNode*)LinkList_Delete(stack,0);
	if (temp == NULL)
	{
		printf("LinkList_Delete() error \n");
		return NULL;
	}

	item = temp->item;

	//因为在LinkList_Insert（）时malloc了链表的业务结点，所以要在LinkList_Delete（）时释放链表的业务结点
	free(temp);

	return item;
}

//获取栈顶元素相当于获取链表的0号位置
void* LinkStack_Top(LinkStack* stack)
{
	TLinkStackNode *temp = NULL;
	temp = (TLinkStackNode*)LinkList_Get(stack,0);
	if (temp == NULL)
	{
		printf("LinkList_Get() error \n");
		return NULL;
	}

	return temp->item;
}

//获取栈的长度相当获取链表的长度
int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}