

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//9.��д���򣬴�1��ʼ�����ݼ����б��˳��Ϊÿ�����ʱ�š��������´�����ʱ��ȷ���µĵ��ʱ�Ž����ϴεı�ſ�ʼ

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
//	puts("���뵥�����ӵ��ļ��ϣ�����#������");
//	while ((fscanf(stdin, "%40s", words)) == 1 && words[0] != '#')
//		fprintf(pa, "%s\n", words);
//	puts("�ļ���Ϣ:\n");
//	rewind(pa);
//	while (fscanf(pa, "%s", words) == 1)
//		puts(words);
//	puts("������\n");
//	if (fclose(pa) != 0)
//	{
//		fprintf(stderr, "�ر��ļ�ʧ��\n");
//	}
//	return 0;
//}


//10.��дһ�������һ���ı��ļ���ͨ��������ʽ����ļ�����ͨ��һ��ѭ������ʾ�û�����һ���ļ�λ�á�Ȼ��ó����ӡ�Ӹ�λ�ÿ�ʼ��
//��һ�����з�֮ǰ�����ݡ��û����븺�������ֵ�ַ����Խ���ѭ��
//#include <ctype.h>
//int main()
//{
//	FILE* pa;
//	printf("������Ҫ��ӡ���ļ�����");
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
//		printf("�����ļ���ʼλ�ã�(0Ϊ��ʼ)");
//		scanf("%d", &position);
//		fseek(pa, position, SEEK_SET);
//		while ((ch = getc(pa)) != EOF&&ch!='\n')
//		{
//			putchar(ch);
//		}
//		printf("�Ƿ�������һ���ļ������븺����ֹѭ��������������������\n");
//		scanf("%d", &i);
//		while (getchar() != '\n')
//			continue;
//		if (i < 0)
//			break;
//		else
//			printf("�������ļ�����");
//
//	}
//}

//11.��дһ�����򣬽��������������в�������1��������һ���ַ������ڶ���������һ���ļ�����Ȼ��ó�����Ҹ��ļ�����ӡ�ļ��а������ַ���������
//�С���Ϊ�������������ж����������ַ��ģ�����Ҫʹ��fgets����������getc������ʹ��C�⺯��strstr������ÿһ�в���ָ���ַ�����
//�����ļ��������ж�������255���ַ�

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

//12.����һ���ı��ļ����ں�20�У�ÿ��30����������Щ��������0��9֮�䣬ʹ�ÿո�ֿ������ļ��������ֱ�ʾһ��ͼƬ��0��9
//��ʾ�����ӵĻҶȡ���дһ�����򣬰��ļ��е����ݶ���һ��20x30��int�����С�һ�ְ���Щ����ת��ΪͼƬ�Ĵ��Է����ǣ�
//�ó���ʹ�������е�ֵ��ʼ��һ��20x31���ַ����飬��ֵ0��Ӧ�ո��ַ���1��Ӧ���ַ����Դ����ơ�����Խ���ʾ�ַ���ռ�Ŀռ�
//Խ�����磬��#��ʾ9.ÿ�����һ���ַ�����31�����ǿ��ַ������������������20���ַ�������󣬳�����ʾ���յ�ͼƬ��������ӡ���е��ַ�����
//��������洢���ı��ļ��С�

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


//13.ʹ�ñ䳤���飨VLA)�����׼���飬��ɱ��12

//char convert[] = { ' ','.','\'','\"','^','*','%','$','@','#' };
//#include <string.h>
//int main()
//{
//
//
//	printf("�������ȡ�����У�");
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



//14.����ͼ�������Ǵ�����ɴ����ص�����ͼ�񣬿��ܻ����һЩʧ�档Ϊ�����ϰ12�������ʧ��ĺ������ú�����ÿ��ֵ����������������
//��ֵ���Ƚϣ������ֵ������Χ����ֵ�Ĳ����1��������������ֵ��ƽ��ֵ����������Ϊ�����������ֵ��ע�⣬��߽��ϵĵ����ڵĵ�����4��
//���������⴦��

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
