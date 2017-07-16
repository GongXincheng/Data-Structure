/*����Ĵ����ͱ���*/

# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node 
{
	int data;	//������
	struct Node * pNext;	//ָ����

}NODE, *PNODE;

//��������
PNODE creat_list(void);
void traverse_list(PNODE pHead);

int main(void)
{
	PNODE pHead = NULL;		//ͷָ��

	pHead = creat_list();	//����һ����ѭ������������������ͷ���ĵ�ַ����pHead
	traverse_list(pHead);	//��������
	free(pHead);
	return 0;
}

PNODE creat_list(void)
{
	int i;		//ѭ�����Ʊ���
	int len;	//��������ĳ���
	int val;	//��ʱ�������������

	PNODE pHead = (PNODE)malloc(sizeof(NODE));		//����ͷ���
	if(pHead == NULL)	//����ڴ����ʧ��
	{	
		printf("�ڴ����ʧ�ܣ�");
		exit(-1);
	}

	PNODE pTail = pHead;	//����һ��βָ�룬�տ�ʼָ��pHead
	pTail->pNext = NULL;	//���룬�տ�ʼ����Ϊ�գ�����ָ����Ϊ��

	printf("����������ĳ��ȣ�len = ");
	scanf("%d", &len);
	
	for(i=0; i<len; i++)
	{
		printf("�������%d���ڵ��ֵ��", i+1);
		scanf("%d",&val);
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));	//�����µĽڵ�
		if(pNew == NULL){
			printf("�ڴ����ʧ�ܣ�");
			exit(-1);
		}
		
		pNew->data = val;	//�����ݷ���������
		pNew->pNext = NULL;	//�Ѹýڵ�����������һ��������ָ����Ϊ��
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