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
	printf("������һ������");
	scanf("%d", &val);
	printf("%d�Ľ׳�Ϊ��%ld\n", val,f(val));

	return 0;
}