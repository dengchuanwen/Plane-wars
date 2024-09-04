#include "head.h"

int main(int argc, char const *argv[])
{
	// 初始化硬件并作内存映射
	lcd_open();
	ts_open();
	//打开文件
	file_open();
	//初始化字库
	Init_Font();       
	//初始化链表
 	head = list_init();
	//实例化Data结构体
	Data data;
 	//定义node节点
	node = NULL;
	flag: 
    // 进入主页面
    Main_Interface();
	//加载退出按钮
	leave_button();
	//进入循环
	while(1)
	{
		//判断主界面屏幕点击位置
		get_xy(&x, &y);
		//退出游戏
		//进入排行榜
		if(x > 60 && x<130 && y >130 && y <360)
		{
			//显示排行榜界面和退出按钮
			leaderboard();
			//判断排行榜界面屏幕点击位置
			while(1)
			{
				//获取屏幕触摸的坐标
				get_xy(&x, &y);
				if(x > 719 && x<800 && y >0 && y <140)
				{
					//返回到主页面
					goto flag;
				}
			}
		}
		//开始游戏
		if(x > 165 && x<240 && y >130 && y <360)
		{
			//进入选择角色界面
			role();
			//打印角色信息
			introduce();
			while (1)
			{
				//获取屏幕触摸的坐标
				get_xy(&x, &y);
				//选择一号角色
				if(x<=80&&y>=80&&y<=160)
				{
					//设置角色
					i=1;
					//加载游戏背景
					Interface();
					// 创建敌方战机线程
					pthread_create(&tid_enemy, NULL, enemy_air, 0);
					// 创建计分线程
					pthread_create(&tid_sroce, NULL,sroce, 0);
					//启动我方战机
					our_air();
					//跳出所有循环进入游戏结束页面
					goto flag1;
				}
				//选择二号角色
			    else if(x<=80&&y>=240&&y<=320)
				{
					//设置角色
					i=2;
					//加载游戏背景
					Interface();
					// 创建敌方战机线程
					pthread_create(&tid_enemy, NULL, enemy_air, 0);
					// 创建计分线程
					pthread_create(&tid_sroce, NULL,sroce, 0);
					//启动我方战机
					our_air();
					//跳出所有循环进入游戏结束页面
					goto flag1;
				}
				//选择三号角色
				else if(x<=80&&y>=400&&y<=480)
				{
					//设置角色
					i=3;
					//加载游戏背景
					Interface();
					// 创建敌方战机线程
					pthread_create(&tid_enemy, NULL, enemy_air, 0);
					// 创建计分线程
					pthread_create(&tid_sroce, NULL,sroce, 0);
					//启动我方战机
					our_air();
					//跳出所有循环进入游戏结束页面
					goto flag1;
				}
			}
		}
		//跳出循环，退出游戏
		else if(659<=x&&y<=79)
		{
			break;
		}
	}
	//游戏结束页面
	if(0)
	{
		flag1:
		//显示游戏结束的界面
		show_bmp("/Even/project/picture/enemy_end.bmp", 0, 0);
		//给结构体赋值
		strcpy(data.name,air_name);//记录我方角色姓名
		data.score=num;//记录我方得分
		//申请链表节点
		node = requset_node(data);
		//插入到所有比他小的数前面
		insert_sort(head,node);
		return_button();//显示返回按钮

		while(1)
		{
			//获取屏幕触摸参数
			get_xy(&x, &y);
			//点击返回主界面
			if(x > 719 && x<800 && y >0 && y <140)
			{
				goto flag;
			}
		}    
	}
	//屏幕显示链表内容并且写入到文件中去
	show_list(head);   
	//关闭字库
	UnInit_Font(); 
    // 解除映射，关闭硬件
	munmap(lcd_map, 800*480*4);
	// 关闭lcd，ts，文件
	fclose(file);
	close(lcd_fd);
	close(ts_fd);
}
