
#include<stdio.h>
#include<stdlib.h>

void sortprint(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void minfixheapsort(int* arr, int i, int n)
{
	int lift = i * 2 + 1;
	int right = i * 2 + 2;

	//如果左子树越界
	if (lift >= n) {
		return;
	}
	int min = lift;
	if (right >=n)//如果右子树越界
	{
		min = lift;
	}
	else//都没越界
	{
		if (arr[lift] > arr[right])//如果右子树比左子树小
		{
			min = right;
		}
	}
	if (arr[i] > arr[min])//若想要实现大顶堆，只需把这个 > 与上一个 > 改为 < 即可
	{
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	minfixheapsort(arr, min, n);


}

void makeheap(int* arr, int n)//建堆
{
	int i = 0;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		minfixheapsort(arr, i, n);
	}
}

void minheapsort(int* arr, int n)
{
	makeheap(arr, n);
	int i = 0;
	for (i = n -1; i >= 0; i--)//排序
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp; 
		minfixheapsort(arr,0,i);
	}

}


int main() {

	int arr[6] = { 9,3,8,6,4,5 };

	sortprint(arr, 6);

	minheapsort(arr, 6);

	sortprint(arr, 6);

	return 0;
}
