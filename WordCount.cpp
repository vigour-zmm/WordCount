
#include<stdio.h>
#pragma warning(disable:4996);
#define SIZE 10240

#define MAXLINE 100000

int main(int argc, char* argv[])
{
	int ch,n=0,i=0,len=0;
	FILE* fp;
	char str[SIZE];


	if (argc != 3)
	{
		printf("Sorry,Input error\n");
		return -1;
	}

	printf("argc=%d\n", argc);

	if (argv[1][0] == '-')
	{
		if (argv[1][1] == 'w')
		{
			printf("这是检测单词数\n");
		}
		else if (argv[1][1] == 'c')
		{
			printf("这是检测字符数\n");
		}
		else
		{
			printf("暂不支持的此功能\n");
			return -1;
		}
	}

	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		printf("File open failed\n");
		return -1;
	}
	printf("File open success\n");

	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch != EOF)
		{
			str[i] = ch;
			i++;
		}	
	}
	len = i + 1;
	str[i] = 0;
	fclose(fp);

	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ' || ',')
			continue;
		n++;
		while (str[i] != ' ' || ',')
	}

	return 0;
}