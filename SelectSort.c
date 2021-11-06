#include<stdio.h>
int main(void)
{
	char arr[4] = { 9,3,6,1 };
	int MinIdx = 0;
	for (int i = 0; i < 3; i++)
	{
		MinIdx = i;
		for (int j = i+1; j < 4; j++)
		{
			if (arr[j] < arr[MinIdx])MinIdx = j;
		}
		int tmp = 0;
		tmp = arr[i];
		arr[i] = arr[MinIdx];
		arr[MinIdx] = tmp;
	}
	for (int i = 0; i < 4; i++)printf("%d  ", arr[i]);
	return 0;
}