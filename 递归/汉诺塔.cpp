# include <stdio.h>

/*
A�����ĸ����ӵ�����
B����Ҫ����������
C����Ҫ�ŵ�������
���磺A�����ϵ����ӽ���B�ƶ���C
*/
void hannuota(int n, char A, char B, char C)
{
	/*
		�����1������
			ֱ�ӽ�A�����ϵ������ƶ���C��
		����
			�Ƚ�A�����ϵ�n-1�����ӽ���C�ƶ���B������
			ֱ�ӽ�A�����ϵ����Ӵ�A�ƶ���C
			���B�����ϵ�n-1�����ӽ���A�ƶ���C������
	*/
	if(n==1){
		printf("�����Ϊ%d�����Ӵ�%c�����ƶ���%c����\n", n, A, C);
	}
	else
	{
		hannuota(n-1, A, C, B);
		printf("�����Ϊ%d�����Ӵ�%c�����ƶ���%c����\n", n, A, C);
		hannuota(n-1, B, A, C);
	}
}

int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("���������ӵĸ�����");
	scanf("%d", &n);
	hannuota(n, 'A','B','C');

	return 0;
}