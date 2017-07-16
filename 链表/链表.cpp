/*
	2017年7月6日 16:54:35
	复习链表
	注意 删除 插入 创建链表
*/

# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

typedef struct Node
{
	int data;			//数据域
	struct Node * pNext;	//指针域

}NODE, *PNODE;

PNODE create();	//创建链表
bool is_empty(PNODE pHead);	//链表是否为空
void traverse(PNODE pHead);	//遍历链表
int get_length(PNODE pHead);	//获取链表长度
int get_val(PNODE pHead, int pos);	//获取指定位置节点
void sort(PNODE pHead);		//对链表排序
bool insert_list(PNODE pHead, int pos, int val);	//插入节点
bool delete_list(PNODE pHead, int pos, int * val);	//删除节点


int main(void)
{
	PNODE pHead;
	int val; //用于存放删除的值

	pHead = create();	//创建链表
	printf("创建的链表为：");
	traverse(pHead);	//遍历链表

	printf("\n链表长度为：%d\n", get_length(pHead) );	//获取链表长度	
	printf("第3个节点的值为：%d\n", get_val(pHead, 3) );
	
	sort(pHead);		//排序
	printf("\n排序后：");
	traverse(pHead);

	insert_list(pHead, 3, 100);
	printf("插入后：");
	traverse(pHead);

	delete_list(pHead, 3, &val);
	printf("删除后：");
	traverse(pHead);
	printf("删除的节点的值为：%d\n", val);

	return 0;
}
//创建链表
PNODE create(){
	int len,val;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));	//创建头节点
	if(pHead == NULL){
		printf("动态内存分配失败\n");
		exit(-1);
	}
	PNODE pTail = pHead;				//pTail始终指向最后一个节点
	pTail->pNext = NULL;
	printf("请输入链表的节点个数：");
	scanf("%d", &len);

	for(int i=0; i<len; i++){
		printf("第%d个节点的值：",i+1);
		scanf("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));	//创建一个新的节点
		if(pNew == NULL){
			printf("动态内存分配失败\n");
			exit(-1);
		}
		
		pNew->data = val;
		pNew->pNext = NULL;
		pTail->pNext = pNew;
		pTail = pNew;
	}	
	return pHead;
}

//链表是否为空
bool is_empty(PNODE pHead){
	PNODE p = pHead->pNext;
	if(p == NULL)
		return true;
	else
		return false;
}

//遍历链表
void traverse(PNODE pHead){
	PNODE p = pHead->pNext;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return ;
}

//获取链表长度
int get_length(PNODE pHead){
	int len = 0;
	PNODE p = pHead->pNext;
	while(p!=NULL)
	{
		len++;
		p = p->pNext;
	}
	return len;	
}

//获取指定位置节点	
int get_val(PNODE pHead, int pos)
{
	PNODE p = pHead;
	int length = get_length(pHead);
	if(pos<1 || pos>length){
		printf("错误，越界！");
		return -1;
	}
	for(int i=0; i<pos; i++){
		p = p->pNext;
	}
	return p->data;
}
//对链表排序
void sort(PNODE pHead)
{
	int i,j,t;
	int length = get_length(pHead);
	PNODE p,q;
	for(i=0,p=pHead->pNext; i<length-1; i++,p=p->pNext){
		for(j=i+1,q=p->pNext; j<length; j++,q=q->pNext){
			if(p->data>q->data){
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return ;
}	
//插入节点
bool insert_list(PNODE pHead, int pos, int val){
	PNODE p = pHead;
	int i = 0;
	while(p!=NULL && i<pos-1){
		p = p->pNext;
		i++;
	}
	if(i>pos-1 || p==NULL){
		return false;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));	//创建一个新的节点
	if(pNew == NULL){
		printf("动态内存分配失败\n");
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}
//删除节点
bool delete_list(PNODE pHead, int pos, int * val)
{	
	int i = 0;
	PNODE p = pHead;
	while(i<pos-1 && p->pNext!=NULL){
		p = p ->pNext;
		i++;
	}
	if(i>pos-1 || p->pNext==NULL){
		return false;
	}
	
	PNODE q = p->pNext;
	*val = q->data;
	p->pNext = q->pNext;
	free(q);
	q = NULL;
	return true;
}

/*	结果为：
---------------------------------------
请输入链表的节点个数：5
第1个节点的值：2
第2个节点的值：1
第3个节点的值：6
第4个节点的值：8
第5个节点的值：7
创建的链表为：2 1 6 8 7

链表长度为：5
第3个节点的值为：6

排序后：1 2 6 7 8
插入后：1 2 100 6 7 8
删除后：1 2 6 7 8
删除的节点的值为：100
ress any key to continue
---------------------------------------
*/