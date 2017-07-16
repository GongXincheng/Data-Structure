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
bool insert_list(PNODE pHead, int, int );
bool delete_list(PNODE pHead, int, int* );

int main(void)
{
	PNODE pHead;
	int val;

	pHead = create_list();	//������������ͷ���ĵ�ַ���ظ�pHead

	traverse_list(pHead);	//��������

	if(is_empty(pHead))		//�ж������Ƿ�Ϊ��
		printf("null\n");
	else
		printf("not null\n");

	sort_lsit(pHead);		//����
	printf("�����");
	traverse_list(pHead);
	
	printf("������Ϊ��%d\n", length_list(pHead));	//���������

	insert_list(pHead, 3, 100 );			//����
	printf("����������");
	traverse_list(pHead);
	printf("�����������Ϊ��%d\n",length_list(pHead));

	delete_list(pHead, 3, &val);			//ɾ��
	printf("ɾ���������");
	traverse_list(pHead);
	printf("ɾ����ֵΪ: %d\n", val);
	printf("������Ϊ��%d\n",length_list(pHead));

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
//���������Ϊ2  posΪ4	posΪ3  posΪ-1
bool insert_list(PNODE pHead, int pos, int val){
	int i = 0;
	PNODE p = pHead;
					// i<3  i<2
	while(p!=NULL && i<pos-1){	//	t	t	 t			//	t	t	f				//	f
		p = p->pNext;			//	1	2	null		//	1	2	
		i++;					//	1	2	 3			//	1	2	
	}
	if(i>pos-1 || p==NULL)		// 3>3 || NULL==NULL	//	2>2 || 	not == NULL		// 0>-1   p!=null
		return false;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL){
		printf("��̬�ڴ����ʧ��!");
		exit(-1);
	}
	pNew->data = val;		//������
	pNew->pNext = p->pNext;	//ָ����
	p->pNext = pNew;		
	return true;
}
//���������Ϊ2  posΪ3	posΪ2  posΪ-1
bool delete_list(PNODE pHead, int pos, int * val){
	int i = 0;
	PNODE p = pHead;
							//i<2 i<1
	while(p->pNext!=NULL && i<pos-1){	//	t	t	f				// t  f					//f
		p = p->pNext;					//	1	2  null				// 1  
		i++;							//	1	2					// 1  
	}
	if(i>pos-1 || p->pNext == NULL)		// 2>2 || null==null		1>1 || not==null		// 0>-2  
		return false;
	
	PNODE q = p->pNext;		//����Ҫɾ���Ľڵ�
	*val = q->data;			//����ɾ���������������
	p->pNext = q->pNext;	//ǰһ���ڵ��ָ����ָ���һ���ڵ�
	free(q);				//�ͷŽڵ�
	q=NULL;
	
	return true;
}



