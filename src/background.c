#include "head.h"

int lcd_fd; // lcd的文件描述符
int *lcd_map; // 内存映射的起始地址

// 打开lcd，并作内存映射
int lcd_open(void)
{
	// 1.打开lcd驱动
	lcd_fd = open("/dev/fb0", O_RDWR);
	if(lcd_fd == -1)
	{
		perror("open lcd error\n");
		return -1;
	}
	// 2.进行内存映射
	lcd_map = mmap(NULL, // 映射内存的起始地址
						800*480*4, // 映射内存的大小
						PROT_READ|PROT_WRITE, // 映射内存的权限
						MAP_SHARED, // 数据共享
						lcd_fd, // 映射内存的对象
						0);// 偏移量
	if(lcd_map == MAP_FAILED)
	{
		perror("mmap error\n");
		return -1;
	}
}


// 图片显示封装
int show_bmp(char *pathname, int x0, int y0)
{
	// 1.打开图片
	int bmp_fd = open(pathname, O_RDWR);
	if(bmp_fd == -1)
	{
		perror("open bmp error\n");
		return -1;
	}
	// 读取图片的头信息（宽+高）
	char head[54] = {0};
	read(bmp_fd, head, 54);
	// 获取图片的宽和高
	int w = *((int *)&head[18]);
	int h = *((int *)&head[22]);
	// printf("w=%d, h=%d\n", w, h);

	// 计算出windows会补多少垃圾值
	int n_add; // 需要补的字节数
	int add_a; // 补齐之后的字节数

	n_add =(4-w*3%4)%4;
	add_a = n_add + w*3; // 一行的字节长度
	// 定义一个大一点的数组，存储包含了垃圾值的图片信息
	char bmp_add[add_a*h];
	// 读取图片数据
	read(bmp_fd, bmp_add, sizeof(bmp_add));
	// 处理垃圾值，利用memcpy，一行一行的拷贝实际的像素数据
	char bmp_buf[w*h*3]; // 存储不包含垃圾值的像素
	for(int i=0; i<h; i++)
	{
		memcpy(&bmp_buf[w*3*i], &bmp_add[add_a*i], w*3);
	}

	// 3.1给每一个图片的像素补一个透明度
	int buf_32[w*h];
	for(int i=0; i<w*h; i++)
	{   
		// 像素			b				g            r					a
		buf_32[i] = bmp_buf[0+3*i]<<0 | bmp_buf[1+3*i]<<8 | bmp_buf[2+3*i]<<16 | 0x00<<24;
	}
	// 3.2将图片翻转，并把像素写入内存映射空间
	for(int y=0; y<h; y++)
	{
		for(int x=0; x<w; x++)
		{
			lcd_map[800*(y+y0)+x+x0] = buf_32[w*(h-1-y)+x]; // 定位到每一个像素
		}
	}
	// 5.关闭lcd和图片
	close(bmp_fd);
}


//主界面背景
void Main_Interface()
{
    //显示图片
    show_bmp("/Even/project/picture/Main_Interface.bmp", 0, 0);
}

//选择角色界面
void role()
{
	//显示图片
	show_bmp("/Even/project/picture/role.bmp",0,0);
	show_bmp("/Even/project/picture/own_air11.bmp",0,80);
	show_bmp("/Even/project/picture/own_air12.bmp",0,240);
	show_bmp("/Even/project/picture/own_air13.bmp",0,400);
}


//游戏界面背景(用小图片循环打印铺满屏幕)
void Interface()
{
    //显示图片
    for(int y=0;y<480;y=y+80)
    {
        for(int x=0;x<800;x=x+80)
        {
			//显示图片
			show_bmp("/Even/project/picture/black.bmp",x,y);
        }
    }
}

//排行榜界面和返回按钮
void leaderboard()
{
    //显示排行榜图片
    show_bmp("/Even/project/picture/leaderboard.bmp", 0, 0);
	//显示返回按钮
    return_button();
}


//结束界面
void gameover()
{
    //显示图片
    show_bmp("/Even/project/picture/gameover.bmp", 0, 0);
	//显示返回按钮
    return_button();
}

//返回上一步按钮
void return_button()
{
    //显示图片
    show_bmp("/Even/project/picture/return_button.bmp", 719, 0);
}

//加载退出按钮
void leave_button()
{
    //显示图片
    show_bmp("/Even/project/picture/leave.bmp", 659, 0);
}