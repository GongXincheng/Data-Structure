# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{	
	int data;
	struct Node * pNext;

}NODE, *PNODE;

PNODE create_list();
void traverse_list(PNODE);
int length_list(PNODE);
bool is_empty(PNODE);
void sort_list(PNODE);
bool insert_list(PNODE, int, int );
bool delete_list(PNODE, int, int* );
int get(PNODE pHead, int pos);

int main(void)
{
	int val;
	PNODE pHead;
	
	pHead = create_list();	//��������
	traverse_list(pHead);	//��������

	
	printf("����ĳ��ȣ�len = %d\n", length_list(pHead));	//������

	if( is_empty(pHead) ){			//�����Ƿ�Ϊ��
		printf("�����Ƿ�Ϊ�գ���\n");
	}
	else{
		printf("�����Ƿ�Ϊ�գ���\n");
	}
	
	sort_list(pHead);			//����
	printf("����������Ϊ��");
	traverse_list(pHead);

	insert_list(pHead, 3, 100);
	printf("����������Ϊ��");
	traverse_list(pHead);

	delete_list(pHead, 3, &val);
	printf("ɾ���������Ϊ��");
	traverse_list(pHead);
	printf("ɾ����ֵΪ��%d\n", val);

	
	printf("��%d���ڵ��ֵ��%d\n", 3, get(pHead, 3));

	return 0;
}

PNODE create_list(){
	int len,i,val;
	
	PNODE pHead = (PNODE)malloc(sizeof(NODE));	//����ͷ���
	if(pHead==NULL){
		printf("�ڴ����ʧ��");
		exit(-1);
	}

	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("����ĳ��ȣ�len = ");
	scanf("%d", &len);

	for(i=0; i<len; i++){
		printf("��%d���ڵ��ֵ��",i+1);
		scanf("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(pNew==NULL){
			printf("�ڴ����ʧ��");
			exit(-1);
		}

		pNew->data = val;
		pNew->pNext = NULL;
		pTail->pNext = pNew;
		pTail = pNew;
	}
	return pHead;
}

void traverse_list(PNODE pHead){
	PNODE p = pHead->pNext;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

int length_list(PNODE pHead){
	int len=0;
	PNODE p = pHead->pNext;
	while(p!=NULL){
		len++;
		p = p->pNext;
	}
	return len;
}

bool is_empty(PNODE pHead){
	PNODE p = pHead->pNext;
	if(p!=NULL)
		return false;
	else
		return true;
}

void sort_list(PNODE pHead){
	int i,j,t;
	int len = length_list(pHead);
	PNODE p,q;
	for(i=0,p=pHead->pNext; i<len-1; i++,p=p->pNext){
		for(j=i+1,q=p->pNext; j<len; j++,q=q->pNext){
			if(p->data > q->data){
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return;
}

bool insert_list(PNODE pHead, int pos, int val){
	int i = 0;
	PNODE p = pHead;
	while(p!=NULL && i<pos-1){
		p = p->pNext;
		i++;
	}
	if(i>pos-1 || p==NULL){
		return false;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->pNext = p->pNext;
	pNew->data = val;
	p->pNext = pNew;
	return true;
}

bool delete_list(PNODE pHead, int pos, int* val){
	int i = 0;
	PNODE p = pHead;
	while(p->pNext!=NULL && i<pos-1){
		p = p->pNext;
		i++;
	}
	if(i>pos-1 || p->pNext==NULL){
		return false;
	}
	
	PNODE q = p->pNext;
	*val = q->data;
	p->pNext = q->pNext;
	free(q);
	q=NULL;
	return true;
}

int get(PNODE pHead, int pos){
	int i = 0;
	PNODE p = pHead;
	/*
	while(p!=NULL && i<pos){
		p = p->pNext;
		i++;
	}
	*/

	for(i; i<pos; i++){
		p = p->pNext;
	}

	return p->data;
}