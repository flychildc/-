#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tag_Linklist
{
	int length;
	LinkListNode head;
}TLinklist;

LinkList* Linklist_Create() 
{
	TLinklist *tmp = (TLinklist*)malloc(sizeof(TLinklist));
	if (tmp == NULL)
	{
		printf(" Linklist_Create() error");
		return NULL;
	}
	memset(tmp,0,sizeof(TLinklist));

	return tmp;
}

void LinkList_Destory(LinkList *list)
{
	/*TLinklist *tmp = NULL;
	if (list == NULL)
	{
		printf("LinkList_Destory error");
		return;
	}
	tmp = (TLinklist*)list;
	free(tmp);*/
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
}

//恢复到初始状态 
void LinkList_Clear(LinkList *list)
{
	TLinklist *tmp = NULL;
	if (list == NULL)
	{
		printf("LinkList_Destory error");
		return;
	}
	tmp = (TLinklist*)list;
	tmp->length = 0;
	tmp->head.next = NULL;
}

int LinkList_Length(LinkList *list)
{
	TLinklist *tmp = NULL;
	if (list == NULL)
	{
		printf("LinkList_Destory error");
		return;
	}
	tmp = (TLinklist*)list;

	return tmp->length;
}

int LinkList_Insert(LinkList *list, LinkListNode *node, int pos)
{
	TLinklist *tmp = NULL;
	LinkListNode *current = NULL;//辅助指针

	if (list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}

	tmp = (TLinklist*)list;
	current = &(tmp->head);

	for (int i = 0; i < pos; i++)
	{
		current = current->next;//辅助指针移动到要插入位置的前一个链表节点
	}
	node->next = current->next;//将要插入的节点指向插入位置的后一个节点
	current->next = node;//将要插入的位置的前一个节点指向要插入的节点
	tmp->length++;

	return 0;
}

LinkListNode* LinkList_Get(LinkList *list, int pos)
{
	TLinklist *tmp = NULL;
	LinkListNode *current = NULL;//辅助指针

	if (list == NULL || pos < 0)
	{
		return NULL;
	}

	tmp = (TLinklist*)list;
	current = &(tmp->head);

	for (int i = 0; i < pos; i++)
	{
		current = current->next;//辅助指针移动到要插入位置的前一个链表节点
	}

	return current->next;
}

LinkListNode* LinkList_Delete(LinkList *list, int pos)
{
	TLinklist *tmp = NULL;
	LinkListNode *current = NULL;//辅助指针
	LinkListNode *delnode = NULL;//要删除的节点

	if (list == NULL || pos < 0)
	{
		return NULL;
	}

	tmp = (TLinklist*)list;
	current = &(tmp->head);

	for (int i = 0; i < pos; i++)
	{
		current = current->next;//辅助指针移动到要插入位置的前一个链表节点
	}
	delnode = current->next;
	current->next = delnode->next;
	tmp->length--;

	return delnode;
}
