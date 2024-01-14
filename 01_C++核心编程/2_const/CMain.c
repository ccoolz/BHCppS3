#include <stdio.h>

const int global_const_c = 1;

int  fmain()
{
	int* pc1 = (int*)(&global_const_c);
	//(*pc1) = 2;	//引出异常，无写入权限
	printf("global_const_c = %d \n\n", global_const_c);
	//printf("*(pc1) = %d \n", (*pc1));


	const int local_const_c = 11;
	int* pc2 = (int*)(&local_const_c);
	*pc2 = 12;
	printf("local_const_c = %d \n", local_const_c);
	printf("*(pc1) = %d \n", *pc2);

	extern const int y;
	printf("%d\n", y);

	return 0;
}