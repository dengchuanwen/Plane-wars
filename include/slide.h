#ifndef __SLIDE_H__
#define __SLIDE_H__

int ts_fd; // 触摸设备的文件描述符

// 打开触摸驱动
int ts_open();

//计算点击位置
int get_xy(int *, int *);

//关闭触摸屏文件
void close_file();


#endif