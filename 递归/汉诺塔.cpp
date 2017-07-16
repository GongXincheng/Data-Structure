# include <stdio.h>

/*
A代表哪个柱子的盘子
B代表要借助的柱子
C代表要放到的柱子
例如：A柱子上的盘子借助B移动到C
*/
void hannuota(int n, char A, char B, char C)
{
	/*
		如果是1个盘子
			直接将A柱子上的盘子移动到C上
		否则
			先将A柱子上的n-1个盘子借助C移动到B柱子上
			直接将A柱子上的盘子从A移动到C
			最后将B柱子上的n-1个盘子借助A移动到C柱子上
	*/
	if(n==1){
		printf("将编号为%d的盘子从%c柱子移动到%c柱子\n", n, A, C);
	}
	else
	{
		hannuota(n-1, A, C, B);
		printf("将编号为%d的盘子从%c柱子移动到%c柱子\n", n, A, C);
		hannuota(n-1, B, A, C);
	}
}

int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("请输入盘子的个数：");
	scanf("%d", &n);
	hannuota(n, 'A','B','C');

	return 0;
}