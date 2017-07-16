/*
	2017��7��6�� 15:24:41
	��ϰ����
*/

# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

//������������Arr
typedef struct Array
{
	int * pBase;
	int length;
	int count;

}Arr;

//��������
void init(Arr * pArr, int length);	//��ʼ��
void show(Arr * pArr);				//�������Ԫ��
bool append(Arr * pArr, int val);	//׷��Ԫ��
bool insert_arr(Arr * pArr, int pos, int val);		//����Ԫ��
bool delete_arr(Arr * pArr, int pos, int * val);	//ɾ��Ԫ��
bool is_empty(Arr * pArr);			//�����Ƿ�Ϊ��
bool is_full(Arr * pArr);			//�����Ƿ���
void sort(Arr * pArr);				//����(����)
int get(Arr * pArr, int pos);		//��ȡָ��λ�õ�Ԫ��
void inversion(Arr * pArr);			//����

int main(void)
{
	int val,length;
	Arr arr;

	printf("����������ĳ��ȣ�length = ");
	scanf("%d", &length);
	init(&arr, length);			//��ʼ������

	
	append(&arr, 1);	
	append(&arr, 3);	
	append(&arr, 5);			//׷��Ԫ��
	append(&arr, 2);
	append(&arr, 4);
	printf("����Ϊ��");
	show(&arr);					//���
	
	inversion(&arr);			//����
	printf("���ã�");
	show(&arr);	

	sort(&arr);					//����
	printf("�����");
	show(&arr);	

	if( insert_arr(&arr, 3, 100) ){
		printf("\n����ɹ�\n");	//����
		show(&arr);	
	}
	else
		printf("\n����ʧ��\n");
	

	printf("\n��3��λ�õ�ֵΪ��%d\n", get(&arr, 3));	//��ȡָ��λ�õ�ֵ

	if( delete_arr(&arr, 3, &val) ){		//ɾ��
		printf("\nɾ���ɹ�\n");
		printf("ɾ���ĵ�3λ��ֵΪ��%d\n", val);
		printf("ɾ����");
		show(&arr);	
	}
	else
		printf("\nɾ��ʧ��\n");

	return 0;
}
//��ʼ��
void init(Arr * pArr, int length){	
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if(pArr == NULL){
		printf("��̬�ڴ����ʧ��!\n");
		exit(-1);
	}
	else{
		pArr->count = 0;
		pArr->length = length;
	}
	return ;
}

//�����Ƿ�Ϊ��
bool is_empty(Arr * pArr){
	if(pArr->count==0)
		return true;
	else
		return false;
}
//�����Ƿ���	
bool is_full(Arr * pArr){
	if(pArr->count == pArr->length)
		return true;
	else
		return false;
}

//�������Ԫ��
void show(Arr * pArr){
	int i;
	if( is_empty(pArr) ){
		printf("����Ϊ�գ�\n");
		return ;
	}
	for(i=0; i<pArr->count; i++){
		printf("%d ", pArr->pBase[i]);
	}
	printf("\n");
	return;
}		
//׷��Ԫ��	
bool append(Arr * pArr, int val){
	if( is_full(pArr) ){
		printf("����������׷��ʧ��\n");
		return false;
	}
	pArr->pBase[pArr->count] = val;
	pArr->count++;
	return true;
}	
//����Ԫ��
bool insert_arr(Arr * pArr, int pos, int val){
	if( is_full(pArr) ){
		printf("��������������ʧ��\n");
		return false;
	}
	if(pos<1 || pos>pArr->count+1){
		printf("λ��Խ�磬����ʧ��\n");
		return false;
	}
	for(int i=pArr->count; i>=pos; i--){
		pArr->pBase[i] = pArr->pBase[i-1];
	}
	pArr->pBase[pos-1] = val;
	pArr->count++;
	return true;
}	
//ɾ��Ԫ��
bool delete_arr(Arr * pArr, int pos, int * val){
	if( is_empty(pArr) ){
		printf("����Ϊ�գ�ɾ��ʧ��\n");
		return false;
	}
	if(pos<1 || pos>pArr->count){
		printf("λ��Խ�磬ɾ��ʧ��\n");
		return false;
	}
	*val = pArr->pBase[pos-1];
	for(int i=pos; i<=pArr->count; i++){
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->count--;
	return true;
}
//����(����)
void sort(Arr * pArr){
	int i,j,t;
	for(i=0; i<pArr->count-1; i++){
		for(j=i+1; j<pArr->count; j++){
			if(pArr->pBase[i]>pArr->pBase[j]){
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
	return ;
}
//��ȡָ��λ�õ�Ԫ��			
int get(Arr * pArr, int pos){
	return pArr->pBase[pos-1];
}

//����	
void inversion(Arr * pArr){
	int i = 0;
	int j = pArr->count-1;
	int t ;

	while(i<j){
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;
	}
	return ;
}		

/*	���н����
-------------------------------------
����������ĳ��ȣ�length = 100
����Ϊ��1 3 5 2 4
���ã�4 2 5 3 1
�����1 2 3 4 5

����ɹ�
1 2 100 3 4 5

��3��λ�õ�ֵΪ��100

ɾ���ɹ�
ɾ���ĵ�3λ��ֵΪ��100
ɾ����1 2 3 4 5
Press any key to continue
-------------------------------------
*/