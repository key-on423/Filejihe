#include <stdio.h>
#include <stdlib.h>
//��дһ�����򣬲������κ������в��������һ�������в����������һ���������������Ϊ�ļ��������û�в���
//ʹ�ñ�׼���루stdin��������������ȫ�Ǹ��������ó���Ҫ����ͱ����������ֵ�����ƽ��ֵ

//int main(int argc, char* argv[])
//{
//	FILE* pa;
//	int panbie = 0;
//	int x;
//	if (argc == 2)
//	{
//		if ((pa = fopen(argv[1], "r")) == NULL)
//		{
//			printf("can not open %s\n", argv[1]);
//			exit(EXIT_FAILURE);
//		}
//		panbie = 1;
//	}
//	double num[10];
//	char name[10];
//	int i = 0;
//	double sum = 0;
//	if (panbie == 0&&argc==1)
//	{
//		printf("��������ϵͳ����ƽ��ֵ��\n");
//		printf("���������֣�");
//		for (i = 0;i < 10;i++)
//		{
//			if (scanf("%lf", &num[i]) != 1)
//				break;
//			while (getchar() != '\n')
//				continue;
//			sum += num[i];
//			printf("��Ҫ����������1����:");
//			scanf("%d", &x);
//			if (x != 1)
//				break;
//			printf("�����룺");
//		}
//		if(i>0)
//		printf("�����������Ϊ%.2lf����ƽ��ֵΪ%.2lf\n", sum, sum / (i + 1));
//	}
//	else if (panbie!=1)
//	{
//		printf("Usage %s filename \n", argv[0]);
//		exit(EXIT_FAILURE);
//		while ((fscanf(pa, "%lf", &num[i])) == 1 && !feof(pa))//ѭ�����������ȡ��EOF����fscanf���������޷���ȡ��������
//		{
//			sum += num[i];
//			i++;
//		}		
//		printf("����%.2lf��ƽ��ֵΪ%.2lf\n", sum, sum / i);
//		
//	}
//	if (i <= 0)
//		printf("û������\n");
//	return 0;
//}



//��дһ�����򣬽������������в�������һ���������ַ����ڶ����������ļ�����Ҫ��ó���ֻ��ӡ�ļ��а��������ַ�����Щ��

//#define hang 256
//int has_ch(char ch, const char* line);
//int main(int argc, char* argv[])
//{
//	FILE* pa;
//	char ch;
//	char line[hang];
//	if (argc != 3)
//	{
//		printf("Usage %s character filename\n", argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	ch = argv[1][0];
//	if ((pa = fopen(argv[2], "r")) == NULL)
//	{
//		printf("Can not open %s\n", argv[2]);
//		exit(EXIT_FAILURE);
//	}
//	while (fgets(line, hang, pa) != NULL)//fgets��ȡ��\n ��ÿ��ѭ����ȡһ��
//	{
//		if (has_ch(ch, line))
//			fputs(line, stdout);
//	}
//	fclose(pa);
//	return 0;
//}
//int has_ch(char ch, const char* line)
//{
//	while (*line)
//		if (ch == *line++)
//			return 1;
//	return 0;
//}

char* s_gets(char* st, int n)
{
	char* ret_val;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (*st != '\n' && *st != '\0')
			st++;
		if (*st == '\n')
			*st = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
int main()
{
	int get;
	int ch;
	FILE* fp;
	FILE* fb;
	unsigned long count = 0;
	char name[10];
	printf("�������ļ����֣�");
	s_gets(name, 10);
	if ((fp = fopen(name, "w")) == NULL)
	{
		printf("Can not poen %s\n", name);
		exit(EXIT_FAILURE);
	}
	printf("������洢����Ϣ:(#end)");
	while ((ch = getchar()) != '#')
	{
		putc(ch, fp);
		count++;
	}
	fclose(fp);
	if ((fb = fopen(name, "r")) == NULL)
	{
		printf("Can not poen %s\n", name);
		exit(EXIT_FAILURE);
	}
	while ((get = getc(fb)) != EOF)
	{
		putc(get, stdout);
	}
	printf("\n");
	fclose(fb);
	printf("�ļ� %s ��%lu ��Ϣ", name, count);
	return 0;
}