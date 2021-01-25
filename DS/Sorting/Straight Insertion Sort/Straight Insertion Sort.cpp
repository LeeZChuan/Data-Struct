//直接插入排序

//算法介绍
//1.查找到L(i)所在数组中的位置k，
//2.将该位置以后的所有元素后移
//将L(i)复制到L(k)中.
//直接排序是一个稳定的排序方法；
//适用性：直接插入排序适用于顺序存储和链式存储的线性表。为链式存储室，可以从前往后查找指定元素位置
//注意：大部分算法都仅仅适用于顺序存储的线性表

#include<iostream>
using namespace std;

void InserSort(int Arr[], int length)
{
	int temp;
	int i, j;
	for (i = 1; i < length; i++)//遍历所有数组中的元素
	{
		if (Arr[i] < Arr[i - 1])//找到不满足排序的要求,提取出来
		{
			temp = Arr[i];
			for (j = i - 1; temp<Arr[j]&&j>=0; j--)
			{
				Arr[j + 1] = Arr[j];
			}
			//出现数组前后顺序数值大小不一致，需要移动然后将不一致的数据插入进去
			    Arr[j + 1] = temp;
		}
	}
}


void OutputArr(int Arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		cout << Arr[i] << ",";

	}
	cout << endl;
}
void main()
{
	int Arr[] = { 45,85,78,59,25,48,15 };
	InserSort(Arr, 7);
	OutputArr(Arr, 7);
}

