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

int main(void)
{
	PNODE pHead = NULL;
	pHead = create_list();
	traverse_list(pHead);

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
}