#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

//变量声明
int lcd_fd; // lcd的文件描述符
int *lcd_map; // 内存映射的起始地址

// 打开lcd，并作内存映射
int lcd_open();

// 图片显示封装
int show_bmp(char *pathname, int x0, int y0);

//主界面背景
void Main_Interface();

//游戏界面背景
void Interface();

//排行榜界面
void leaderboard();

//结束界面
void gameover();

//返回按钮
void return_button();

//选择角色界面
void role();

//加载退出按钮
void leave_button();

#endif 