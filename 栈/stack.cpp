# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node		//节点
{
	int data;
	struct Node *pNext;

}NODE, * PNODE;

typedef struct Stack	//栈
{
	PNODE pTop;
	PNODE pBottom;

}STACK, * PSTACK;

//函数声明
void init(PSTACK pStack);		//对栈初始化
void push(PSTACK pStack,int val);	//入栈/压栈
void traverse(PSTACK pStack);	//遍历
bool pop(PSTACK pStack, int *);	//出栈
void clear(PSTACK pStack);		//清除栈内节点
bool is_empty(PSTACK pStack);	//栈是否为空


int main()
{
	STACK stack;
	int val;

	init(&stack);		//对栈初始化

	push(&stack,1);		//入栈/压栈
	push(&stack,2);
	push(&stack,3);
	printf("入栈后：");
	traverse(&stack);	//遍历

	pop(&stack, &val);	//出栈
	printf("出栈后：");
	traverse(&stack);
	printf("出栈的值为：%d\n", val);

	clear(&stack);		//清除栈
	printf("清除后：");
	traverse(&stack);

	return 0;
}


void init(PSTACK pStack){

	PNODE pHead = (PNODE)malloc(sizeof(NODE));	//创建头结点
	if(pHead==NULL){
		printf("动态内存分配失败！");
		exit(-1);
	}
	pHead->pNext = NULL;		//头结点的指针域为空
	pStack->pTop = pHead;		//栈 top 指向头结点
	pStack->pBottom = pHead;	//栈 bottom 指向头结点
	return ;
}

void push(PSTACK pStack,int val){
	PNODE pNew = (PNODE)malloc(sizeof(NODE));	//创建新的节点
	if(pNew==NULL){
		printf("动态内存分配失败！");
		exit(-1);
	}

	pNew->data = val;			//数据域
	pNew->pNext = pStack->pTop;	//新节点的指针域 指向前一个节点(pStack->pTop保存了前一个节点的地址)
	pStack->pTop = pNew;		//将新节点的地址赋给pTop, pTop 指向新的节点(最上方的节点)
	return ;
}
void traverse(PSTACK pStack){
	PNODE p = pStack->pTop;		//p指向最上面的节点
	if(is_empty(pStack)){
		printf("栈为空栈！\n");
		return ;
	}
	else{
		while(p!=pStack->pBottom){	//当p不指向头结点的时候
			printf("%d ", p->data);
			p = p->pNext;			//向下移动
		}
		printf("\n");
		return;
	}
}

bool pop(PSTACK pStack, int * pVal){
	if(is_empty(pStack)){
		printf("出栈失败！");
		return false;
	}
	else{
		PNODE r = pStack->pTop;		//r指向最上方的节点（保存最上节点的地址  为了free）
		*pVal = r->data;			//保存值
		pStack->pTop = r->pNext;	//pTop指向 r 下面的节点
		free(r);					
		r = NULL;
		return true;
	}
}
void clear(PSTACK pStack){
	if(is_empty(pStack)){
		return;
	}
	else{
		PNODE p = pStack->pTop;			//p指向最上方的节点
		PNODE q = NULL;					//q 刚开始为空
		while(p!=pStack->pBottom){		//如果p不指向头节点
			q = p->pNext;				//q 指向 p的下一个节点
			free(p);					
			p = q;						//将下一个节点赋给p 循环
		}
		pStack->pTop = p;				//pTop 指向头结点
		return;
	}
}

bool is_empty(PSTACK pStack){
	if(pStack->pTop == pStack->pBottom)
		return true;
	else
		return false;
}