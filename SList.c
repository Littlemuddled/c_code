#define  _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

//��ӡ
void SListPrint(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);//��ӡ����
		cur = cur->next;//��һ����ַ��ָ����һ�����ݵĵ�ַ��
	}
	printf("NULL");
}

//����
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
	return NULL;//û�ҵ�����NULL
}

//���ٿռ�
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTDataType));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//β��
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
 
	//�жϿ�ʼ�ڵ��Ƿ�ΪNULL
	if (*pphead = NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//��β�ڵ��ָ��
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//β�ڵ㣬�����½ڵ㣨β�ڵ�ԭ��ΪNULL��β�壺���¿��ٵĿռ�ĵ�ַnewnode����ԭ��β�ڵ��NULL��
		tail->next = newnode;
	}
}

//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	SLTNode* next = (*pphead)->next;//��freeǰ����ڵ�ĵ�ַ
	free(*pphead);
	*pphead = next;
}

//βɾ
void SListPopBack(SLTNode** pphead)
{
	//1.��
	if (*pphead = NULL)
	{
		return;
	}
	//2.һ���ڵ�
	else if ((*pphead)->next = NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//����ڵ�
	else
	{
		SLTNode* prev = NULL;//��¼ǰһ���ڵ�
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;//��ǰһ���ڵ����ΪNULL
	}
}


//��posǰ�����x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);//����ڵ�һ���ڵ�֮ǰ������൱��ͷ��
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

//ɾ��pos��ֵ
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);//���ɾ����һ���ڵ���൱��ͷɾ
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