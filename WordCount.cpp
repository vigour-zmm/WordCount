
#include<stdio.h>
int main(int argc, char* argv[])
{
	int ch;
	FILE* fp;
	if (argc != 3)
	{
		printf("Sorry,Input error\n");
		return -1;
	}

	printf("3\n");

	//if ((fp = fopen(argv[2], "r")) == NULL)
	//{
	//	printf("File open failed\n");
	//	return -1;
	//}

	//printf("File open success\n");

	//ch = fgetc(fp);
	//while (ch != EOF)
	//{
	//	putchar(ch);
	//	ch = fgetc(fp);
	//}
	//fclose(fp);

	printf("%d\n", argc);
	printf("argv[1]= %c\n", argv[1][0]);
	printf("argv[1]= %c\n", argv[1][1]);

	if (argv[1][0] == '-')
	{
		if (argv[1][1] == 'w')
		{
			printf("这是检测单词数");
		}
		else if (argv[1][1] == 'c')
		{
			printf("这是检测字符数");
		}
		else
		{
			printf("暂不支持的此功能");
		}
	}


	return 0;
}