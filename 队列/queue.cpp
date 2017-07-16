//ѭ������

# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Queue	//������еĽṹ��
{
	int * pBase;
	int front;
	int rear;

}QUEUE;

//��������
void init(QUEUE *);	//��ʼ������
bool en_queue(QUEUE *, int); //���
void traverse_queue(QUEUE *);//��������
bool full_queue(QUEUE *);	//������
bool empty_queue(QUEUE *);	//����Ϊ��
bool out_queue(QUEUE *, int *);  //����

int main(void)
{
	QUEUE Q;
	int val;

	init(&Q);	//���г�ʼ��

	en_queue(&Q, 1);	//���
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
//	en_queue(&Q, 6);  //��������
	traverse_queue(&Q);

	out_queue(&Q, &val);	//����
	printf("���ӵ�ֵ��%d\n", val);
	traverse_queue(&Q);

	return 0;
}

//���г�ʼ��
void init(QUEUE * pQ){
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	if(pQ->pBase==NULL){
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	else{
		pQ->front = 0;
		pQ->rear = 0;
		return;
	}
}

//�����Ƿ�Ϊ��
bool empty_queue(QUEUE * pQ){
	if(pQ->front == pQ->rear)
		return true;
	else
		return false;
}
//�����Ƿ�����
bool full_queue(QUEUE * pQ){
	if( (pQ->rear+1) % 6 == (pQ->front) )	//ע��
		return true;
	else
		return false;
}

//��Ӳ���
bool en_queue(QUEUE * pQ, int val){
	if( full_queue(pQ) ){
		printf("����������");
		return false;
	}
	else{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1) % 6;	//ע��
		return true;
	}
}

//����
bool out_queue(QUEUE * pQ, int * pVal){
	if( empty_queue(pQ) ){
		printf("����Ϊ�գ�");
		return false;
	}
	else{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front+1)%6;

		return true;
	}
}

//���б���
void traverse_queue(QUEUE * pQ){
	int i = pQ->front;
	while(i != pQ->rear){
		printf("%d ", pQ->pBase[i]);
		i = (i+1)%6;					//ע��
	}
	printf("\n");
	return;
}