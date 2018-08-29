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

//�ָ�����ʼ״̬ 
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
	LinkListNode *current = NULL;//����ָ��

	if (list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}

	tmp = (TLinklist*)list;
	current = &(tmp->head);

	for (int i = 0; i < pos; i++)
	{
		current = current->next;//����ָ���ƶ���Ҫ����λ�õ�ǰһ������ڵ�
	}
	node->next = current->next;//��Ҫ����Ľڵ�ָ�����λ�õĺ�һ���ڵ�
	current->next = node;//��Ҫ�����λ�õ�ǰһ���ڵ�ָ��Ҫ����Ľڵ�
	tmp->length++;

	return 0;
}

LinkListNode* LinkList_Get(LinkList *list, int pos)
{
	TLinklist *tmp = NULL;
	LinkListNode *current = NULL;//����ָ��

	if (list == NULL || pos < 0)
	{
		return NULL;
	}

	tmp = (TLinklist*)list;
	current = &(tmp->head);

	for (int i = 0; i < pos; i++)
	{
		current = current->next;//����ָ���ƶ���Ҫ����λ�õ�ǰһ������ڵ�
	}

	return current->next;
}

LinkListNode* LinkList_Delete(LinkList *list, int pos)
{
	TLinklist *tmp = NULL;
	LinkListNode *current = NULL;//����ָ��
	LinkListNode *delnode = NULL;//Ҫɾ���Ľڵ�

	if (list == NULL || pos < 0)
	{
		return NULL;
	}

	tmp = (TLinklist*)list;
	current = &(tmp->head);

	for (int i = 0; i < pos; i++)
	{
		current = current->next;//����ָ���ƶ���Ҫ����λ�õ�ǰһ������ڵ�
	}
	delnode = current->next;
	current->next = delnode->next;
	tmp->length--;

	return delnode;
}
