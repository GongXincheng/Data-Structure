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

//��������
void init(PSTACK pStack);		//��ջ��ʼ��
void push(PSTACK pStack,int val);	//��ջ/ѹջ
void traverse(PSTACK pStack);	//����
bool pop(PSTACK pStack, int *);	//��ջ
void clear(PSTACK pStack);		//���ջ�ڽڵ�
bool is_empty(PSTACK pStack);	//ջ�Ƿ�Ϊ��

int main(void)
{	
	STACK stack;
	int val;

	init(&stack);		//��ջ��ʼ��

	push(&stack,1);		//��ջ/ѹջ
	push(&stack,2);
	push(&stack,3);
	printf("��ջ��");
	traverse(&stack);	//����

	pop(&stack, &val);	//��ջ
	printf("��ջ��");
	traverse(&stack);
	printf("��ջ��ֵΪ��%d\n", val);

	clear(&stack);		//���ջ
	printf("�����");
	traverse(&stack);

	return 0;
}
//��ջ��ʼ��
void init(PSTACK pStack)
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(pHead == NULL){
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	else{
		pHead->pNext = NULL;
		pStack->pBottom = pHead;
		pStack->pTop = pHead;
		return ;
	}
}
//��ջ/ѹջ
void push(PSTACK pStack,int val){
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew==NULL){
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	else{
		pNew->pNext = pStack->pTop;
		pNew->data = val;
		pStack->pTop = pNew;
		return;
	}
}
//����
void traverse(PSTACK pStack){
	if( is_empty(pStack) ){
		printf("ջΪ��ջ��");
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
//��ջ
bool pop(PSTACK pStack, int * pVal){
	if( is_empty(pStack) ){
		printf("ջΪ��ջ��");
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
//���ջ�ڽڵ�	
void clear(PSTACK pStack){
	if( is_empty(pStack) ){
		printf("ջΪ��ջ��\n");
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
//ջ�Ƿ�Ϊ��
bool is_empty(PSTACK pStack){
	if(pStack->pBottom == pStack->pTop)
		return true;
	else
		return false;
}	