#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void swap(int* x, int* y)//交换函数 
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

}
int select(int a[], int low, int high, int k)
{
	if (low >= high) return a[low];
	int i = low;
	int j = high + 1;
	int pivot = a[low];//枢纽元 
	while (true)
	{
		do {
			i++;
		} while (a[i] < pivot);
		do {
			j--;
		} while (a[j] > pivot);
		if (i >= j) break;
		swap(&a[i], &a[j]);
	}
	if (j - low + 1 == k)
		return pivot;
	a[low] = a[j];
	a[j] = pivot;
	if (j - low + 1 < k)
		return select(a, j + 1, high, k - j + low - 1);
	else
		return select(a, low, j - 1, k);
}
int main() {
	int A[] = { 1,3,5,7,2,8,9,4,6 };
	int k;
	printf("输入k：");
	scanf("%d", &k);
	int result = select(A, 0, 8, k);
	printf("第%d小的是%d", k, result);
	system("pause");
}
