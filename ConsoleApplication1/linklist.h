#pragma once
typedef void LinkList;

typedef struct _tag_Link_list_Node 
{
	struct _tag_Link_list_Node *next;//�봫ͳ����ͬ���Ǵ�ͳ����ָ��Ĳ�������һ���ڵ������һ���ڵ��next
}LinkListNode;//����ڵ�

LinkListNode node;

LinkList* Linklist_Create();
void LinkList_Destory(LinkList *list);
void LinkList_Clear(LinkList *list);
int LinkList_Length(LinkList *list);
int LinkList_Insert(LinkList *list,LinkListNode *node,int pos);
LinkListNode* LinkList_Get(LinkList *list,int pos);
LinkListNode* LinkList_Delete(LinkList *list, int pos);
