#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME 20
#define MAX_SET 10
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_SZ 3 //Ĭ���ܴ�ŵĿռ�Ϊ3
#define INC_SZ 2  //ÿ������2

#define MAX 100

//���͵Ķ���
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char set[MAX_SET];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


//ͨѶ¼
typedef struct Contact
{
	PeoInfo* deta;//ָ��̬����Ŀռ䣬�����ϵ����Ϣ
	int sz;//��¼��ǰͨѶ¼����Ч��Ϣ�ĸ���
	int max_capacity;//��¼��ǰͨѶ¼���������
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//��ӡ��ϵ����Ϣ
void PrintContact(const Contact* pc); //ֻ�Ǵ�ӡ��Ϣ����ı�ԭ����Ϣ ��const����

//ɾ����ϵ��
void DelContact(Contact* pc);

//������ϵ��
void SearchContact(Contact* pc);

//�޸���ϵ����Ϣ
void ModifyContact(Contact* pc);

//����ϵ�˰���������
void SortContact(Contact* pc);

//����ͨѶ¼
void DestroyContact(Contact* pc);



