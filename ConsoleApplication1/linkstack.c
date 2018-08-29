/*
* ������ʵ��ջ����ʽ�洢����Ҫ�ǽ������ͷ�����Ϊջ��ָ�룬Ȼ���������ͷ�����в����ɾ������
* ��Ҫע�������Ϊʹ�õ����������Ҫ��ѭ�����ҵ����ģ�ͣ�������+ҵ�񣩣������Ҫ��ջ��
* ҵ������Ϊ�����ҵ�����һ������ʵ��ջ��������ҵ����֮���ת�������У�����ջҵ�����
* ����ҵ���㣨��ջ��㣩����Ҫmalloc�ģ������Ҫ��ɾ����ʱ���ͷ�
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"
#include "linklist.h"

//��Ϊ��ʹ������ʵ��ջ����ʽ�洢�����Ҫ���������ҵ����ģ�ͣ�������+ҵ�񣩣���ʱ��ҵ�����ջ��ҵ��
//typedef struct  teacher//�����ҵ����
//{
//	LinkListNode node;//������
//	void *item;//ջ��ҵ����
//}teacher;

typedef struct  _Tag_LinkStackNode//�����ҵ����
{
	LinkListNode node;//������
	void *item;//ջ��ҵ����
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

//���ջ�൱�����һ�����Ա�
//�⽫�漰��ջԪ�ص��������ڵĹ���
//������Ϊ������ջ�Ľ�㶼��malloc�ģ�������ʱ����
//Ҫ��ջԪ�ص���������Ҫ������ȫ���ͷ�
void LinkStack_Clear(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	while (LinkStack_Size(stack) > 0)
	{
		LinkStack_Pop(stack);//��������ͷ���ջ���
	}

	LinkList_Clear(stack);
}
//��ջ���Ԫ���൱�������Ա��ͷ������Ԫ��
//void* item ջ��ҵ����-----�������ҵ����
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

//��ջ��ɾ��Ԫ���൱��ɾ�������ͷ��Ԫ�أ���һ��ҵ���㣩
//�����Ա��ҵ����  ת���� ջ��ҵ����
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

	//��Ϊ��LinkList_Insert����ʱmalloc�������ҵ���㣬����Ҫ��LinkList_Delete����ʱ�ͷ������ҵ����
	free(temp);

	return item;
}

//��ȡջ��Ԫ���൱�ڻ�ȡ�����0��λ��
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

//��ȡջ�ĳ����൱��ȡ����ĳ���
int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}