//折半插入排序
//1.查找到L(i)所在数组中的位置，
//2.将该位置以后的所有元素后移
//3.将L(i)复制到该位置
//该算法同时使用于顺序表和链表

#include<iostream>
using namespace std;

void InsertSort(int Arr[], int length) {
	int i, j, low, high, mid, temp;
	for (i = 1; i < length; i++)
	{
		temp = Arr[i];
		low = 0;//折半查找的范围
		high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (Arr[mid] > temp)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= low; j--)//查找位置，并后移
			Arr[j + 1] = Arr[j];
		Arr[high + 1] = temp;

	}
}

void OutputArr(int Arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		cout << Arr[i] << ", ";

	}
	cout << endl;
}

void main() {
	int Arr[] = { 45,57,12,31,1,60,92,71,87 };
	InsertSort(Arr, 9);
	OutputArr(Arr, 9);
}