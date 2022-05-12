#define  _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushFront(&plist, 0);

	SListPopFront(&plist);
	SListPopBack(&plist);

	//在3前面插入一个30
	SLTNode* pos = SListFind(&plist, 3);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}
	
	//删除2
	pos = SListFind(&plist, 2);
	if (pos)
	{
		SListErase(&plist, pos);
	}

	SListPrint(&plist);
}

int main()
{
	TestSList1();
	return 0;
}
