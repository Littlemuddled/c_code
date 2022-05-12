#define  _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;//数据
	struct SListNode* next;//节点（下一个结构体类型数据的地址）
}SLTNode;


void SListPrint(SLTNode** pphead);//打印
SLTNode* SListFind(SLTNode** pphead, SLTDataType x);//查找

void SListPushBack(SLTNode** pphead, SLTDataType x);//尾插
void SListPushFront(SLTNode** pphead, SLTDataType x);//头插
void SListPopFront(SLTNode** pphead);//头删
void SListPopBack(SLTNode** pphead);//尾删

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//在pos前面插入x
void SListErase(SLTNode** pphead, SLTNode* pos);//删除pos的值
