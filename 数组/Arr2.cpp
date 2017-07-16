# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>


typedef struct
{
	int * pBase;//�洢���������һ��Ԫ�صĸ���
	int len;	//�����������ɵ����Ԫ�صĸ���
	int cnt;	//��ǰ������ЧԪ�صĸ���
}Arr;

void init_arr(Arr * pArr, int length);	//��ʼ��
bool append_arr(Arr * pArr, int val);	//׷��
bool insert_arr(Arr * pArr, int pos, int val);	//���� pose��ֵ��1��ʼ
bool delete_arr(Arr * pArr, int pos, int * pVal);	//ɾ��
int get(Arr * pArr, int pos);			//��ȡ
bool is_empty(Arr * pArr);	//�Ƿ�Ϊ��
bool is_full(Arr * pArr);	//�Ƿ���
void sort_arr(Arr * pArr);	//����
void show_arr(Arr * pArr);	//��ʾ����
void inversion_arr(Arr * pArr);//����

int main(void)
{
	Arr arr; 
	int val;   //Ϊ�˴�ű�ɾ����ֵ
	
	init_arr(&arr, 6);	//��ʼ��
	show_arr(&arr);

	append_arr(&arr, 5);	//׷��Ԫ��
	append_arr(&arr, 23);
	append_arr(&arr, 7);
	append_arr(&arr, 33);
	append_arr(&arr, 2);
	show_arr(&arr);

	insert_arr(&arr, 1, 88);	//����Ԫ��
	show_arr(&arr);

	delete_arr(&arr, 1, &val);	//ɾ��Ԫ��
	printf("ɾ����ֵΪ��%d\n", val);
	show_arr(&arr);
	
	sort_arr(&arr);		//����
	show_arr(&arr);

	int num = get(&arr,3);	//get
	printf("λ�õ�ֵΪ��%d\n",num);

	inversion_arr(&arr);	//����
	show_arr(&arr);

	return 0;
}

void init_arr(Arr * pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);	//Ϊ��������ڴ�ռ�(��̬�ڴ����)
	if(NULL == pArr->pBase)		//������䲻�ɹ�(���ڴ�����)
	{
		printf("��̬�ڴ����ʧ��\n");
		exit(-1);	//��ֹ��������(��Ҫ�� stdlib.h ��ͷ�ļ�)
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return; 
}

bool is_empty(Arr * pArr){
	if(pArr->cnt==0)
		return true;
	else
		return false;
}

bool is_full(Arr * pArr){
	if(pArr->len == pArr->cnt)
		return true;
	else
		return false;	
}

void show_arr(Arr * pArr)
{
	if(is_empty(pArr)){
		printf("����Ϊ��\n");
	}
	else{
		for(int i=0; i<pArr->cnt; i++){ 
			printf("%d ", pArr->pBase[i]); //ע��  
		}
		printf("\n");
	}
}

bool append_arr(Arr * pArr, int val){
	if(is_full(pArr)){
		printf("����������\n");
		return false;
	}

	pArr->pBase[pArr->cnt] = val;
	pArr->cnt = pArr->cnt + 1;
	return true;
}

bool insert_arr(Arr * pArr, int pos, int val){

	if(is_full(pArr)){
		printf("��������������ʧ��\n");
		return false;
	}

	if(pos<1 || pos>(pArr->cnt+1)){
		printf("����ʧ��\n");
		return false;
	}

	for(int i=pArr->cnt; i>=pos; i--){
		pArr->pBase[i] = pArr->pBase[i-1];
	}
	/*
	for(int i=pArr->cnt-1; i>=pos-1; i--){
		pArr->pBase[i+1] = pArr->pBase[i];
	}	
	*/
	pArr->pBase[pos-1] = val;
	pArr->cnt = pArr->cnt +1;
	return true;
}

bool delete_arr(Arr * pArr, int pos, int * pVal){
	if( is_empty(pArr)){
		printf("ɾ��ʧ��\n");
		return false;
	}
	if(pos<1 || pos>pArr->cnt){
		printf("ɾ��ʧ��\n");
		return false;
	}
	
	*pVal = pArr->pBase[pos-1];	//�洢ɾ����ֵ
	for(int i=pos-1; i<pArr->cnt-1; i++){
		pArr->pBase[i] = pArr->pBase[i+1];
	}
	/*
	for(int i=pos; i<pArr->cnt; i++){
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	*/
	
	pArr->cnt = pArr->cnt - 1;
	return true;
}

void sort_arr(Arr * pArr){
	for(int i=0; i<pArr->cnt; i++){
		for(int j=i+1; j<pArr->cnt; j++){
			if(pArr->pBase[i]>pArr->pBase[j]){
				int t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
	return;
}

int get(Arr * pArr, int pos){
	return pArr->pBase[pos-1];
}

void inversion_arr(Arr * pArr){
	int i=0,j=pArr->cnt-1,t;
	while(j>i){
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;
	}
	return;
}