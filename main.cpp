#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void swap(int* x, int* y)//�������� 
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
	int pivot = a[low];//��ŦԪ 
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
	printf("����k��");
	scanf("%d", &k);
	int result = select(A, 0, 8, k);
	printf("��%dС����%d", k, result);
	system("pause");
}
