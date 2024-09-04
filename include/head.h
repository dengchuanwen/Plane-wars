#ifndef __HEAD_H__
#define __HEAD_H__

//头文件声明
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <linux/input.h>
#include "background.h"
#include "own_side.h"
#include "slide.h"
#include "enemy.h"
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>
#include "font.h"
#include "file.h"
#include "list.h"
#include <strings.h>

//声明变量，记录触摸屏幕的坐标
int x, y;

//创建积分的线程
pthread_t tid_sroce; // 线程号

//创建敌人战机的线程号
pthread_t tid_enemy; // 线程号

#endif