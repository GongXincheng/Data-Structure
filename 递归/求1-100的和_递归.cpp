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
	printf("������һ������");
	scanf("%d", &val);
	printf("���Ϊ��%ld\n", sum(val));

	return 0;
}