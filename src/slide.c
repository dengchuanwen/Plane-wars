#include "head.h"

int ts_fd; // 触摸设备的文件描述符

// 打开触摸驱动
int ts_open(void)
{
	// 1.打开触摸驱动
	ts_fd = open("/dev/input/event0", O_RDWR);
	if(ts_fd == -1)
	{
		perror("open ts error\n");
		return -1;
	}
}

// 获取坐标
int get_xy(int *x, int *y)
{
	// 1.准备一个存储数据的结构体变量
	struct input_event ts_buf;
	memset(&ts_buf, 0, sizeof(ts_buf));
	while(1)
	{
		// read会一直等待触摸屏直到有数据产生
		read(ts_fd, &ts_buf, sizeof(ts_buf));
		// 判断输入设备的类型，事件描述，对应的值
		if(ts_buf.type == EV_ABS && ts_buf.code==ABS_X)
		{
			// 拿到横向坐标x的值
			*x=ts_buf.value*800/1024; // 将触摸点坐标和像素对应
		}
		if(ts_buf.type == EV_ABS && ts_buf.code==ABS_Y)
		{
			// 拿到纵向坐标y的值
			*y=ts_buf.value*480/600; // 只有黑色屏幕需要操作，蓝色屏幕不需要
		}
		if(ts_buf.type == EV_KEY && ts_buf.code==BTN_TOUCH && ts_buf.value==0)
		{
			// 说明手离开了触摸屏，可以退出了
			break;
		}
	}
}

//滑动代码
// // 获取坐标
// int get_xy(int *x, int *y)
// {
// 	// 2.获取坐标
// 	static int flag=0;
// 	while(1)
// 	{
// 		// 清空结构体
// 		memset(&ts_buf, 0, sizeof(ts_buf));
// 		// 读取触摸数据，放到结构体变量中
// 		read(ts_fd, &ts_buf, sizeof(ts_buf));
// 		if(ts_buf.type==EV_ABS && ts_buf.code==ABS_X) // 输入类型为触摸屏，并且具体事件描述为x方向
// 		{
// 			*x=ts_buf.value*800/1024; // 获取x的值，1024
// 			flag++;
// 		}
// 		if(ts_buf.type==EV_ABS && ts_buf.code==ABS_Y) // 输入类型为触摸屏，并且具体事件描述为x方向
// 		{
// 			*y=ts_buf.value*480/600; // 获取y的值，600
// 			flag++;
// 		}
// 		if(ts_buf.type==EV_KEY && ts_buf.code==BTN_TOUCH && ts_buf.value==0)
// 			break; // 松开了触摸屏
// 		if(flag==2)
// 		{
// 			printf("(%d,%d)\n", *x, *y);
// 			flag=0;
// 		    //break;
// 		}
// 	}
// }

