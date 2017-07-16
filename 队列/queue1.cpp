# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Queue
{
	int * pBase;
	int front;
	int rear;
	
} QUEUE;

void init(QUEUE *);
bool en_queue(Queue *, int );
bool out_queue(Queue *, int *);
void traverse_queue(Queue *);
bool is_empty(Queue *);
bool is_full(Queue *);


int main(void){


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

void init(QUEUE *pQ){
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	if(pQ->pBase==NULL){
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	else{
		pQ->front = 0;
		pQ->rear = 0;
		return ;
	}
}

bool is_empty(Queue * pQ){
	if(pQ->front == pQ->rear)
		return true;
	else
		return false;
}
bool is_full(Queue * pQ){
	if( (pQ->rear+1)%6 == pQ->front)
		return true;
	else
		return false;
}

void traverse_queue(Queue * pQ){
	if( is_empty(pQ) ){
		printf("����Ϊ��!");
		return;
	}	
	else{
		int i = pQ->front;
		while(i != pQ->rear){
			printf("%d ", pQ->pBase[i]);
			i = (i+1)%6;
		}	
		printf("\n");
		return ;
	}
}

bool en_queue(Queue * pQ, int val){
	if(is_full(pQ)){
		printf("��������");
		return false;
	}
	else{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1)%6;
		return true;
	}
}
bool out_queue(Queue * pQ, int * pVal){
	if( is_empty(pQ) ){
		printf("����Ϊ��!");
		return false;
	}
	else{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front+1)%6;
		return true;
	}
}
