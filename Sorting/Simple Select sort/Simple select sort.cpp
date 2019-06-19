//简单选择排序
//遍历、对比、挑选、替换


#include<iostream>
using namespace std;

void SelectSort(int A[], int n)
{
	int temp = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[j] < A[min])
			{
				min = j;
			}
			if (min != i)
			{
				temp = A[min];
				A[min] = A[i];
				A[i] = temp;
			}
		}
	}
}


void OutputArr(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << ", ";

	}
	cout << endl;
}

void main()
{
	int A[]= { 6,88,75,45,57,12,31,1,60,92,71,87 };
	SelectSort(A, 12);
	OutputArr(A, 12);
}