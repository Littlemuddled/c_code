#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//int main()
//{
//	printf("Practice makes perfect!");
//	return 0;
//}

//���뻺����������
//int main()
//{
//	char password[20] = { 0 };
//	printf("���������룺\n");
//	scanf("%s", password);
//	printf("��ȷ�ϣ���Y/N��\n");
//	getchar();//���������� \n
//	char ch = getchar();
//	if (ch == 'Y')
//		printf("ȷ�ϳɹ�\n");
//	else
//		printf("ȷ��ʧ��\n");
//	return 0;
//}

//int get_max(int x, int y)
//{
//	int z = 0;
//	if (x > y)
//		z = x;
//	else
//		z = y;
//	return z;//���غ���������ֵ
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//�����ĵ���
//	int max = get_max(a, b);
//	printf("%d\n", max);
//	return 0;
//}


//void Swap1(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
//
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//дһ�����������������ͱ�����ֵ
//	printf("����ǰ��a=%d b=%d\n",a, b);
//	Swap1(a, b);
//	printf("������a=%d b=%d\n", a, b);
//	return 0;
//}
//
//void Swap2(int* pa, int* pb)
//{
//	int z = 0;
//	z = *pa;
//	*pa = *pb;
//	*pb = z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//дһ�����������������ͱ�����ֵ
//	printf("����ǰ��a=%d b=%d\n", a, b);
//	Swap2(&a, &b);
//	printf("������a=%d b=%d\n", a, b);
//	return 0;
//}



//��װһ��������100-200֮�������
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j < n; j++)
//	{
//		if (n%j == 0)
//			return 0;
//	}
//	return 1;
//}
//
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (1 == is_prime(i))
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount = %d\n",count);
//	return 0;
//}
//

//����ʵ�ֶ��ֲ��ҷ�
//int binary_search(int a[], int k, int s)
//{
//	int left = 0;
//	int right = s - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (a[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (a[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
//	int key = 7;//Ҫ���ҵ�����
//	int se = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr,key,se);
//	if (-1 == ret)
//	{
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
//	}
//	return 0;
//}


//void test2()
//{
//	printf("hehe\n");
//}
//
//int test1()
//{
//	test2();
//	return 0;
//}
//
//int main()
//{
//	test1();
//	return 0;
//}



//int main()
//{
//	int len = strlen("abc");
//	printf("%d\n", len);
//
//	//��ʽ����
//	printf("%d\n",strlen("abc"));
//	return 0;
//}


//int main()
//{
//	printf("%d",printf("%d",printf("%d", 43)));
//	return 0;
//}


//int main()
//{
//	printf("hehe\n");
//	main();
//	return 0;
//}


//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d", n % 10);
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);//123
//	//�ݹ�-�����Լ������Լ�
//	print(num);
//	return 0;
//}


//int count = 0;
//int Fib(int n)
//{
//	//ͳ�Ƶ�����쳲��������ļ�����������
//	if (n == 3)
//		count++;
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	printf("count = %d\n",count);
//	return 0;
//}



int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d\n", ret);
	return 0;
}

