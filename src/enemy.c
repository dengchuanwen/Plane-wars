#include "head.h"

//敌方飞机
void *enemy_air()
{
    num=0;//将击毁敌机数量设为0

    while(1)
    {
        //飞机随机生成在某一路
        j, k=650;//设置j和k的初始值
        j=rand()%7*60;//随机给j分配0-360的值
        show_bmp("/Even/project/picture/enemy.bmp", 650, j);//显示敌机图片
        //飞机向前飞
        while (k)
        {
            //销毁原来位置的敌机
            show_bmp("/Even/project/picture/enemy_black.bmp", k+80,j);
            //当敌机在炮弹线上
            if(last_y>=j && last_y<=j+80 && last_x+80<=k)
            {
                //销毁飞机
                show_bmp("/Even/project/picture/black.bmp", k, j);
                //画新激光
                for(int x2=x+40;x2<800;x2++)
                {
                    //打印攻击图片
                    show_bmp("/Even/project/picture/gongji.bmp", x2, y-2);
                }
                break;
            }
            //当敌机撞上我们的飞机
            else if(x-40<=k+80&&x+40>=k && y-40<=j+80 && y+40>=j)
            {
                //结束敌机线程
                pthread_exit(NULL);
            }
            //不在炮弹线上
            else
                //敌机前进一个像素点
                k--;
            //更新敌机位置
            show_bmp("/Even/project/picture/enemy.bmp", k, j);
            //延时2 毫秒，避免卡顿
            usleep(2000);
        }

        //当飞机飞到终点
        if(k==0)
        {
            //结束敌机线程
            pthread_exit(NULL);
        }
        else
        {
            //记录摧毁敌机数
            num++;
        }
    }
}
