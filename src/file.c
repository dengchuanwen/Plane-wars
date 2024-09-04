#include"head.h"


//打开文件
int file_open()
{
    //打开1.txt文本文件
	file = fopen("/Even/project/1.txt", "w+");
	if(file == NULL)
	{
		perror("fopen error\n");
		return -1;
	}
}
