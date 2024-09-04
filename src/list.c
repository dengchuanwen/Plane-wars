#include "head.h"

List *list_init(void)
{
	//申请头节点的堆内存
	List *head = malloc(sizeof(List));
	//给结构体分配内存
	head->data = (Data *)malloc(sizeof(Data)); 
	//判断节点是否申请成功
	if(head == NULL)
	{
		printf("申请头节点失败\n");
		return NULL;
	}
	//清空头节点的数据域
	strcpy(head->data->name,"0");
	head->data->score=0;
	//刚初始化的头节点后面没有节点
	head->next = NULL;
	//返回头节点地址
	return head;
}

//申请节点来保存数据
List *requset_node(Data data)
{
	//申请节点的堆内存
	List *node = malloc(sizeof(List));
	if(node == NULL)
	{
		printf("申请新节点失败\n");
		return NULL;
	}
	//给结构体分配内存
	node->data = (Data *)malloc(sizeof(Data)); 
	//将数据保存到节点的数据域
	strcpy(node->data->name,data.name);
	node->data->score=data.score;
	//刚初始化的新节点后面没有节点
	node->next = NULL;
	//返回新节点地址
	return node;
}

//将链表信息写入到文件中
int show_list(List *head)
{
	//定义一个链表节点
	List *p = NULL;
	for(p = head->next; p != NULL ;p = p->next)
	{
		//将结点信息写入到文件中
		file_write(p->data);
	}
	printf("\n");
}

//尾插
int insert_tail(List *head,List *node)
{
	//先找到尾节点
	List *p = NULL;
	for(p = head; p->next != NULL ; p = p->next);
	//让尾节点的后继指针指向新节点
	p->next = node;
}

//在链表中找到比node小的节点，插入到它的前面
int insert_sort(List *head,List *node)
{
	//定义一个链表节点
    List *p = NULL; 
    //找到比node小的节点，插入到它的前面
    for(p = head;p->next!=NULL&&p->next->data->score > node->data->score;p=p->next);
	node->next = p->next;
	p->next = node;
}

//写入内容到文件
int file_write(Data *data)
{
	//定义一个字符串，用作传输文件的缓冲区
	char str[100]={'0'};
    // 使用 sprintf 格式化字符串
    sprintf(str, "姓名: %s, 分数: %d", data->name, data->score);
	//将字符串写入文件中
    fprintf(file, "%s", str);
	//将换行符写入文件中
	fprintf(file, "\n");
}
