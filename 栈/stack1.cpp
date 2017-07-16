# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

typedef struct Node
{
	int data;
	struct Node * pNext;

}NODE, * PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;

}STACK, *PSTACK;

//函数声明
void init(PSTACK pStack);		//对栈初始化
void push(PSTACK pStack,int val);	//入栈/压栈
void traverse(PSTACK pStack);	//遍历
bool pop(PSTACK pStack, int *);	//出栈
void clear(PSTACK pStack);		//清除栈内节点
bool is_empty(PSTACK pStack);	//栈是否为空

int main(void)
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
//对栈初始化
void init(PSTACK pStack)
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(pHead == NULL){
		printf("动态内存分配失败！");
		exit(-1);
	}
	else{
		pHead->pNext = NULL;
		pStack->pBottom = pHead;
		pStack->pTop = pHead;
		return ;
	}
}
//入栈/压栈
void push(PSTACK pStack,int val){
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew==NULL){
		printf("动态内存分配失败！");
		exit(-1);
	}
	else{
		pNew->pNext = pStack->pTop;
		pNew->data = val;
		pStack->pTop = pNew;
		return;
	}
}
//遍历
void traverse(PSTACK pStack){
	if( is_empty(pStack) ){
		printf("栈为空栈！");
		return ;
	}
	else{
		PNODE p = pStack->pTop;
		while(p != pStack->pBottom){
			printf("%d ", p->data);
			p = p->pNext;
		}
		printf("\n");
		return ;
	}
}
//出栈
bool pop(PSTACK pStack, int * pVal){
	if( is_empty(pStack) ){
		printf("栈为空栈！");
		return false;
	}
	else{
		PNODE r = pStack->pTop;
		*pVal = r->data;
		pStack->pTop = r->pNext;
		free(r);
		r = NULL;
		return true;
	}
}
//清除栈内节点	
void clear(PSTACK pStack){
	if( is_empty(pStack) ){
		printf("栈为空栈！\n");
		return;
	}
	else{
		PNODE p = pStack->pTop;
		PNODE q =NULL;
		while(p!=pStack->pBottom){
			q = p->pNext;
			free(p);
			p = q;
		}
		pStack->pTop = p;
		return;
	}
}	
//栈是否为空
bool is_empty(PSTACK pStack){
	if(pStack->pBottom == pStack->pTop)
		return true;
	else
		return false;
}	