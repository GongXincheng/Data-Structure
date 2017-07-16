/*
	2017年7月6日 13:30:37
	快速排序
	郝斌数据结构视频 第76讲
*/

# include <stdio.h>

void QuickSort(int * a, int low, int high);
int FindPos(int * a, int low, int high);

int main(void)
{
	int a[6] = {2, 1, 0, 5, 4, 3};
	
	QuickSort(a, 0, 5);	//第二个参数表示第一个元素的下标，第三个表示左后一个元素的下标
	
	for(int i=0; i<6; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

void QuickSort(int * a, int low, int high)	//低 高
{
	int pos; //位置

	if(low < high){
		pos = FindPos(a, low, high);
		QuickSort(a, low, pos-1);
		QuickSort(a, pos+1, high);
	}
}

int FindPos(int * a, int low, int high)
{	
	int val = a[low];

	while(low < high)
	{
		while(low<high && a[high]>=val)
			--high;
		a[low] = a[high];

		while(low<high && a[high]<=val)
			++low;
		a[high] = a[low];
	}//终止while循环之后 low和high的值相等

	a[low] = val;
	return low; //high都行
}