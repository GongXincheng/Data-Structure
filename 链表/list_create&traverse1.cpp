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
PNODE create_list(void);
void traverse_list(PNODE pHead);

int main(void)
{
	PNODE pHead = NULL;		//头指针

	pHead = create_list();	//创建一个非循环单链表，并将该链表头结点的地址赋给pHead
	traverse_list(pHead);	//遍历链表

	return 0;
}

PNODE create_list(void)
{
	int i;
	int len;
	int val;

	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(pHead == NULL)
	{	
		printf("内存分配失败！");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入链表的长度：len = ");
	scanf("%d", &len);
	
	for(i=0; i<len; i++)
	{
		printf("请输入第%d个节点的值：", i+1);
		scanf("%d",&val);
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(pNew == NULL){
			printf("内存分配失败！");
			exit(-1);
		}
		
		pNew->data = val;
		pNew->pNext = NULL;
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