#define  _CRT_SECURE_NO_WARNINGS 1

//ÿ���˵���Ϣ��
//����+����+�Ա�+�绰+��ַ
//1.������Ϣ
//2.ɾ��ָ���˵���Ϣ
//3.�޸�ָ���˵���Ϣ
//4.����ָ���˵���Ϣ
//5.ͨ��¼��Ϣ����
//�ڴ涯̬�����İ汾
//ͨѶ¼��ʼ�����3������Ϣ������ʼ���ռ����ʱ������2���˵���Ϣ



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
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch(input)
		{
		case ADD://�����˵���Ϣ
			AddContact(&con);
			break;
		case DEL://ɾ��
			DelContact(&con);
			break;
		case SEARCH://����
			SearchContact(&con);
			break;
		case MODIFY://�޸�
			ModifyContact(&con);
			break;
		case SORT://����
			SortContact(&con);
			break;
		case PRINT://��ӡ
			PrintContact(&con);
			break;
		case EXIT://�˳�
			//����ͨѶ¼
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}