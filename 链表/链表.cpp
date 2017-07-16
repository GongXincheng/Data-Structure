/*
	2017��7��6�� 16:54:35
	��ϰ����
	ע�� ɾ�� ���� ��������
*/

# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

typedef struct Node
{
	int data;			//������
	struct Node * pNext;	//ָ����

}NODE, *PNODE;

PNODE create();	//��������
bool is_empty(PNODE pHead);	//�����Ƿ�Ϊ��
void traverse(PNODE pHead);	//��������
int get_length(PNODE pHead);	//��ȡ������
int get_val(PNODE pHead, int pos);	//��ȡָ��λ�ýڵ�
void sort(PNODE pHead);		//����������
bool insert_list(PNODE pHead, int pos, int val);	//����ڵ�
bool delete_list(PNODE pHead, int pos, int * val);	//ɾ���ڵ�


int main(void)
{
	PNODE pHead;
	int val; //���ڴ��ɾ����ֵ

	pHead = create();	//��������
	printf("����������Ϊ��");
	traverse(pHead);	//��������

	printf("\n������Ϊ��%d\n", get_length(pHead) );	//��ȡ������	
	printf("��3���ڵ��ֵΪ��%d\n", get_val(pHead, 3) );
	
	sort(pHead);		//����
	printf("\n�����");
	traverse(pHead);

	insert_list(pHead, 3, 100);
	printf("�����");
	traverse(pHead);

	delete_list(pHead, 3, &val);
	printf("ɾ����");
	traverse(pHead);
	printf("ɾ���Ľڵ��ֵΪ��%d\n", val);

	return 0;
}
//��������
PNODE create(){
	int len,val;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));	//����ͷ�ڵ�
	if(pHead == NULL){
		printf("��̬�ڴ����ʧ��\n");
		exit(-1);
	}
	PNODE pTail = pHead;				//pTailʼ��ָ�����һ���ڵ�
	pTail->pNext = NULL;
	printf("����������Ľڵ������");
	scanf("%d", &len);

	for(int i=0; i<len; i++){
		printf("��%d���ڵ��ֵ��",i+1);
		scanf("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));	//����һ���µĽڵ�
		if(pNew == NULL){
			printf("��̬�ڴ����ʧ��\n");
			exit(-1);
		}
		
		pNew->data = val;
		pNew->pNext = NULL;
		pTail->pNext = pNew;
		pTail = pNew;
	}	
	return pHead;
}

//�����Ƿ�Ϊ��
bool is_empty(PNODE pHead){
	PNODE p = pHead->pNext;
	if(p == NULL)
		return true;
	else
		return false;
}

//��������
void traverse(PNODE pHead){
	PNODE p = pHead->pNext;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return ;
}

//��ȡ������
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

//��ȡָ��λ�ýڵ�	
int get_val(PNODE pHead, int pos)
{
	PNODE p = pHead;
	int length = get_length(pHead);
	if(pos<1 || pos>length){
		printf("����Խ�磡");
		return -1;
	}
	for(int i=0; i<pos; i++){
		p = p->pNext;
	}
	return p->data;
}
//����������
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
//����ڵ�
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
	PNODE pNew = (PNODE)malloc(sizeof(NODE));	//����һ���µĽڵ�
	if(pNew == NULL){
		printf("��̬�ڴ����ʧ��\n");
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}
//ɾ���ڵ�
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

/*	���Ϊ��
---------------------------------------
����������Ľڵ������5
��1���ڵ��ֵ��2
��2���ڵ��ֵ��1
��3���ڵ��ֵ��6
��4���ڵ��ֵ��8
��5���ڵ��ֵ��7
����������Ϊ��2 1 6 8 7

������Ϊ��5
��3���ڵ��ֵΪ��6

�����1 2 6 7 8
�����1 2 100 6 7 8
ɾ����1 2 6 7 8
ɾ���Ľڵ��ֵΪ��100
ress any key to continue
---------------------------------------
*/