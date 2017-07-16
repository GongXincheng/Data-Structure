# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct
{
	int * pBase;
	int cnt;
	int len;
}Arr;

//函数声明
void init_arr(Arr * pArr, int length);		//初始化
bool append_arr(Arr * pArr, int val);		//追加
bool insert_arr(Arr * pArr, int pos, int val);		//插入 pos的值从1开始
bool delete_arr(Arr * pArr,int pos, int * val);		//删除
bool is_empty(Arr * pArr);		//是否为空
bool is_full(Arr * pArr);			//是否已满
void sort_arr(Arr * pArr);		//排序
void show_arr(Arr * pArr);		//显示
void inversion(Arr * pArr);		//倒置
int get(Arr * pArr, int pos);

int main(void)
{
	int val;

	Arr arr;	//定义结构体变量arr
	init_arr(&arr, 6);	//初始化该数组,并设置数组的最大元素个数
	
	//追加数值
	append_arr(&arr, 1);	
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, 5);
	show_arr(&arr);
	printf("\n");

	//插入
	if(insert_arr(&arr,1,99)){	
		printf("插入成功！\n");
	}else{
		printf("插入失败！\n");
	}
	show_arr(&arr);
	printf("\n");

	//删除
	if(	delete_arr(&arr,3, &val)){
		printf("删除成功！\n");
		printf("删除%d位置的值为：%d \n",3,val);
	}else{
		printf("删除失败！\n");
	}
	printf("删除后：");
		show_arr(&arr);
	printf("\n");

	//倒置
	printf("倒置前：");
	show_arr(&arr);
	inversion(&arr);
	printf("\n倒置后：");
	show_arr(&arr);

	//排序
	sort_arr(&arr);
	printf("\n排序后：");
	show_arr(&arr);
	printf("\n");
	
	return 0;
}

//初始化顺序表
void init_arr(Arr * pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if(pArr->pBase == NULL){
		printf("内存分配失败！");
		exit(-1);
	}
	else{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

//顺序表是否满  是否空
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
//追加
bool append_arr(Arr * pArr, int val){
	if( is_full(pArr) ){
		printf("数组已满，追加失败");
		return false;
	}
	pArr->pBase[pArr->cnt] = val;
	pArr->cnt++;
	return true;
}
//排序
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
//显示	
void show_arr(Arr * pArr)
{
	for(int i=0; i<pArr->cnt; i++){
		printf("%d ", pArr->pBase[i]);
	}
	return;
}
//倒置	
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
//获取	
int get(Arr * pArr, int pos){
	if(pos<1 || pos>pArr->cnt){
		printf("位置越界");
		return -1;
	}
	else{
		return pArr->pBase[pos-1];
	}
}
//插入 pos的值从1开始
bool insert_arr(Arr * pArr, int pos, int val){
	if(is_full(pArr)){
		printf("数组已满");
		return false;
	}
	if(pos<1 || pos>(pArr->cnt+1)){
		printf("位置越界");
		return false;
	}

	for(int i=pArr->cnt; i>pos; i--){
		pArr->pBase[i] = pArr->pBase[i-1];
	}
	pArr->pBase[pos-1] = val;
	pArr->cnt++;
	return true;
}
//删除		
bool delete_arr(Arr * pArr,int pos, int * val){
	if(is_empty(pArr)){
		printf("数组为空");
		return false;
	}
	if(pos<1 || pos>pArr->cnt){
		printf("位置越界");
		return false;
	}
	*val = pArr->pBase[pos-1];
	for(int i=pos; i<pArr->cnt; i++){
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}	
