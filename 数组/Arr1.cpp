# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct{
	int * pBase;	//存储的是数组第一个元素的地址
	int cnt;	//当前数组有效元素的个数
	int len;	//数组所能容纳的最大元素的个数
}Arr;

void init_arr(Arr * pArr, int length);		//初始化
bool append_arr(Arr * pArr, int val);		//追加
bool insert_arr(Arr * pArr, int pos, int val);		//插入 pos的值从1开始
bool delete_arr(Arr * pArr,int pos, int * val);		//删除
bool is_empty(Arr * pArr);		//是否为空
bool is_full(Arr * pArr);			//是否已满
void sort_arr(Arr * pArr);		//排序
void show_arr(Arr * pArr);		//显示
void inversion(Arr * pArr);		//倒置
int get();

int main(void){
	
	int val;

	Arr arr;	//定义结构体变量arr
	init_arr(&arr, 6);	//初始化该数组,并设置数组的最大元素个数
	show_arr(&arr);		//显示数组
	
	//追加数值
	append_arr(&arr, 1);	
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, 5);
	show_arr(&arr);

	//插入
	if(insert_arr(&arr,1,99)){	
		printf("插入成功！\n");
	}else{
		printf("插入失败！\n");
	}
	show_arr(&arr);

	//删除
	if(	delete_arr(&arr,3, &val)){
		printf("删除成功！\n");
		printf("删除的值为：%d \n", val);
	}else{
		printf("删除失败！\n");
	}

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
	if(is_empty(pArr)){		//判断该数组是否为空
		printf("数组为空！\n");
	}else{
		for(int i=0;i<pArr->cnt;i++){	//for循环输出
			printf("%d  ",pArr->pBase[i]);
		}
		printf("\n");
	}
}

void init_arr(Arr * pArr, int length){
	pArr->pBase = (int *)malloc(sizeof(int) * length);	//动态分配数组的内存空间

	if(pArr->pBase==NULL){		//如果内存已经满，分配失败
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	else{
		pArr->len = length;		//为其他成员赋值
		pArr->cnt = 0;
	}
	return;
}

bool append_arr(Arr * pArr, int val){
	if(is_full(pArr)){		//判断数组是否已满 如果满返回false
		printf("数组已满！");
		return false;
	}
	else{	//数组不满时
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