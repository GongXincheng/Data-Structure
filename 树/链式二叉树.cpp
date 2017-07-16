# include <stdio.h>
# include <malloc.h>

typedef struct BTNode
{
	char data;				//������
	struct BTNode * pLchild;	//���ӵ�ָ��
	struct BTNode * pRchild;	//�Һ��ӵ�ָ��

}BTNODE;

//��������
BTNODE * CreateBTree(void);
void PreTraverseBTree(BTNODE *);	//�������
void InTraverseBTree(BTNODE *);	//�������
void PostTraverseBTree(BTNODE *);	//�������

int main(void)
{
	BTNODE * pT = CreateBTree();
	PreTraverseBTree(pT);	//�������
//	InTraverseBTree(pT);	//�������
//	PostTraverseBTree(pT);	//�������

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
//�������
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
//�������	
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
//�������
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