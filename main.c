#include <stdio.h>

typedef unsigned long long u64;
int array[] = {8, 4, 2, 1, 6, 9, 5, 3, 7};

int qsort(int *ptr, int low, int hight)
{
	int temp;
	temp = *(ptr + low);

	while(low < hight)
	{
		while((low < hight) && (temp <= *(ptr + hight)))
			hight--;
		*(ptr + low) = *(ptr + hight);

		while((low < hight) && (temp > *(ptr + low)))
			low ++;
		*(ptr + hight) = *(ptr + low);
	}
	*(ptr + low) = temp;

	printf("low = %d\n", low);
	printf("hight = %d\n", hight);
	return low;
}

void quick_sort(int *ptr, int low, int hight)
{
	int i;
	if(low < hight)
	{
		i = qsort(ptr, low, hight);
		quick_sort(ptr, 0, i - 1);
		quick_sort(ptr, i + 1, hight);
	}
}

int main(void)
{
	u64 fact = 1;
	fact = (fact*~0)/(fact*1<<32);
	printf("%d:fact=%llx\n", __LINE__, fact);
	printf("%d:~0=%llx\n", __LINE__, (u64)~0);
	
	printf("sizeof(array) = %d\n", sizeof(array)/sizeof(array[0]));
	int i;
	for(i = 0; i< sizeof(array)/sizeof(array[0]); i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}

	quick_sort(array, 0, sizeof(array)/sizeof(array[0]) - 1);

	for(i = 0; i< sizeof(array)/sizeof(array[0]); i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}

	return 0;
}
