#include "head.h"


//我方飞机
void* our_air()
{
    //记录最后激光的坐标
    end_x=40;
    end_y=240;
    //记录最后飞机的坐标
    last_x=40;
    last_y=240;
    //生成初始战机
    if(i==1)
    {
        //记录角色姓名
        strcpy(air_name, "齐天大圣");
        show_bmp("/Even/project/picture/own_air1.bmp", end_x-40, end_y-40);//以(end_x,end_y)为中心生成新的飞机
    }
    else if(i==2)
    {
        //记录角色姓名
        strcpy(air_name, "孤高曼波");
        show_bmp("/Even/project/picture/own_air2.bmp", end_x-40, end_y-40);//以(end_x,end_y)为中心生成新的飞机
    }
    else if(i==3)
    {
        //记录角色姓名
        strcpy(air_name, "中分坤哥");
        show_bmp("/Even/project/picture/own_air3.bmp", end_x-40, end_y-40);//以(end_x,end_y)为中心生成新的飞机
    }
    //画初始激光
    for(int x1=last_x+40;x1<800;x1++)
    {
        show_bmp("/Even/project/picture/gongji.bmp", x1, last_y-2);//在飞机正中间画激光
    }
    while(1)
    {
        //如果敌机进程存在
        if(pthread_kill(tid_enemy, 0)==0)
        {
            get_xy(&x, &y);
            if(x>=40&&x<=760&&y>=40&&y<=440)
            {
                show_bmp("/Even/project/picture/black.bmp", end_x-40,end_y-40);//清除原位置飞机
                //删除原激光
                for(int x1=last_x+40;x1<800;x1++)
                {
                    show_bmp("/Even/project/picture/black2.bmp", x1, last_y-2);//删除原激光
                }
                if(i==1)
                    show_bmp("/Even/project/picture/own_air1.bmp", x-40, y-40);//生成新的飞机
                else if(i==2)
                    show_bmp("/Even/project/picture/own_air2.bmp", x-40, y-40);//生成新的飞机
                else if(i==3)
                    show_bmp("/Even/project/picture/own_air3.bmp", x-40, y-40);//生成新的飞机
                //画新激光
                for(int x2=x+40;x2<800;x2++)
                {
                    show_bmp("/Even/project/picture/gongji.bmp", x2, y-2);//在飞机正中间画激光
                }
                //原坐标更新为新坐标
                end_x=x;
                end_y=y;
                //保存上一条激光位置
                last_x=end_x;
                last_y=end_y;
            } 
        }
        //如果敌机进程不存在
        else
        {
            //结束程序，返回0
            return 0;
        }
    }
}
