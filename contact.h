#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME 20
#define MAX_SET 10
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_SZ 3 //默认能存放的空间为3
#define INC_SZ 2  //每次增加2

#define MAX 100

//类型的定义
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char set[MAX_SET];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


//通讯录
typedef struct Contact
{
	PeoInfo* deta;//指向动态申请的空间，存放联系人信息
	int sz;//记录当前通讯录中有效信息的个数
	int max_capacity;//记录当前通讯录的最大容量
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//打印联系人信息
void PrintContact(const Contact* pc); //只是打印信息不会改变原有信息 用const修饰

//删除联系人
void DelContact(Contact* pc);

//查找联系人
void SearchContact(Contact* pc);

//修改联系人信息
void ModifyContact(Contact* pc);

//将联系人按年龄排序
void SortContact(Contact* pc);

//销毁通讯录
void DestroyContact(Contact* pc);



