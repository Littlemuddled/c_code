#define  _CRT_SECURE_NO_WARNINGS 1

//每个人的信息：
//姓名+年龄+性别+电话+地址
//1.增加信息
//2.删除指定人的信息
//3.修改指定人的信息
//4.查找指定人的信息
//5.通信录信息排序
//内存动态增长的版本
//通讯录初始化存放3个人信息，当初始化空间放满时，增加2个人的信息



#include"contact.h"


void menu()
{
	printf("**********************************\n");
	printf("*** 1.add     2.del   3.search ***\n");
	printf("*** 4.modify  5.sort  6.print  ***\n");
	printf("***           0.exit           ***\n");
	printf("**********************************\n");
}
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT,
};
int main()
{
	int input = 0;
	//创建通讯录
	Contact con;
	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch(input)
		{
		case ADD://增加人的信息
			AddContact(&con);
			break;
		case DEL://删除
			DelContact(&con);
			break;
		case SEARCH://查找
			SearchContact(&con);
			break;
		case MODIFY://修改
			ModifyContact(&con);
			break;
		case SORT://排序
			SortContact(&con);
			break;
		case PRINT://打印
			PrintContact(&con);
			break;
		case EXIT://退出
			//销毁通讯录
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}