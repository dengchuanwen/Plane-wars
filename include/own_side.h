#ifndef __OWN_SIDE_H__
#define __OWN_SIDE_H__

//记录最后激光的坐标
int end_x;
int end_y;

//记录最后飞机的坐标
int last_x;
int last_y;

//记录第几位角色
int i;

//记录角色名
char air_name[20];

//我方飞机
void* our_air();

#endif