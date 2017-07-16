# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct{
	int * pBase;	//�洢���������һ��Ԫ�صĵ�ַ
	int cnt;	//��ǰ������ЧԪ�صĸ���
	int len;	//�����������ɵ����Ԫ�صĸ���
}Arr;

void init_arr(Arr * pArr, int length);		//��ʼ��
bool append_arr(Arr * pArr, int val);		//׷��
bool insert_arr(Arr * pArr, int pos, int val);		//���� pos��ֵ��1��ʼ
bool delete_arr(Arr * pArr,int pos, int * val);		//ɾ��
bool is_empty(Arr * pArr);		//�Ƿ�Ϊ��
bool is_full(Arr * pArr);			//�Ƿ�����
void sort_arr(Arr * pArr);		//����
void show_arr(Arr * pArr);		//��ʾ
void inversion(Arr * pArr);		//����
int get();

int main(void){
	
	int val;

	Arr arr;	//����ṹ�����arr
	init_arr(&arr, 6);	//��ʼ��������,��������������Ԫ�ظ���
	show_arr(&arr);		//��ʾ����
	
	//׷����ֵ
	append_arr(&arr, 1);	
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, 5);
	show_arr(&arr);

	//����
	if(insert_arr(&arr,1,99)){	
		printf("����ɹ���\n");
	}else{
		printf("����ʧ�ܣ�\n");
	}
	show_arr(&arr);

	//ɾ��
	if(	delete_arr(&arr,3, &val)){
		printf("ɾ���ɹ���\n");
		printf("ɾ����ֵΪ��%d \n", val);
	}else{
		printf("ɾ��ʧ�ܣ�\n");
	}

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
	

	return 0;
}

bool is_empty(Arr * pArr){
	if(pArr->cnt==0)
		return true;
	else
		return false;
	
}

bool is_full(Arr * pArr){
	if(pArr->cnt==pArr->len)
		return true;
	else
		return false;
}

void show_arr(Arr * pArr){
	if(is_empty(pArr)){		//�жϸ������Ƿ�Ϊ��
		printf("����Ϊ�գ�\n");
	}else{
		for(int i=0;i<pArr->cnt;i++){	//forѭ�����
			printf("%d  ",pArr->pBase[i]);
		}
		printf("\n");
	}
}

void init_arr(Arr * pArr, int length){
	pArr->pBase = (int *)malloc(sizeof(int) * length);	//��̬����������ڴ�ռ�

	if(pArr->pBase==NULL){		//����ڴ��Ѿ���������ʧ��
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	else{
		pArr->len = length;		//Ϊ������Ա��ֵ
		pArr->cnt = 0;
	}
	return;
}

bool append_arr(Arr * pArr, int val){
	if(is_full(pArr)){		//�ж������Ƿ����� ���������false
		printf("����������");
		return false;
	}
	else{	//���鲻��ʱ
		 pArr->pBase[pArr->cnt] = val;
		 (pArr->cnt)++;
		 return true;
	}
}

bool insert_arr(Arr * pArr, int pos, int val){
	
	if(is_full(pArr))
		return false;

	if(pos<1 || pos>pArr->cnt+1)
		return false;
	
	for(int i=pArr->cnt; i>=pos-1; i--){
		pArr->pBase[i] = pArr->pBase[i-1];
	}

	pArr->pBase[pos-1] = val;
	pArr->cnt++;
	return true;
}

bool delete_arr(Arr * pArr,int pos, int * val){
	int i;
	
	if(is_empty(pArr)){
		return false;
	}

	if(pos<1 || pos>pArr->cnt){
		return false;
	}

	*val = pArr->pBase[pos-1];
	
	for(i=pos;i<=pArr->cnt-1;i++){
		pArr->pBase[i-1] = pArr->pBase[i];
	}

	pArr->cnt--;

	return true;;
}

void inversion(Arr * pArr){
	int i,j,t;
	i = 0;
	j = pArr->cnt - 1;

	while(i<j){
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;
	}

	return;
}

void sort_arr(Arr * pArr){
	
	int i, j, t;
	
	for(i=0; i<pArr->cnt; i++){
		for(j=i+1; j<pArr->cnt; j++){
			if(pArr->pBase[i] > pArr->pBase[j]){
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}

	return;
}