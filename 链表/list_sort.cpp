# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

typedef struct Node
{
	int data;
	struct Node * pNext;

}NODE, *PNODE;

PNODE create_list();
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
void sort_lsit(PNODE pHead);

int main(void)
{
	PNODE pHead = NULL;	//���ͷ���ĵ�ַ

	pHead = create_list();	//��������

	traverse_list(pHead);	//��������

	if( is_empty(pHead) )	//�����Ƿ�Ϊ��
		printf("null \n");
	else
		printf("not null \n");
	
	int length = length_list(pHead);	//��ȡ����ĳ���
	printf("����ĳ���Ϊ��%d\n", length);

	sort_lsit(pHead);	//����������
	traverse_list(pHead);
	
	system("pause");
	return 0;
}

PNODE create_list()
{
	int i;
	int len;
	int value;

	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(pHead==NULL){
		printf("�ڴ����ʧ�ܣ�");
		exit(-1);
	}

	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("����������ĳ��ȣ�len = ");
	scanf("%d", &len);

	for(i=0; i<len; i++){
		printf("��%d���ڵ��ֵ��", i+1);
		scanf("%d", &value);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(pNew==NULL){
			printf("�ڴ����ʧ�ܣ�");
			exit(-1);
		}
		
		pNew->data = value;
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
	return;
}

bool is_empty(PNODE pHead){
	if(NULL == pHead->pNext)
		return true;
	else
		return false;
}

int length_list(PNODE pHead){
	int length = 0;
	PNODE p = pHead->pNext;
	while(p != NULL){
		length++;
		p = p->pNext;
	}
	return length;
}

void sort_lsit(PNODE pHead){
	int i,j,t;
	int len = length_list(pHead);
	PNODE p,q;

	for(i=0,p=pHead->pNext; i<len-1; i++,p=p->pNext){
		for(j=i+1,q=p->pNext; j<len; j++,q=q->pNext){
			if(p->data>q->data){		//	if(a[i]>a[j]){
				t = p->data;			//		t = a[i];
				p->data = q->data;		//		a[i] = a[j];
				q->data = t;			//		a[j] = t;
			}
		}
	}
}