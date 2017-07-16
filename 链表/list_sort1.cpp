# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;

}NODE, *PNODE;

PNODE create_list();	//创建链表
void traverse_list(PNODE pHead);	//遍历链表
bool is_empty(PNODE pHead);		//链表是否为空
int length_list(PNODE pHead);	//获取链表的长度
void sort_lsit(PNODE pHead);	//排序

int main(void)
{
	PNODE pHead;

	pHead = create_list();	//创建链表，并将头结点的地址返回给pHead

	traverse_list(pHead);	//遍历链表

	if(is_empty(pHead))		//判断链表是否为空
		printf("null\n");
	else
		printf("not null\n");

	sort_lsit(pHead);		//排序
	traverse_list(pHead);

	int len = length_list(pHead);	//输出链表长度
	printf("链表长度为：%d\n",len);

	return 0;
}

//创建链表
PNODE create_list(){
	int i;
	int len;
	int val;

	PNODE pHead = (PNODE)malloc(sizeof(NODE));	//创建头结点
	if(pHead == NULL){
		printf("内存分配失败！");
		exit(-1);
	}

	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入链表节点个数：len = ");
	scanf("%d", &len);

	for(i=0; i<len; i++){
		printf("第%d个节点的值：",i+1);
		scanf("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(pNew == NULL){
			printf("内存分配失败！");
			exit(-1);
		}

		pNew->data = val;
		pNew->pNext = NULL;

		pTail->pNext = pNew;	//让上一个节点的指针域指向当前节点
		pTail = pNew;			//最后一个节点变为pTail
	}
	return pHead;
}

//遍历链表
void traverse_list(PNODE pHead){
	PNODE p = pHead->pNext;			// p为首元节点
	while(p!=NULL){
		printf("%d ", p->data);
		p = p->pNext;				// 移动到下一个节点
	}
	printf("\n");
	return;
}	

//链表是否为空
bool is_empty(PNODE pHead){
	if(pHead->pNext == NULL)		//只需判断头结点的指针域是否为空
		return true;
	else
		return false;
}

//获取链表的长度
int length_list(PNODE pHead){
	PNODE p = pHead->pNext;
	int len=0;
	while(p!=NULL){
		len++;
		p = p->pNext;
	}
	return len;
}

//排序
void sort_lsit(PNODE pHead){
	int i,j,t;
	int len = length_list(pHead);
	PNODE p,q;

	for(i=0,p=pHead->pNext; i<len-1; i++,p=p->pNext){
		for(j=i+1,q=p->pNext; j<len; j++,q=q->pNext){
			if(p->data>q->data){
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return ;
}

