/*链表的创建和遍历*/

# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node 
{
	int data;	//数据域
	struct Node * pNext;	//指针域

}NODE, *PNODE;

//函数声明
PNODE creat_list(void);
void traverse_list(PNODE pHead);

int main(void)
{
	PNODE pHead = NULL;		//头指针

	pHead = creat_list();	//创建一个非循环单链表，并将该链表头结点的地址赋给pHead
	traverse_list(pHead);	//遍历链表
	free(pHead);
	return 0;
}

PNODE creat_list(void)
{
	int i;		//循环控制变量
	int len;	//定义链表的长度
	int val;	//临时存放数据域数据

	PNODE pHead = (PNODE)malloc(sizeof(NODE));		//创建头结点
	if(pHead == NULL)	//如果内存分配失败
	{	
		printf("内存分配失败！");
		exit(-1);
	}

	PNODE pTail = pHead;	//创建一个尾指针，刚开始指向pHead
	pTail->pNext = NULL;	//必须，刚开始链表为空，所以指针域为空

	printf("请输入链表的长度：len = ");
	scanf("%d", &len);
	
	for(i=0; i<len; i++)
	{
		printf("请输入第%d个节点的值：", i+1);
		scanf("%d",&val);
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));	//创建新的节点
		if(pNew == NULL){
			printf("内存分配失败！");
			exit(-1);
		}
		
		pNew->data = val;	//将数据放入数据域
		pNew->pNext = NULL;	//把该节点挂在链表最后一个，所以指针域为空
		pTail->pNext = pNew; 
		pTail = pNew;		
	}
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while(p!=NULL){
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}