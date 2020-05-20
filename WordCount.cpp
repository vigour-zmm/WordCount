
#include<stdio.h>
#pragma warning(disable:4996);
#define SIZE 10240 //数组空间要足够大，才可以尽可能的装下目标文件

int main(int argc, char* argv[])
{
	int ch,n=0,i=0,len=0,word_val=0;
	FILE* fp;
	char str[SIZE];

	//检测命令行参数输入是否完整
	if (argc != 3)
	{
		printf("Sorry,Input error\n");
		return -1;
	}
	//检测将执行的功能是什么
	if (argv[1][0] == '-')
	{
		if (argv[1][1] == 'w')
		{
			//以下为测定单词数代码
			//打开目标文件
			if ((fp = fopen(argv[2], "r")) == NULL)
			{
				printf("File open failed\n");
				return -1;
			}

			//逐字节取出存在str数组中
			while (!feof(fp))
			{
				ch = fgetc(fp);
				if (ch != EOF)
				{
					str[i] = ch;
					i++;
				}
			}
			len = i;
			str[i] = 0;
			fclose(fp);
			//遍历str数组确定单词数
			//通过同wora_val来保证每个单词是完整计算
			for (i = 0; i < len + 1; i++)
			{
				if (str[i] != ' ' && str[i] != ',')
					word_val = 1;
				if (str[i] == ' ' || str[i] == ',')
				{
					n += word_val;
					word_val = 0;
				}
			}
			n += word_val;
			printf("单词个数:%d\n", n);
		}
		else if (argv[1][1] == 'c')
		{
			//以下为测定字符数的代码
			//打开目标文件
			if ((fp = fopen(argv[2], "r")) == NULL)
			{
				printf("File open failed\n");
				return -1;
			}
			//逐字节取出存在str数组中
			while (!feof(fp))
			{
				ch = fgetc(fp);
				if (ch != EOF)
				{
					str[i] = ch;
					i++;
				}
			}
			fclose(fp);
			len = i;

			printf("字符个数%d\n", len);

		}
		else
		{
			//不能识别具体功能的，将拒绝执行
			printf("暂不支持的此功能\n");
			return -1;
		}
	}

	return 0;
}