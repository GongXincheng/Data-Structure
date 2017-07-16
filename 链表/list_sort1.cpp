# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;

}NODE, *PNODE;

PNODE create_list();	//��������
void traverse_list(PNODE pHead);	//��������
bool is_empty(PNODE pHead);		//�����Ƿ�Ϊ��
int length_list(PNODE pHead);	//��ȡ����ĳ���
void sort_lsit(PNODE pHead);	//����

int main(void)
{
	PNODE pHead;

	pHead = create_list();	//������������ͷ���ĵ�ַ���ظ�pHead

	traverse_list(pHead);	//��������

	if(is_empty(pHead))		//�ж������Ƿ�Ϊ��
		printf("null\n");
	else
		printf("not null\n");

	sort_lsit(pHead);		//����
	traverse_list(pHead);

	int len = length_list(pHead);	//���������
	printf("������Ϊ��%d\n",len);

	return 0;
}

//��������
PNODE create_list(){
	int i;
	int len;
	int val;

	PNODE pHead = (PNODE)malloc(sizeof(NODE));	//����ͷ���
	if(pHead == NULL){
		printf("�ڴ����ʧ�ܣ�");
		exit(-1);
	}

	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("����������ڵ������len = ");
	scanf("%d", &len);

	for(i=0; i<len; i++){
		printf("��%d���ڵ��ֵ��",i+1);
		scanf("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(pNew == NULL){
			printf("�ڴ����ʧ�ܣ�");
			exit(-1);
		}

		pNew->data = val;
		pNew->pNext = NULL;

		pTail->pNext = pNew;	//����һ���ڵ��ָ����ָ��ǰ�ڵ�
		pTail = pNew;			//���һ���ڵ��ΪpTail
	}
	return pHead;
}

//��������
void traverse_list(PNODE pHead){
	PNODE p = pHead->pNext;			// pΪ��Ԫ�ڵ�
	while(p!=NULL){
		printf("%d ", p->data);
		p = p->pNext;				// �ƶ�����һ���ڵ�
	}
	printf("\n");
	return;
}	

//�����Ƿ�Ϊ��
bool is_empty(PNODE pHead){
	if(pHead->pNext == NULL)		//ֻ���ж�ͷ����ָ�����Ƿ�Ϊ��
		return true;
	else
		return false;
}

//��ȡ����ĳ���
int length_list(PNODE pHead){
	PNODE p = pHead->pNext;
	int len=0;
	while(p!=NULL){
		len++;
		p = p->pNext;
	}
	return len;
}

//����
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

