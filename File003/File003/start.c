#include <stdio.h>
#include <stdlib.h>
//2.��дһ���ļ��������򣬸ó���ͨ�������л�ȡԭʼ�ļ����Ϳ����ļ���������ʹ�ñ�׼I/O�Ͷ�����ģʽ

//#define max 10000
//int main(int argc, char* argv[])
//{
//	FILE* pa;
//	FILE* pb;
//	if (argc != 3)
//	{
//		printf("Can not open %s filename well\n", argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	if ((pa = fopen(argv[1], "rb")) == NULL)
//	{
//		printf("Can not open the %s filename\n", argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	char data[max];
//	//fread(data, sizeof(char), max, pa);
//	size_t bytes;
//	
//	if ((pb = fopen(argv[2], "wb")) == NULL)
//	{
//		printf("Can not open the %s filename\n", argv[2]);
//		exit(EXIT_FAILURE);
//	}
//	while((bytes = fread(data, sizeof(char), max, pa)) > 0)
//	{
//		fwrite(data, sizeof(char), bytes/*max*/, pb);
//	}
//	fclose(pa);
//	fclose(pb);
//	return 0;
//}

#include <ctype.h>
//3.��дһ���ļ�����������ʾ�û������ı��ļ��������Ը��ļ�����Ϊԭʼ�ļ���������ļ������ó���Ҫʹ��ctype.h�е�
//toupper������������д�뵽����ļ�ʱ�������ı�ת���ɴ�д��ʹ�ñ�׼I/O���ı�ģʽ
//int main()
//{
//	char name[10];
//	char data[10];
//	char ch;
//	FILE* pa;
//	printf("��������Ҫ�������ı��ļ�����");
//	scanf("%s", name);
//	if ((pa = fopen(name, "r+")) == NULL)
//	{
//		printf("Can not open %s filename well\n", name);
//		exit(EXIT_FAILURE);
//	}
//	while ((ch = getc(pa)) != EOF)//�õ�����
//	{
//		fseek(pa, -sizeof(char), SEEK_CUR);//�Ƶ�ԭ��λ��
//		putc(toupper(ch), pa);
//    //getc() putc() ���ַ���ȡ/���� ���ƶ�����һ��λ��
//	}
//	fclose(pa);
//	return 0;
//
//
//}



//4.��дһ�����򣬰�˳������Ļ����ʾ���������г��������ļ���ʹ��argc����ѭ��


//int main(int argc, char* argv[])
//{
//	FILE* pa;
//	char ch;
//	if (argc < 1)
//	{
//		printf("Not enough %s\n", argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	for (int i = 1;i < argc;i++)
//	{
//		if ((pa = fopen(argv[i], "r")) != NULL)
//		{
//			printf("Now print file %s:\n", argv[i]);
//			while ((ch = getc(pa)) != EOF)
//			{
//				putchar(ch);
//			}
//			printf("\n");
//			fclose(pa);
//		}
//		else
//		{
//			printf("Can not open %s\n", argv[i]);
//			exit(EXIT_FAILURE);
//		}
//	}
//	printf("%d files printed\n", argc - 1);
//	return 0;
//}

//��һϵ���ļ�������Ŀ���ļ�ĩβ
//#include <string.h>
//#define bufsize 4096
//#define slen 81
//void append(FILE* source, FILE* dest);
//int main(int argc, char* argv[])
//{
//
//	FILE* pa, * pb;
//	int files = 1;//���ӵ��ļ�����
//	if ((pa = fopen(argv[1], "a+")) == NULL)
//	{
//		fprintf(stderr, "Can not open %s\n", argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	if (setvbuf(pa, NULL, _IOFBF, bufsize) != 0)
//	{
//		fputs("Can not create output buffer\n", stderr);
//		exit(EXIT_FAILURE);
//	}
//	while (files < argc - 1)
//	{
//		if (strcmp(argv[1], argv[files + 1]) == 0)
//			fputs("Can not append file to itself\n", stderr);
//		else if ((pb = fopen(argv[files + 1], "r")) == NULL)
//			fprintf(stderr, "Can not open %s\n", argv[files + 1]);
//		else
//		{
//			if(setvbuf(pb,NULL,_IOFBF,bufsize)!=0)
//			{
//				fputs("Can not create input buffer\n", stderr);
//				files++;
//				continue;
//			} 
//		}
//		append(pb, pa);
//		if (ferror(pb) != 0)
//		{
//			fprintf(stderr, "Error in reading file %s\n", argv[files+1]);
//		}
//		if (ferror(pa) != 0)
//		{
//			fprintf(stderr, "Error in writing file %s\n", argv[1]);
//		}
//		fclose(pb);
//		files++;
//		printf("Files %s appended\n", argv[files]);
//		printf("Next file is\n");
//	}
//	printf("����׷��.%d���ļ�׷����ȥ��\n", files-1);
//	rewind(pa);
//	printf("%s contents\n", argv[1]);
//	int ch;
//	while ((ch = getc(pa)) != EOF)
//		putchar(ch);
//	puts("��������\n");
//	fclose(pa);
//	return 0;
//}
//void append(FILE* source, FILE* dest)
//{
//	size_t bytes;
//	static char temp[bufsize];
//	while ((bytes = fread(temp, sizeof(char), bufsize, source)) > 0)
//		fwrite(temp, sizeof(char), bytes, dest);
//}
//


//6.ʹ�������в����ĳ����������û����ڴ������ȷ��ʹ�����ǡ�


//#define len 40
//
//int main()
//{
//	FILE* in, * out;
//	int ch;
//	char name[len];//�洢����ļ���
//	int count = 0;
//	char name1[len];
//	printf("������һ��in�ļ���:");
//	scanf("%s", name1);
//	if ((in = fopen(name1, "r")) == NULL)
//	{
//		fprintf(stderr,"Can not open the file %s\n",name1);
//		exit(EXIT_FAILURE);
//	}
//	strncpy(name, name1, len - 5);
//	name[len - 5] = '\0';
//	strcat(name, ".red");
//	if ((out = fopen(name, "w")) == NULL)
//	{
//		fprintf(stderr, "Can not create output file\n");
//		exit(3);
//	}
//	while ((ch = getc(in)) != EOF)
//	{
//		if (count++ % 3 == 0)
//			putc(ch, out);
//	}
//	if (fclose(in) != 0 || fclose(out) != 0)
//		fprintf(stderr, "Error in closing files\n");
//	return 0;
//}


//7.��дһ������������ļ�������ʹ�������в���

//a.�ó�����������˳���ӡ����ӡ��һ�ļ��ĵ�һ�У��ڶ����ļ��ĵ�һ�У���һ���ļ��ĵڶ��У��ڶ����ļ��ĵڶ���
//�Դ����ƣ������������϶��ļ������һ��
//b.�޸ĸĳ��򣬰��к���ͬ�õ��д��һ��

                                               
//#define linesize 256
//int main(int  argc, char* argv[])
//{
//    char* lineone = (char*)malloc(linesize * sizeof(char));
//    char* linetwo = (char*)malloc(linesize * sizeof(char));
//    //Ԥ�������������еĻ�����
//    int firstend = 1;
//    if(argc!=3)
//    {
//        fprintf(stderr, "Usage %s filename", argv[0]);
//        exit(EXIT_FAILURE);
//    }
//
//    FILE* fp1, *fp2;
//    if ((fp1 = fopen(argv[1], "r")) == NULL)
//    {
//        fprintf(stderr, "Can not open %s\n", argv[1]);
//        exit(EXIT_FAILURE);
//    }
//    if ((fp2 = fopen(argv[1], "r")) == NULL)
//    {
//        fprintf(stderr, "Can not open %s\n", argv[2]);
//        exit(EXIT_FAILURE);
//    }
//    printf("һ��һ�д�ӡ��\n");
//    int i = 1;
//    while (fgets(lineone, linesize, fp1) != NULL)
//    {
//        if (fgets(linetwo, linesize, fp2) != NULL)
//        {
//            printf("File 1 line %d :%s", i, lineone);
//            printf("File 2 line %d :%s", i, linetwo);
//            i++;
//        }
//        else
//        {
//            printf("File 1 line %d :%s", i, lineone);//�ڵ�һ���ļ��ȵڶ��ļ���ʱ��ӡ
//            i++;
//        }
//    }
//    while (fgets(linetwo, linesize, fp2) != NULL)
//    {
//        printf("File 2 line %d :%s", i, linetwo);
//        i++;//�ڶ����ļ��ȵ�һ���ļ���ʱ
//    }
//
//    printf("�����ϲ�һ���ӡΪ��\n");
//    rewind(fp1);
//    rewind(fp2);
//    i = 1;
//    while (fgets(lineone, linesize, fp1) != NULL)
//    {
//        if (fgets(linetwo, linesize, fp2) != NULL)
//        {
//            printf("LINE NO.%d:", i);
//            while (*lineone != '\n')
//                putchar(*lineone++);
//            putchar('+');
//            printf("%s", linetwo);
//            i++;
//        }
//        else
//        {
//            printf("LINE NO.%d��%s", i, lineone);
//            i++;
//        }
//    }
//    while (fgets(linetwo, linesize, fp2) != NULL)
//    {
//        printf("LINE NO.%d��%s", i, linetwo);
//        i++;//�ڶ����ļ��ȵ�һ���ļ���ʱ
//    }
//    fclose(fp1);
//    fclose(fp2);
//    return 0;
//}
//

//8.��дһ��������һ���ַ��������ļ�����Ϊ�����в���������ַ�����û�в������ó����ȡ��׼���룻���򣬳������δ�ÿ���ļ�
//������ÿ���ļ��и��ַ����ֵĴ������ļ������ַ�����ҲҪһͬ���档����Ӧ���������飬��ȷ�����������Ƿ���ȷ���Ƿ��ܴ��ļ�
//����޷����ļ�������Ӧ������һ�����Ȼ������һ���ļ�


int main(int argc, char* argv[])
{
    char ch = argv[1][0];
    int i = 1;
    int num = 0;
    FILE* pa;
    char* arr1 = (char*)malloc(1000 * sizeof(char));
    for (i = 2;i < argc;i++)
    {
        char name[10] = argv[i];
        if (ferror(argv[i]) != 0)
            printf("��������:\n");
        if ((pa = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr,"Can not open %s\n",argv[i]);
            exit(EXIT_FAILURE);
        }

        while (fgets(arr1, 100, pa) != NULL)
        {
            for (i = 0;i < 10;i++)
                if (name[i] == ch)
                    num++;
            while (*arr1 != '\n')
                if (*arr1++ == ch)
                    num++;
        }
      /*  char ar;
        while ((ar = getc(pa)) != EOF)
        {
            if (ar == argv[1][0])
                num++;
        }*/
        printf("File %s has %d �� %c\n", argv[i], num, ch);
        fclose(pa);
    }
    return 0;
}
