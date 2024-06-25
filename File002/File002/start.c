#include <stdio.h>
#include <stdlib.h>
//编写一个程序，不接受任何命令行参数或接受一个命令行参数。如果有一个参数，将其解释为文件名；如果没有参数
//使用标准输入（stdin）。假设输入完全是浮点数。该程序要计算和报告输入数字的算术平均值

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
//		printf("输入数字系统计算平均值：\n");
//		printf("请输入数字：");
//		for (i = 0;i < 10;i++)
//		{
//			if (scanf("%lf", &num[i]) != 1)
//				break;
//			while (getchar() != '\n')
//				continue;
//			sum += num[i];
//			printf("还要输入吗输入1继续:");
//			scanf("%d", &x);
//			if (x != 1)
//				break;
//			printf("请输入：");
//		}
//		if(i>0)
//		printf("输入的总数和为%.2lf算术平均值为%.2lf\n", sum, sum / (i + 1));
//	}
//	else if (panbie!=1)
//	{
//		printf("Usage %s filename \n", argv[0]);
//		exit(EXIT_FAILURE);
//		while ((fscanf(pa, "%lf", &num[i])) == 1 && !feof(pa))//循环入口条件读取到EOF或者fscanf（）函数无法读取浮点数据
//		{
//			sum += num[i];
//			i++;
//		}		
//		printf("总数%.2lf的平均值为%.2lf\n", sum, sum / i);
//		
//	}
//	if (i <= 0)
//		printf("没有数字\n");
//	return 0;
//}



//编写一个程序，接受两个命令行参数。第一个参数是字符，第二个参数是文件名。要求该程序只打印文件中包含给定字符的那些行

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
//	while (fgets(line, hang, pa) != NULL)//fgets读取到\n 即每次循环读取一行
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
	printf("请输入文件名字：");
	s_gets(name, 10);
	if ((fp = fopen(name, "w")) == NULL)
	{
		printf("Can not poen %s\n", name);
		exit(EXIT_FAILURE);
	}
	printf("请输入存储的信息:(#end)");
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
	printf("文件 %s 有%lu 信息", name, count);
	return 0;
}