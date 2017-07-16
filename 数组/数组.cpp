/*
	2017年7月6日 15:24:41
	复习数组
*/

# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

//定义数据类型Arr
typedef struct Array
{
	int * pBase;
	int length;
	int count;

}Arr;

//函数声明
void init(Arr * pArr, int length);	//初始化
void show(Arr * pArr);				//输出数组元素
bool append(Arr * pArr, int val);	//追加元素
bool insert_arr(Arr * pArr, int pos, int val);		//插入元素
bool delete_arr(Arr * pArr, int pos, int * val);	//删除元素
bool is_empty(Arr * pArr);			//数组是否为空
bool is_full(Arr * pArr);			//数组是否满
void sort(Arr * pArr);				//排序(升序)
int get(Arr * pArr, int pos);		//获取指定位置的元素
void inversion(Arr * pArr);			//倒置

int main(void)
{
	int val,length;
	Arr arr;

	printf("请输入数组的长度：length = ");
	scanf("%d", &length);
	init(&arr, length);			//初始化数组

	
	append(&arr, 1);	
	append(&arr, 3);	
	append(&arr, 5);			//追加元素
	append(&arr, 2);
	append(&arr, 4);
	printf("数组为：");
	show(&arr);					//输出
	
	inversion(&arr);			//倒置
	printf("倒置：");
	show(&arr);	

	sort(&arr);					//排序
	printf("排序后：");
	show(&arr);	

	if( insert_arr(&arr, 3, 100) ){
		printf("\n插入成功\n");	//插入
		show(&arr);	
	}
	else
		printf("\n插入失败\n");
	

	printf("\n第3个位置的值为：%d\n", get(&arr, 3));	//获取指定位置的值

	if( delete_arr(&arr, 3, &val) ){		//删除
		printf("\n删除成功\n");
		printf("删除的第3位的值为：%d\n", val);
		printf("删除后：");
		show(&arr);	
	}
	else
		printf("\n删除失败\n");

	return 0;
}
//初始化
void init(Arr * pArr, int length){	
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if(pArr == NULL){
		printf("动态内存分配失败!\n");
		exit(-1);
	}
	else{
		pArr->count = 0;
		pArr->length = length;
	}
	return ;
}

//数组是否为空
bool is_empty(Arr * pArr){
	if(pArr->count==0)
		return true;
	else
		return false;
}
//数组是否满	
bool is_full(Arr * pArr){
	if(pArr->count == pArr->length)
		return true;
	else
		return false;
}

//输出数组元素
void show(Arr * pArr){
	int i;
	if( is_empty(pArr) ){
		printf("数组为空！\n");
		return ;
	}
	for(i=0; i<pArr->count; i++){
		printf("%d ", pArr->pBase[i]);
	}
	printf("\n");
	return;
}		
//追加元素	
bool append(Arr * pArr, int val){
	if( is_full(pArr) ){
		printf("数组已满，追加失败\n");
		return false;
	}
	pArr->pBase[pArr->count] = val;
	pArr->count++;
	return true;
}	
//插入元素
bool insert_arr(Arr * pArr, int pos, int val){
	if( is_full(pArr) ){
		printf("数组已满，插入失败\n");
		return false;
	}
	if(pos<1 || pos>pArr->count+1){
		printf("位置越界，插入失败\n");
		return false;
	}
	for(int i=pArr->count; i>=pos; i--){
		pArr->pBase[i] = pArr->pBase[i-1];
	}
	pArr->pBase[pos-1] = val;
	pArr->count++;
	return true;
}	
//删除元素
bool delete_arr(Arr * pArr, int pos, int * val){
	if( is_empty(pArr) ){
		printf("数组为空，删除失败\n");
		return false;
	}
	if(pos<1 || pos>pArr->count){
		printf("位置越界，删除失败\n");
		return false;
	}
	*val = pArr->pBase[pos-1];
	for(int i=pos; i<=pArr->count; i++){
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->count--;
	return true;
}
//排序(升序)
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
//获取指定位置的元素			
int get(Arr * pArr, int pos){
	return pArr->pBase[pos-1];
}

//倒置	
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

/*	运行结果：
-------------------------------------
请输入数组的长度：length = 100
数组为：1 3 5 2 4
倒置：4 2 5 3 1
排序后：1 2 3 4 5

插入成功
1 2 100 3 4 5

第3个位置的值为：100

删除成功
删除的第3位的值为：100
删除后：1 2 3 4 5
Press any key to continue
-------------------------------------
*/