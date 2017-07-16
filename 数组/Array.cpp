# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct
{
	int * pBase;
	int cnt;
	int len;
}Arr;

//��������
void init_arr(Arr * pArr, int length);		//��ʼ��
bool append_arr(Arr * pArr, int val);		//׷��
bool insert_arr(Arr * pArr, int pos, int val);		//���� pos��ֵ��1��ʼ
bool delete_arr(Arr * pArr,int pos, int * val);		//ɾ��
bool is_empty(Arr * pArr);		//�Ƿ�Ϊ��
bool is_full(Arr * pArr);			//�Ƿ�����
void sort_arr(Arr * pArr);		//����
void show_arr(Arr * pArr);		//��ʾ
void inversion(Arr * pArr);		//����
int get(Arr * pArr, int pos);

int main(void)
{
	int val;

	Arr arr;	//����ṹ�����arr
	init_arr(&arr, 6);	//��ʼ��������,��������������Ԫ�ظ���
	
	//׷����ֵ
	append_arr(&arr, 1);	
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, 5);
	show_arr(&arr);
	printf("\n");

	//����
	if(insert_arr(&arr,1,99)){	
		printf("����ɹ���\n");
	}else{
		printf("����ʧ�ܣ�\n");
	}
	show_arr(&arr);
	printf("\n");

	//ɾ��
	if(	delete_arr(&arr,3, &val)){
		printf("ɾ���ɹ���\n");
		printf("ɾ��%dλ�õ�ֵΪ��%d \n",3,val);
	}else{
		printf("ɾ��ʧ�ܣ�\n");
	}
	printf("ɾ����");
		show_arr(&arr);
	printf("\n");

	//����
	printf("����ǰ��");
	show_arr(&arr);
	inversion(&arr);
	printf("\n���ú�");
	show_arr(&arr);

	//����
	sort_arr(&arr);
	printf("\n�����");
	show_arr(&arr);
	printf("\n");
	
	return 0;
}

//��ʼ��˳���
void init_arr(Arr * pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if(pArr->pBase == NULL){
		printf("�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	else{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

//˳����Ƿ���  �Ƿ��
bool is_empty(Arr * pArr){
	if(pArr->cnt==0)
		return true;
	else
		return false;
}
bool is_full(Arr * pArr){
	if(pArr->cnt == pArr->len)
		return true;
	else
		return false;
}
//׷��
bool append_arr(Arr * pArr, int val){
	if( is_full(pArr) ){
		printf("����������׷��ʧ��");
		return false;
	}
	pArr->pBase[pArr->cnt] = val;
	pArr->cnt++;
	return true;
}
//����
void sort_arr(Arr * pArr){
	for(int i=0; i<pArr->cnt-1; i++){
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
//��ʾ	
void show_arr(Arr * pArr)
{
	for(int i=0; i<pArr->cnt; i++){
		printf("%d ", pArr->pBase[i]);
	}
	return;
}
//����	
void inversion(Arr * pArr){
	int i = 0;
	int j = pArr->cnt-1;
	int t;
	
	while(i<j){
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;
	}

	return;
}	
//��ȡ	
int get(Arr * pArr, int pos){
	if(pos<1 || pos>pArr->cnt){
		printf("λ��Խ��");
		return -1;
	}
	else{
		return pArr->pBase[pos-1];
	}
}
//���� pos��ֵ��1��ʼ
bool insert_arr(Arr * pArr, int pos, int val){
	if(is_full(pArr)){
		printf("��������");
		return false;
	}
	if(pos<1 || pos>(pArr->cnt+1)){
		printf("λ��Խ��");
		return false;
	}

	for(int i=pArr->cnt; i>pos; i--){
		pArr->pBase[i] = pArr->pBase[i-1];
	}
	pArr->pBase[pos-1] = val;
	pArr->cnt++;
	return true;
}
//ɾ��		
bool delete_arr(Arr * pArr,int pos, int * val){
	if(is_empty(pArr)){
		printf("����Ϊ��");
		return false;
	}
	if(pos<1 || pos>pArr->cnt){
		printf("λ��Խ��");
		return false;
	}
	*val = pArr->pBase[pos-1];
	for(int i=pos; i<pArr->cnt; i++){
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}	
