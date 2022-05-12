#define  _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

//打印
void SListPrint(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);//打印数据
		cur = cur->next;//下一个地址（指向下一个数据的地址）
	}
	printf("NULL");
}

//查找
SLTNode* SListFind(SLTNode** pphead, SLTDataType x)
{
	SLTNode* cur = *pphead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;//没找到返回NULL
}

//开辟空间
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTDataType));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
 
	//判断开始节点是否为NULL
	if (*pphead = NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾节点的指针
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//尾节点，链接新节点（尾节点原本为NULL，尾插：将新开辟的空间的地址newnode给到原本尾节点的NULL）
		tail->next = newnode;
	}
}

//头插
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//头删
void SListPopFront(SLTNode** pphead)
{
	SLTNode* next = (*pphead)->next;//在free前保存节点的地址
	free(*pphead);
	*pphead = next;
}

//尾删
void SListPopBack(SLTNode** pphead)
{
	//1.空
	if (*pphead = NULL)
	{
		return;
	}
	//2.一个节点
	else if ((*pphead)->next = NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//多个节点
	else
	{
		SLTNode* prev = NULL;//记录前一个节点
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;//将前一个节点的置为NULL
	}
}


//在pos前面插入x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);//如果在第一个节点之前插入就相当于头插
	}
	else
	{
		SLTNode* newnode = BuySListNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}

//删除pos的值
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);//如果删除第一个节点就相当于头删
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}