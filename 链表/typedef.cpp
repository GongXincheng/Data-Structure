# include <stdio.h>

typedef struct student
{
	char name[20];
	int age;
	char sex[10];
}STU, * PSTU;

int main(void)
{
	STU stu;			//�ȼ���  struct student stu;
	PSTU pstu = &stu;	//�ȼ���  struct student * pstu = &stu;
	pstu->age = 10;
	printf("%d\n", pstu->age);
	printf("%d\n", stu.age);

/*	struct student stu;
	stu.age = 10;
	printf("%d\n",stu.age);
*/
	return 0;
}