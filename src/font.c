#include "head.h"
//注意：编码格式必须是GB2312

//显示积分板 
void  *sroce()
{
    char count[10]={0};//定义一个数组
    printf("start:\n");//开始计分
    while (1)
    {
        if(pthread_kill(tid_enemy, 0)==0)
        {
            //延时0.1秒，避免屏幕闪烁
            usleep(100000);
            Clean_Area(719,0,80,40,0x000000ff);                //清屏，蓝色背景
            sprintf(count, "%d", num);                         //将num存入到字符串中去
            Display_characterX(759,0,count,0x0000ff00,2);    //显示字符串，绿色字体           
        }
        else
        {
            //结束计分线程
            pthread_exit(NULL);
        }
    }  
}

//显示角色信息 
int introduce(void)
{
    //定义字符串存储需要打印的内容
	char *str="点击头像选择你要使用角色";
	char *str1_0 = "齐天大圣:";
    char *str1_1 = "孙悟空由开天辟地产生的仙石孕育而生 ，出生地位于东胜神洲的花果山，";
	char *str1_2 = "为了学艺而漂洋过海拜师于须菩提祖师 ，学会七十二变 、筋斗云等法术。";
	char *str2_0 = "孤高曼波:";
	char *str2_1 = "出自赛马娘手游里的人气角色“诗歌剧”，在个人剧情第七章里，";
	char *str2_2 = "哼唱了一段她爸爸教给她的口号。曼波是翻车鱼的意思。";
	char *str3_0 = "中分坤哥:";
	char *str3_1 = "大家好，我是练习时长，两年半的，个人练习生，蔡徐坤，喜欢，唱，跳，rop，music！";
	char *str3_2 = "在今后的节目中，有我很多作词，作曲，编舞的原创作品，期待的话多多投票吧！！";
	//界面介绍
	Display_characterX(0,0,str,0x0000ff00,3);     //显示字符串，绿色字体
	//显示齐天大圣介绍
    Display_characterX(100,80,str1_0,0x000000ff,2);     //显示字符串，蓝色字体
    Display_characterX(100,120,str1_1,0x00ff0000,1);    //显示字符串，红色字体
    Display_characterX(100,160,str1_2,0x00ff0000,1);    //显示字符串，红色字体
	//显示孤高曼波介绍
	Display_characterX(100,240,str2_0,0x000000ff,2);    //显示字符串，蓝色字体
	Display_characterX(100,280,str2_1,0x00ff0000,1);    //显示字符串，红色字体
	Display_characterX(100,300,str2_2,0x00ff0000,1);    //显示字符串，红色字体
	//显示中分坤哥介绍
    Display_characterX(100,400,str3_0,0x000000ff,2);    //显示字符串，蓝色字体
    Display_characterX(100,440,str3_1,0x00ff0000,1);    //显示字符串，红色字体
	Display_characterX(100,460,str3_2,0x00ff0000,1);    //显示字符串，红色字体
}


