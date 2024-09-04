#ifndef __LIST_H__
#define __LIST_H__

//数据域结构体
typedef struct data{
	char  name[20];//角色名
	int   score;//得分
}Data;

//设计链表节点模型
typedef struct list{
	/**数据域**/
	Data *data; //信息结构体
	/**指针域**/
	struct list *next;//后继指针
}List;

//链表模型
List *head;

//节点模型
List *node;

//初始化
List *list_init(void);

//申请节点来保存数据
List *requset_node(Data);

//将链表信息写入到文件中
int show_list(List *);

//尾插
int insert_tail(List *,List *);

//找到比node小的节点，插入到它的前面
int insert_sort(List *,List *);

//写入对应节点信息到文件
int file_write(Data *);

#endif