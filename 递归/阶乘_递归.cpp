# include <stdio.h>

long f(long n)
{
	if( n ==1 )
		return 1;
	else
		return f(n-1)*n;
}

int main(void)
{
	int val;
	printf("请输入一个数：");
	scanf("%d", &val);
	printf("%d的阶乘为：%ld\n", val,f(val));

	return 0;
}