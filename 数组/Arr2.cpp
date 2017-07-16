# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>


typedef struct
{
	int * pBase;//存储的是数组第一个元素的个数
	int len;	//数组所能容纳的最大元素的个数
	int cnt;	//当前数组有效元素的个数
}Arr;

void init_arr(Arr * pArr, int length);	//初始化
bool append_arr(Arr * pArr, int val);	//追加
bool insert_arr(Arr * pArr, int pos, int val);	//插入 pose的值从1开始
bool delete_arr(Arr * pArr, int pos, int * pVal);	//删除
int get(Arr * pArr, int pos);			//获取
bool is_empty(Arr * pArr);	//是否为空
bool is_full(Arr * pArr);	//是否满
void sort_arr(Arr * pArr);	//排序
void show_arr(Arr * pArr);	//显示数组
void inversion_arr(Arr * pArr);//倒置

int main(void)
{
	Arr arr; 
	int val;   //为了存放被删除的值
	
	init_arr(&arr, 6);	//初始化
	show_arr(&arr);

	append_arr(&arr, 5);	//追加元素
	append_arr(&arr, 23);
	append_arr(&arr, 7);
	append_arr(&arr, 33);
	append_arr(&arr, 2);
	show_arr(&arr);

	insert_arr(&arr, 1, 88);	//插入元素
	show_arr(&arr);

	delete_arr(&arr, 1, &val);	//删除元素
	printf("删除的值为：%d\n", val);
	show_arr(&arr);
	
	sort_arr(&arr);		//排序
	show_arr(&arr);

	int num = get(&arr,3);	//get
	printf("位置的值为：%d\n",num);

	inversion_arr(&arr);	//倒置
	show_arr(&arr);

	return 0;
}

void init_arr(Arr * pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);	//为数组分配内存空间(动态内存分配)
	if(NULL == pArr->pBase)		//如果分配不成功(如内存已满)
	{
		printf("动态内存分配失败\n");
		exit(-1);	//终止整个程序(需要加 stdlib.h 的头文件)
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
		printf("数组为空\n");
	}
	else{
		for(int i=0; i<pArr->cnt; i++){ 
			printf("%d ", pArr->pBase[i]); //注意  
		}
		printf("\n");
	}
}

bool append_arr(Arr * pArr, int val){
	if(is_full(pArr)){
		printf("数组已满！\n");
		return false;
	}

	pArr->pBase[pArr->cnt] = val;
	pArr->cnt = pArr->cnt + 1;
	return true;
}

bool insert_arr(Arr * pArr, int pos, int val){

	if(is_full(pArr)){
		printf("数组已满！插入失败\n");
		return false;
	}

	if(pos<1 || pos>(pArr->cnt+1)){
		printf("插入失败\n");
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
		printf("删除失败\n");
		return false;
	}
	if(pos<1 || pos>pArr->cnt){
		printf("删除失败\n");
		return false;
	}
	
	*pVal = pArr->pBase[pos-1];	//存储删除的值
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