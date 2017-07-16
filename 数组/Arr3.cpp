# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct{
	int * pBase;
	int count;
	int length;
}Arr;

void init_arr(Arr *pArr, int length);
bool is_empty(Arr *pArr);
bool is_full(Arr *pArr);
bool append_arr(Arr *pArr, int value);
bool insert_arr(Arr *pArr, int value, int pos);
bool delete_arr(Arr *pArr, int pos, int * value);
void sort_arr(Arr *pArr);
void inversion_arr(Arr *pArr);
void show_arr(Arr *pArr);
int get(Arr *pArr, int pos);

int main(void){
	Arr arr; 
	int value;   //为了存放被删除的值
	
	init_arr(&arr, 6);	//初始化
	show_arr(&arr);

	append_arr(&arr, 5);	//追加元素
	append_arr(&arr, 23);
	append_arr(&arr, 7);
	append_arr(&arr, 33);
	append_arr(&arr, 2);
	show_arr(&arr);

	insert_arr(&arr, 88, 1);	//插入元素
	show_arr(&arr);

	delete_arr(&arr, 1, &value);	//删除元素
	printf("删除的值为：%d\n", value);
	show_arr(&arr);
	
	sort_arr(&arr);		//排序
	show_arr(&arr);

	int num = get(&arr,3);	//get
	printf("位置的值为：%d\n",num);

	inversion_arr(&arr);	//倒置
	show_arr(&arr);

	return 0;
}

void init_arr(Arr *pArr, int length){
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if(NULL == pArr->pBase){
		printf("动态内存分配失败\n");
		exit(-1);
	}
	else{
		pArr->count=0;
		pArr->length = length;
	}
	return;
}

bool is_empty(Arr *pArr){
	if(pArr->count==0)
		return true;
	else
		return false;
}
bool is_full(Arr *pArr){
	if(pArr->count==pArr->length)
		return true;
	else
		return false;
}

bool append_arr(Arr *pArr, int value){
	if(is_full(pArr)){
		printf("数组已满");
		return false;
	}
	
	pArr->pBase[pArr->count] = value;
	pArr->count++;
	return true;
}

bool insert_arr(Arr *pArr, int value, int pos){
	if(is_full(pArr)){
		printf("插入失败，数组已满");
		return false;
	}
	if(pos<1 || pos>(pArr->count+1)){
		printf("插入失败\n");
		return false;
	}
	for(int i=pArr->count; i>=pos; i--){
		pArr->pBase[i] = pArr->pBase[i-1];
	}
	pArr->pBase[pos-1] = value;
	pArr->count = pArr->count +1;
	return true;
}

bool delete_arr(Arr *pArr, int pos, int * value){
	if( is_empty(pArr)){
		printf("删除失败\n");
		return false;
	}
	if(pos<1 || pos>pArr->count){
		printf("删除失败\n");
		return false;
	}
	*value = pArr->pBase[pos-1];	//存储删除的值
	for(int i=pos; i<pArr->count; i++){
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->count = pArr->count - 1;
	return true;
}

void sort_arr(Arr *pArr){
	for(int i=0; i<pArr->count; i++){
		for(int j=i+1; j<pArr->count; j++){
			if(pArr->pBase[i]>pArr->pBase[j]){
				int t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
}
void inversion_arr(Arr *pArr){
	int i = 0, t;
	int j = pArr->count-1;
	while(i<j){
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;
	}
	return ;
}

void show_arr(Arr *pArr){
	if(is_empty(pArr)){
		printf("数组为空");
	}
	for(int i=0; i<pArr->count;i++){
		printf("%d ", pArr->pBase[i]);
	}
	printf("\n");
	return;
}

int get(Arr *pArr, int pos){
	return pArr->pBase[pos-1];
}