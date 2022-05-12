#define  _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;//����
	struct SListNode* next;//�ڵ㣨��һ���ṹ���������ݵĵ�ַ��
}SLTNode;


void SListPrint(SLTNode** pphead);//��ӡ
SLTNode* SListFind(SLTNode** pphead, SLTDataType x);//����

void SListPushBack(SLTNode** pphead, SLTDataType x);//β��
void SListPushFront(SLTNode** pphead, SLTDataType x);//ͷ��
void SListPopFront(SLTNode** pphead);//ͷɾ
void SListPopBack(SLTNode** pphead);//βɾ

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//��posǰ�����x
void SListErase(SLTNode** pphead, SLTNode* pos);//ɾ��pos��ֵ
