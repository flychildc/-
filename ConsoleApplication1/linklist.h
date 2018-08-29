#pragma once
typedef void LinkList;

typedef struct _tag_Link_list_Node 
{
	struct _tag_Link_list_Node *next;//与传统链表不同，非传统链表指向的并非是下一个节点而是下一个节点的next
}LinkListNode;//链表节点

LinkListNode node;

LinkList* Linklist_Create();
void LinkList_Destory(LinkList *list);
void LinkList_Clear(LinkList *list);
int LinkList_Length(LinkList *list);
int LinkList_Insert(LinkList *list,LinkListNode *node,int pos);
LinkListNode* LinkList_Get(LinkList *list,int pos);
LinkListNode* LinkList_Delete(LinkList *list, int pos);
