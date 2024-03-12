
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

	//���������Խ��
	if (lift >= n) {
		return;
	}
	int min = lift;
	if (right >=n)//���������Խ��
	{
		min = lift;
	}
	else//��ûԽ��
	{
		if (arr[lift] > arr[right])//�����������������С
		{
			min = right;
		}
	}
	if (arr[i] > arr[min])
	{
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	minfixheapsort(arr, min, n);


}

void makeheap(int* arr, int n)//����
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
	for (i = n -1; i >= 0; i--)//����
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