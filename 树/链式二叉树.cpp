# include <stdio.h>
# include <malloc.h>

typedef struct BTNode
{
	char data;				//数据域
	struct BTNode * pLchild;	//左孩子的指针
	struct BTNode * pRchild;	//右孩子的指针

}BTNODE;

//函数声明
BTNODE * CreateBTree(void);
void PreTraverseBTree(BTNODE *);	//先序遍历
void InTraverseBTree(BTNODE *);	//中序遍历
void PostTraverseBTree(BTNODE *);	//后序遍历

int main(void)
{
	BTNODE * pT = CreateBTree();
	PreTraverseBTree(pT);	//先序遍历
//	InTraverseBTree(pT);	//中序遍历
//	PostTraverseBTree(pT);	//后序遍历

	return 0;
}

BTNODE * CreateBTree(void)
{
	BTNODE * pA = (BTNODE *)malloc(sizeof(BTNODE));
	BTNODE * pB = (BTNODE *)malloc(sizeof(BTNODE));
	BTNODE * pC = (BTNODE *)malloc(sizeof(BTNODE));
	BTNODE * pD = (BTNODE *)malloc(sizeof(BTNODE));
	BTNODE * pE = (BTNODE *)malloc(sizeof(BTNODE));

	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;
	
	return pA;
}
//先序遍历
void PreTraverseBTree(BTNODE * pT){
	if(pT != NULL){
		
		printf("%c\n",pT->data);
		
		if(pT->pLchild != NULL){
			PreTraverseBTree(pT->pLchild);
		}

		if(pT->pRchild != NULL){
			PreTraverseBTree(pT->pRchild);
		}
	}
}
//中序遍历	
void InTraverseBTree(BTNODE * pT){
	if(pT != NULL){
		
		if(pT->pLchild != NULL){
			InTraverseBTree(pT->pLchild);
		}

		printf("%c\n",pT->data);

		if(pT->pRchild != NULL){
			InTraverseBTree(pT->pRchild);
		}
	}
}
//后序遍历
void PostTraverseBTree(BTNODE * pT){
	if(pT != NULL){
		
		if(pT->pLchild != NULL){
			PostTraverseBTree(pT->pLchild);
		}

		if(pT->pRchild != NULL){
			PostTraverseBTree(pT->pRchild);
		}

		printf("%c\n",pT->data);
	}
}