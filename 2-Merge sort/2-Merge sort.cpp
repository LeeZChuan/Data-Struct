//2-路归并排序

//利用递归，将原始序列不断两两分块，知道每块剩下一个元素，这个元素肯定是有序的。
//然后利用递归的原理合并即可；
//二路归并排序的最好，最坏，和平均时间复杂度为O(nlgn);是一种稳定的排序

#include<iostream>
using namespace std;

void Merge(int data[], int low, int mid, int high)
{
	int i = low, j = mid + 1, k = 0;
	int* temp = new int[high - low + 1];      //temp数组暂存合并的有序序列

	if (!temp)                                 //内存分配失败 
	{
		cout << "ERROR!";
		return;
	}

	while (i <= mid && j <= high)             //顺序选取两个有序区的较小元素，存储到t数组中
	{
		if (data[i] <= data[j])                 //较小的先存入temp中
			temp[k++] = data[i++];
		else
			temp[k++] = data[j++];
	}

	while (i <= mid)                          //若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
		temp[k++] = data[i++];
	while (j <= high)                         //同上
		temp[k++] = data[j++];
	for (i = low, k = 0; i <= high; i++, k++)     //将排好序的存回data中low到high这区间 
		data[i] = temp[k];
	delete[]temp;                          //删除指针，由于指向的是数组，必须用delete [] 
}


void MergeSort(int data[], int low, int high)
{                                            //用递归应用二路归并函数实现排序——分治法
	if (low < high)                             //（是if，不是while！，且不含等号！否则死循环！）
	{
		int mid = (low + high) / 2;
		MergeSort(data, low, mid);
		MergeSort(data, mid + 1, high);
		Merge(data, low, mid, high);
	}
}

int main()
{
	int x[] = { 0, 5, 33, 1, 8, 7, 23, 3 };
	MergeSort(x, 0, 7);
	for (int i = 0; i < 8; i++)
		cout << x[i] << " ";
	return 0;
}