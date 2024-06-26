

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//9.编写程序，从1开始，根据假如列表的顺序为每个单词编号。当程序下次运行时，确保新的单词编号接着上次的编号开始

//#define max 41
//int main()
//{
//	FILE* pa;
//	char words[max];
//	if ((pa = fopen("wordy", "a+")) == NULL)
//	{
//		fprintf(stderr, "Can not open the file wordy\n");
//		exit(EXIT_FAILURE);
//	}
//	puts("输入单词来加到文件上；输入#来结束");
//	while ((fscanf(stdin, "%40s", words)) == 1 && words[0] != '#')
//		fprintf(pa, "%s\n", words);
//	puts("文件信息:\n");
//	rewind(pa);
//	while (fscanf(pa, "%s", words) == 1)
//		puts(words);
//	puts("结束。\n");
//	if (fclose(pa) != 0)
//	{
//		fprintf(stderr, "关闭文件失败\n");
//	}
//	return 0;
//}


//10.编写一个程序打开一个文本文件，通过交互方式获得文件名。通过一个循环，提示用户输入一个文件位置。然后该程序打印从该位置开始到
//下一个换行符之前的内容。用户输入负数或非数值字符可以结束循环
//#include <ctype.h>
//int main()
//{
//	FILE* pa;
//	printf("请输入要打印的文件名：");
//	char name[20];
//	char ch;
//	int i = 1;
//	int position;
//	while (scanf("%s", name) == 1)
//	{
//		if ((pa = fopen(name, "r")) == NULL)
//		{
//			fprintf(stderr, "Can open the %s file\n", name);
//			exit(EXIT_FAILURE);
//		}
//		printf("输入文件起始位置：(0为起始)");
//		scanf("%d", &position);
//		fseek(pa, position, SEEK_SET);
//		while ((ch = getc(pa)) != EOF&&ch!='\n')
//		{
//			putchar(ch);
//		}
//		printf("是否输入下一个文件，输入负数终止循环，输入正数继续运行\n");
//		scanf("%d", &i);
//		while (getchar() != '\n')
//			continue;
//		if (i < 0)
//			break;
//		else
//			printf("请输入文件名：");
//
//	}
//}

//11.编写一个程序，接受链各个命令行参数。第1个参数是一个字符串，第二个参数是一个文件名。然后该程序查找该文件，打印文件中包含该字符串的所有
//行。因为该任务是面向行而不是面向字符的，所以要使用fgets（）而不是getc（）。使用C库函数strstr（）在每一行查找指定字符串。
//假设文件中所有行都不超过255个字符

//#define max 255
//int main(int argc, char* argv[])
//
//{
//	FILE* pa;
//	char arr1[max] = argv[1];
//	char buf[max];
//	if (argc != 3)
//	{
//		fprintf(stderr, "Can not open the %s file\n", argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	if ((pa = fopen(argv[2], "r")) == NULL)
//	{
//		fprintf(stderr, "Can open the %s file\n", argv[2]);
//		exit(EXIT_FAILURE);
//	}
//	while (fgets(buf, max, pa) != NULL)
//	{
//		if (strstr(buf, arr1) != NULL)
//			puts(buf);
//	}
//	fclose(pa);
//	return 0;
//}

//12.创建一个文本文件，内含20行，每行30个整数。这些整数都在0到9之间，使用空格分开。该文件是用数字表示一张图片，0到9
//表示逐渐增加的灰度。编写一个程序，把文件中的内容读入一个20x30的int数组中。一种把这些数字转换为图片的粗略方法是：
//该程序使用数组中的值初始化一个20x31的字符数组，用值0对应空格字符，1对应点字符，以此类推。数字越大表示字符所占的空间
//越大。例如，用#表示9.每行最后一个字符（第31个）是空字符，这样该数组包含了20个字符串。最后，程序显示最终的图片（即，打印所有的字符串）
//并将结果存储在文本文件中。

//#include <string.h>
//int main()
//{
//	FILE* pa, * pb;
//	int arr1[20][30];
//	char convert[] = { ' ','.','\'','\"','^','*','%','$','@','#' };
//	if ((pa = fopen("wenjian", "r")) == NULL)
//	{
//		fprintf(stderr, "Can not open the wenjian file\n");
//		exit(EXIT_FAILURE);
//	}
//	if ((pb = fopen("wenjiancunru", "w")) == NULL)
//	{
//		fprintf(stderr, "Can not open the wenjian file\n");
//		exit(EXIT_FAILURE);
//	}
//	for (int i = 0;i < 20;i++)
//	{
//
//		for (int w = 0;w < 30;w++)
//			fscanf(pa, "%d", &arr1[i][w]);
//	}
//	for (int i = 0;i < 20;i++)
//	{
//
//		for (int w = 0;w < 30;w++)
//		{
//			printf("%c", convert[arr1[i][w]]);
//			fprintf(pb, "%c", convert[arr1[i][w]]);
//		}
//		printf("\n");
//		fprintf(pb, "\n");
//	}
//	fclose(pa);
//	return 0;
//}


//13.使用变长数组（VLA)代替标准数组，完成编程12

//char convert[] = { ' ','.','\'','\"','^','*','%','$','@','#' };
//#include <string.h>
//int main()
//{
//
//
//	printf("请输入读取的行列：");
//	int x, y;
//	scanf("%d %d", &x, &y);
//	FILE* pa, * pb;
//	int arr1[x][y];
//	/*char convert[] = { ' ','.','\'','\"','^','*','%','$','@','#' };*/
//	if ((pa = fopen("wenjian", "r")) == NULL)
//	{
//		fprintf(stderr, "Can not open the wenjian file\n");
//		exit(EXIT_FAILURE);
//	}
//	if ((pb = fopen("wenjiancunru", "w")) == NULL)
//	{
//		fprintf(stderr, "Can not open the wenjian file\n");
//		exit(EXIT_FAILURE);
//	}
//	for (int i = 0;i < x;i++)
//	{
//
//		for (int w = 0;w < y;w++)
//			fscanf(pa, "%d", &arr1[i][w]);
//	}
//	for (int i = 0;i < x;i++)
//	{
//
//		for (int w = 0;w <y;w++)
//		{
//			printf("%c", convert[arr1[i][w]]);
//			fprintf(pb, "%c", convert[arr1[i][w]]);
//		}
//		printf("\n");
//		fprintf(pb, "\n");
//	}
//	fclose(pa);
//	return 0;
//}
//
//
//void readdata(int x, int y, int arr1[x][y], FILE* aa)
//{
//	for (int w = 0;w < x;w++)
//	{
//		for (int j = 0;j < y;j++)
//		{
//			fscanf(aa, "%d", &arr1[w][j]);
//		}
//	}
//}
//void wirtedata(int x, int y, int arr1[x][y], FILE* aa)
//{
//	for (int w = 0;w < x;w++)
//	{
//		for (int j = 0;j < y;j++)
//		{
//			printf("%c", convert[arr1[w][j]]);
//			fprintf(aa, "%c", convert[arr1[w][j]]);
//		}
//		printf("\n");
//		fprintf(aa, "\n");
//	}
//}



//14.数字图像，尤其是从宇宙飞船发回的数字图像，可能会包含一些失真。为编程练习12添加消除失真的函数。该函数把每个值与他上下左右相邻
//的值作比较，如果该值与其周围相邻值的差都大于1，则用所有相邻值的平均值（四舍五入为整数）代替该值。注意，与边界上的点相邻的点少于4个
//所以做特殊处理

void panbie(int arr1[20][30])
{
	for (int i = 0;i < 20;i++)
	{
		for (int j = 0;j < 30;j++)
		{
			if (i == 0&& j == 0)
			{
				int x = arr1[i][j];
				if (arr1[i][j] - arr1[i + 1][j] > 1 && arr1[i][j] - arr1[i][j + 1] > 1)
					arr1[i][j] = (arr1[i + 1][j] + arr1[i][j + 1]) / 2;
			}
			if (i == 0 && j == 29)
			{
				int x = arr1[i][j];
				if (arr1[i][j] - arr1[i + 1][j] > 1 && arr1[i][j] - arr1[i][j -1] > 1)
					arr1[i][j] = (arr1[i + 1][j] + arr1[i][j-1]) / 2;
			}
			if (i == 19 && j == 0)
			{
				int x = arr1[i][j];
				if (arr1[i][j] - arr1[i-1][j] > 1 && arr1[i][j] - arr1[i][j +1] > 1)
					arr1[i][j] = (arr1[i-1][j] + arr1[i][j +1]) / 2;
			}
			if (i == 19 && j == 29)
			{
				int x = arr1[i][j];
				if (arr1[i][j] - arr1[i - 1][j] > 1 && arr1[i][j] - arr1[i][j -1] > 1)
					arr1[i][j] = (arr1[i - 1][j] + arr1[i][j - 1]) / 2;
			}
			if (i == 0 && j > 0 && j < 29)
			{
				if (arr1[i][j] - arr1[i + 1][j] > 1 && arr1[i][j] - arr1[i][j + 1] > 1&&arr1[i][j] - arr1[i][j-1] > 1 )
					arr1[i][j] = (arr1[i +1][j] + arr1[i][j - 1]+arr1[i][j + 1]) / 3;
			}
			if (i == 19 && j > 0 && j < 29)
			{
				if (arr1[i][j] - arr1[i - 1][j] > 1 && arr1[i][j] - arr1[i][j + 1] > 1 && arr1[i][j] - arr1[i][j - 1] > 1)
					arr1[i][j] = (arr1[i - 1][j] + arr1[i][j - 1] + arr1[i][j + 1]) / 3;
			}
			if (arr1[i][j] - arr1[i - 1][j] > 1 && arr1[i][j] - arr1[i][j + 1] > 1 && arr1[i][j] - arr1[i][j - 1] > 1&& arr1[i][j] - arr1[i+1][j])
				arr1[i][j] = (arr1[i - 1][j] + arr1[i][j - 1] + arr1[i][j + 1]+ arr1[i + 1][j]) / 4;
		}
	}
}
#include <string.h>
int main()
{
	FILE* pa, * pb;
	int arr1[20][30];
	char convert[] = { ' ','.','\'','\"','^','*','%','$','@','#' };
	if ((pa = fopen("wenjian", "r")) == NULL)
	{
		fprintf(stderr, "Can not open the wenjian file\n");
		exit(EXIT_FAILURE);
	}
	if ((pb = fopen("wenjiancunru", "w")) == NULL)
	{
		fprintf(stderr, "Can not open the wenjian file\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0;i < 20;i++)
	{
		panbie(arr1[20][30]);
		for (int w = 0;w < 30;w++)
			fscanf(pa, "%d", &arr1[i][w]);
	}
	for (int i = 0;i < 20;i++)
	{

		for (int w = 0;w < 30;w++)
		{
			printf("%c", convert[arr1[i][w]]);
			fprintf(pb, "%c", convert[arr1[i][w]]);
		}
		printf("\n");
		fprintf(pb, "\n");
	}
	fclose(pa);
	return 0;
}
