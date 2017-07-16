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
bool insert_list(PNODE pHead, int, int );
bool delete_list(PNODE pHead, int, int* );

int main(void)
{
	PNODE pHead;
	int val;

	pHead = create_list();	//创建链表，并将头结点的地址返回给pHead

	traverse_list(pHead);	//遍历链表

	if(is_empty(pHead))		//判断链表是否为空
		printf("null\n");
	else
		printf("not null\n");

	sort_lsit(pHead);		//排序
	printf("排序后：");
	traverse_list(pHead);
	
	printf("链表长度为：%d\n", length_list(pHead));	//输出链表长度

	insert_list(pHead, 3, 100 );			//插入
	printf("插入后的链表：");
	traverse_list(pHead);
	printf("插入后链表长度为：%d\n",length_list(pHead));

	delete_list(pHead, 3, &val);			//删除
	printf("删除后的链表：");
	traverse_list(pHead);
	printf("删除的值为: %d\n", val);
	printf("链表长度为：%d\n",length_list(pHead));

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
//如果链表长度为2  pos为4	pos为3  pos为-1
bool insert_list(PNODE pHead, int pos, int val){
	int i = 0;
	PNODE p = pHead;
					// i<3  i<2
	while(p!=NULL && i<pos-1){	//	t	t	 t			//	t	t	f				//	f
		p = p->pNext;			//	1	2	null		//	1	2	
		i++;					//	1	2	 3			//	1	2	
	}
	if(i>pos-1 || p==NULL)		// 3>3 || NULL==NULL	//	2>2 || 	not == NULL		// 0>-1   p!=null
		return false;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL){
		printf("动态内存分配失败!");
		exit(-1);
	}
	pNew->data = val;		//数据域
	pNew->pNext = p->pNext;	//指针域
	p->pNext = pNew;		
	return true;
}
//如果链表长度为2  pos为3	pos为2  pos为-1
bool delete_list(PNODE pHead, int pos, int * val){
	int i = 0;
	PNODE p = pHead;
							//i<2 i<1
	while(p->pNext!=NULL && i<pos-1){	//	t	t	f				// t  f					//f
		p = p->pNext;					//	1	2  null				// 1  
		i++;							//	1	2					// 1  
	}
	if(i>pos-1 || p->pNext == NULL)		// 2>2 || null==null		1>1 || not==null		// 0>-2  
		return false;
	
	PNODE q = p->pNext;		//保存要删除的节点
	*val = q->data;			//保存删除的数据域的数据
	p->pNext = q->pNext;	//前一个节点的指针域指向后一个节点
	free(q);				//释放节点
	q=NULL;
	
	return true;
}



