# include <stdio.h>

long sum(int n)
{	
	if( n == 1 )
		return 1;
	else
		return n+sum(n-1);

}

int main(void)
{
	int val;
	printf("请输入一个数：");
	scanf("%d", &val);
	printf("结果为：%ld\n", sum(val));

	return 0;
}