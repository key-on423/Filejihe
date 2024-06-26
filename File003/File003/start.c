#include <stdio.h>
#include <stdlib.h>
//2.编写一个文件拷贝程序，该程序通过命令行获取原始文件名和拷贝文件名。尽量使用标准I/O和二进制模式

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
//3.编写一个文件拷贝程序，提示用户输入文本文件名，并以该文件名作为原始文件名和输出文件名。该程序要使用ctype.h中的
//toupper（）函数，在写入到输出文件时把所有文本转换成大写。使用标准I/O和文本模式
//int main()
//{
//	char name[10];
//	char data[10];
//	char ch;
//	FILE* pa;
//	printf("请输入想要创建的文本文件名：");
//	scanf("%s", name);
//	if ((pa = fopen(name, "r+")) == NULL)
//	{
//		printf("Can not open %s filename well\n", name);
//		exit(EXIT_FAILURE);
//	}
//	while ((ch = getc(pa)) != EOF)//得到后移
//	{
//		fseek(pa, -sizeof(char), SEEK_CUR);//移到原来位置
//		putc(toupper(ch), pa);
//    //getc() putc() 逐字符读取/放置 后移动至下一个位置
//	}
//	fclose(pa);
//	return 0;
//
//
//}



//4.编写一个程序，按顺序在屏幕上显示命令行中列出的所有文件。使用argc控制循环


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

//把一系列文件拷贝在目的文件末尾
//#include <string.h>
//#define bufsize 4096
//#define slen 81
//void append(FILE* source, FILE* dest);
//int main(int argc, char* argv[])
//{
//
//	FILE* pa, * pb;
//	int files = 1;//附加的文件数量
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
//	printf("结束追加.%d个文件追加上去了\n", files-1);
//	rewind(pa);
//	printf("%s contents\n", argv[1]);
//	int ch;
//	while ((ch = getc(pa)) != EOF)
//		putchar(ch);
//	puts("结束程序\n");
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


//6.使用命令行参数的程序依赖与用户的内存如何正确地使用它们。


//#define len 40
//
//int main()
//{
//	FILE* in, * out;
//	int ch;
//	char name[len];//存储输出文件名
//	int count = 0;
//	char name1[len];
//	printf("请输入一个in文件名:");
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


//7.编写一个程序打开两个文件。可以使用命令行参数

//a.该程序以这样的顺序打印：打印第一文件的第一行，第二个文件的第一行，第一个文件的第二行，第二个文件的第二行
//以此类推，大隐刀行数较多文件的最后一行
//b.修改改程序，把行号相同得到行打成一行

                                               
//#define linesize 256
//int main(int  argc, char* argv[])
//{
//    char* lineone = (char*)malloc(linesize * sizeof(char));
//    char* linetwo = (char*)malloc(linesize * sizeof(char));
//    //预分配两个读入行的缓冲区
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
//    printf("一行一行打印：\n");
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
//            printf("File 1 line %d :%s", i, lineone);//在第一个文件比第二文件长时打印
//            i++;
//        }
//    }
//    while (fgets(linetwo, linesize, fp2) != NULL)
//    {
//        printf("File 2 line %d :%s", i, linetwo);
//        i++;//第二个文件比第一个文件长时
//    }
//
//    printf("两个合并一起打印为：\n");
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
//            printf("LINE NO.%d：%s", i, lineone);
//            i++;
//        }
//    }
//    while (fgets(linetwo, linesize, fp2) != NULL)
//    {
//        printf("LINE NO.%d：%s", i, linetwo);
//        i++;//第二个文件比第一个文件长时
//    }
//    fclose(fp1);
//    fclose(fp2);
//    return 0;
//}
//

//8.编写一个程序以一个字符和任意文件名作为命令行参数，如果字符后面没有参数，该程序读取标准输入；否则，程序依次打开每个文件
//并报告每个文件中该字符出现的次数。文件名和字符本身也要一同报告。程序应包含错误检查，以确定参数数量是否正确和是否能打开文件
//如果无法打开文件，程序应报告这一情况，然后处理下一个文件


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
            printf("参数错误:\n");
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
        printf("File %s has %d 个 %c\n", argv[i], num, ch);
        fclose(pa);
    }
    return 0;
}
