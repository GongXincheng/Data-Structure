# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

typedef struct Queue
{
	int * pBase;
	int front;
	int rear;

}QUEUE;

//函数声明
void init(QUEUE *);	//初始化队列
bool en_queue(QUEUE *, int); //入队
void traverse_queue(QUEUE *);//遍历队列
bool full_queue(QUEUE *);	//队列满
bool empty_queue(QUEUE *);	//队列为空
bool out_queue(QUEUE *, int *);  //出队


int main(void){
	
	QUEUE Q;
	int val;

	init(&Q);	//队列初始化

	en_queue(&Q, 1);	//入队
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
//	en_queue(&Q, 6);  //队列已满
	traverse_queue(&Q);

	out_queue(&Q, &val);	//出队
	printf("出队的值：%d\n", val);
	traverse_queue(&Q);
		
	return 0;
}

//初始化队列
void init(QUEUE * pQ){
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	if(pQ->pBase == NULL){
		printf("内存分配失败！");
		exit(-1);
	}
	else{
		pQ->front = 0;
		pQ->rear = 0;
		return ;
	}
}
//入队
bool en_queue(QUEUE * pQ, int val){
	if( full_queue(pQ) ){
		printf("队列已满！");
		return false;
	}
	else{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1)%6;
		return true;
	}
}
//遍历队列
void traverse_queue(QUEUE * pQ){
	if( empty_queue(pQ) ){
		printf("队列为空！\n");
		return ;
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
//队列满
bool full_queue(QUEUE * pQ){
	if( (pQ->rear+1)%6 == pQ->front )
		return true;
	else
		return false;
}
//队列为空	
bool empty_queue(QUEUE * pQ){
	if(pQ->front == pQ->rear)
		return true;
	else
		return false;
}
//出队
bool out_queue(QUEUE * pQ, int * pVal){
	if( empty_queue(pQ) ){
		printf("队列为空！\n");
		return false;
	}
	else{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front+1)%6;
		return true;
	}
} 