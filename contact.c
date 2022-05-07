#define  _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//动态初始化通讯录
void InitContact(Contact* pc)
{
	pc->deta = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));//动态开辟空间
	if (pc->deta == NULL)
	{
		perror("InitContact");//如果开辟失败，打印错误原因
		return;
	}
	pc->max_capacity = DEFAULT_SZ;
	pc->sz = 0;
}


//动态增加联系人
void AddContact(Contact* pc)
{
	//考虑增容
	if (pc->sz == pc->max_capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->deta, (pc->max_capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->deta = ptr;//开辟成功
			pc->max_capacity += INC_SZ;
			printf("增容成功\n");
		}
		else
		{
			perror("AddContact");//动态开辟空间失败打印错误原因后返回
			printf("增加联系人失败\n");
			return;
		}
	}
	//增加一个人信息
	printf("请输入名字：");
	scanf("%s", pc->deta[pc->sz].name);
	printf("请输入性别：");
	scanf("%s", pc->deta[pc->sz].set);
	printf("请输入年龄：");
	scanf("%d", &(pc->deta[pc->sz].age));
	printf("请输入电话：");
	scanf("%s", pc->deta[pc->sz].tele);
	printf("请输入地址：");
	scanf("%s", pc->deta[pc->sz].addr);

	pc->sz++;
	printf("添加成功\n");
}

//动态销毁通讯录（回收空间）
void DestroyContact(Contact* pc)
{
	free(pc->deta);
	pc->deta = NULL;
	pc->max_capacity = 0;
	pc->sz = 0;
}

void PrintContact(const Contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		//打印数据
		printf("%-15s\t%-5s\t%-5d\t%-12s\t%-20s\n",
			pc->deta[i].name,
			pc->deta[i].set,
			pc->deta[i].age,
			pc->deta[i].tele,
			pc->deta[i].addr);
	}
}

//static 修饰函数只在此头文件下使用
static int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->deta[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//找不到
}
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	//1.查找要删除的联系人
	printf("请输入要删除人的姓名：");
	scanf("%s", name);
	//如果要删除的联系人存在返回其下标，不存在返回-1
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	//2.删除
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->deta[i] = pc->deta[i + 1];//删除（用后面的覆盖前面的）最后一个不用管
	}
	pc->sz--;
	printf("删除成功\n");
}


void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的姓名：");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	else
	{
		int i = 0;
		//打印标题
		printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
		//打印数据
		printf("%-15s\t%-5s\t%-5d\t%-12s\t%-20s\n",
			pc->deta[pos].name,
			pc->deta[pos].set,
			pc->deta[pos].age,
			pc->deta[pos].tele,
			pc->deta[pos].addr);
	}
}


void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的姓名：");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		//修改一个人的信息
		printf("请输入新的名字：");
		scanf("%s", pc->deta[pos].name);
		printf("请输入新的性别：");
		scanf("%s", pc->deta[pos].set);
		printf("请输入新的年龄：");
		scanf("%d", &(pc->deta[pos].age));
		printf("请输入新的电话：");
		scanf("%s", pc->deta[pos].tele);
		printf("请输入新的地址：");
		scanf("%s", pc->deta[pos].addr);;
		printf("修改成功\n");
	}
}


//冒泡排序法实现年龄的排序
void SortContact(Contact* pc)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pc->sz; i++)//遍历趟数
	{
		for (j = 0; j < pc->sz - 1 - i; j++)//每一趟比较次数
		{
			if (pc->deta[j].age > pc->deta[j + 1].age)
			{
				PeoInfo tmp = pc->deta[j];
				pc->deta[j] = pc->deta[j + 1];
				pc->deta[j + 1] = tmp;
			}
		}
	}
	printf("按年龄排序成功\n");
}

