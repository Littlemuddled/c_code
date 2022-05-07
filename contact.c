#define  _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//��̬��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	pc->deta = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));//��̬���ٿռ�
	if (pc->deta == NULL)
	{
		perror("InitContact");//�������ʧ�ܣ���ӡ����ԭ��
		return;
	}
	pc->max_capacity = DEFAULT_SZ;
	pc->sz = 0;
}


//��̬������ϵ��
void AddContact(Contact* pc)
{
	//��������
	if (pc->sz == pc->max_capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->deta, (pc->max_capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->deta = ptr;//���ٳɹ�
			pc->max_capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("AddContact");//��̬���ٿռ�ʧ�ܴ�ӡ����ԭ��󷵻�
			printf("������ϵ��ʧ��\n");
			return;
		}
	}
	//����һ������Ϣ
	printf("���������֣�");
	scanf("%s", pc->deta[pc->sz].name);
	printf("�������Ա�");
	scanf("%s", pc->deta[pc->sz].set);
	printf("���������䣺");
	scanf("%d", &(pc->deta[pc->sz].age));
	printf("������绰��");
	scanf("%s", pc->deta[pc->sz].tele);
	printf("�������ַ��");
	scanf("%s", pc->deta[pc->sz].addr);

	pc->sz++;
	printf("��ӳɹ�\n");
}

//��̬����ͨѶ¼�����տռ䣩
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
	//��ӡ����
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		//��ӡ����
		printf("%-15s\t%-5s\t%-5d\t%-12s\t%-20s\n",
			pc->deta[i].name,
			pc->deta[i].set,
			pc->deta[i].age,
			pc->deta[i].tele,
			pc->deta[i].addr);
	}
}

//static ���κ���ֻ�ڴ�ͷ�ļ���ʹ��
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
	return -1;//�Ҳ���
}
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	//1.����Ҫɾ������ϵ��
	printf("������Ҫɾ���˵�������");
	scanf("%s", name);
	//���Ҫɾ������ϵ�˴��ڷ������±꣬�����ڷ���-1
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	//2.ɾ��
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->deta[i] = pc->deta[i + 1];//ɾ�����ú���ĸ���ǰ��ģ����һ�����ù�
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}


void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵�������");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	else
	{
		int i = 0;
		//��ӡ����
		printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		//��ӡ����
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
	printf("������Ҫ�޸��˵�������");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		//�޸�һ���˵���Ϣ
		printf("�������µ����֣�");
		scanf("%s", pc->deta[pos].name);
		printf("�������µ��Ա�");
		scanf("%s", pc->deta[pos].set);
		printf("�������µ����䣺");
		scanf("%d", &(pc->deta[pos].age));
		printf("�������µĵ绰��");
		scanf("%s", pc->deta[pos].tele);
		printf("�������µĵ�ַ��");
		scanf("%s", pc->deta[pos].addr);;
		printf("�޸ĳɹ�\n");
	}
}


//ð������ʵ�����������
void SortContact(Contact* pc)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pc->sz; i++)//��������
	{
		for (j = 0; j < pc->sz - 1 - i; j++)//ÿһ�˱Ƚϴ���
		{
			if (pc->deta[j].age > pc->deta[j + 1].age)
			{
				PeoInfo tmp = pc->deta[j];
				pc->deta[j] = pc->deta[j + 1];
				pc->deta[j + 1] = tmp;
			}
		}
	}
	printf("����������ɹ�\n");
}

