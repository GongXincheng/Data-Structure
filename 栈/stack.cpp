# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node		//�ڵ�
{
	int data;
	struct Node *pNext;

}NODE, * PNODE;

typedef struct Stack	//ջ
{
	PNODE pTop;
	PNODE pBottom;

}STACK, * PSTACK;

//��������
void init(PSTACK pStack);		//��ջ��ʼ��
void push(PSTACK pStack,int val);	//��ջ/ѹջ
void traverse(PSTACK pStack);	//����
bool pop(PSTACK pStack, int *);	//��ջ
void clear(PSTACK pStack);		//���ջ�ڽڵ�
bool is_empty(PSTACK pStack);	//ջ�Ƿ�Ϊ��


int main()
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


void init(PSTACK pStack){

	PNODE pHead = (PNODE)malloc(sizeof(NODE));	//����ͷ���
	if(pHead==NULL){
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	pHead->pNext = NULL;		//ͷ����ָ����Ϊ��
	pStack->pTop = pHead;		//ջ top ָ��ͷ���
	pStack->pBottom = pHead;	//ջ bottom ָ��ͷ���
	return ;
}

void push(PSTACK pStack,int val){
	PNODE pNew = (PNODE)malloc(sizeof(NODE));	//�����µĽڵ�
	if(pNew==NULL){
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}

	pNew->data = val;			//������
	pNew->pNext = pStack->pTop;	//�½ڵ��ָ���� ָ��ǰһ���ڵ�(pStack->pTop������ǰһ���ڵ�ĵ�ַ)
	pStack->pTop = pNew;		//���½ڵ�ĵ�ַ����pTop, pTop ָ���µĽڵ�(���Ϸ��Ľڵ�)
	return ;
}
void traverse(PSTACK pStack){
	PNODE p = pStack->pTop;		//pָ��������Ľڵ�
	if(is_empty(pStack)){
		printf("ջΪ��ջ��\n");
		return ;
	}
	else{
		while(p!=pStack->pBottom){	//��p��ָ��ͷ����ʱ��
			printf("%d ", p->data);
			p = p->pNext;			//�����ƶ�
		}
		printf("\n");
		return;
	}
}

bool pop(PSTACK pStack, int * pVal){
	if(is_empty(pStack)){
		printf("��ջʧ�ܣ�");
		return false;
	}
	else{
		PNODE r = pStack->pTop;		//rָ�����Ϸ��Ľڵ㣨�������Ͻڵ�ĵ�ַ  Ϊ��free��
		*pVal = r->data;			//����ֵ
		pStack->pTop = r->pNext;	//pTopָ�� r ����Ľڵ�
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
		PNODE p = pStack->pTop;			//pָ�����Ϸ��Ľڵ�
		PNODE q = NULL;					//q �տ�ʼΪ��
		while(p!=pStack->pBottom){		//���p��ָ��ͷ�ڵ�
			q = p->pNext;				//q ָ�� p����һ���ڵ�
			free(p);					
			p = q;						//����һ���ڵ㸳��p ѭ��
		}
		pStack->pTop = p;				//pTop ָ��ͷ���
		return;
	}
}

bool is_empty(PSTACK pStack){
	if(pStack->pTop == pStack->pBottom)
		return true;
	else
		return false;
}