#include <stdio.h>
#include <stdlib.h>
int main()
{
	struct S { int n };
	struct S s = { 0 };
	FILE* fp= fopen("text.txt", "w");
	if (fp == NULL)
	{
		printf("Failed to open file. Bye\n");
		exit(1);
	}
	fscanf(fp, "%d", &(s.n));
	fprintf(fp, "%d", s.n);
	fclose(fp);
	
	fp = NULL;
	return 0;
}