//该算法为冒泡排序

//算法介绍
//1.比较相邻的元素。如果第一个比第二个大，就交换他们两个。
//2.对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
//3.针对所有的元素重复以上的步骤，除了最后一个。
//4.持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

#include<iostream>
using namespace std;

void BubbleSort(int Arr[], int length) {
	int temp;
	int flag;
	for (int i = 0; i < length - 1; i++)
	{
		flag = 1;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag)
			return;
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
	BubbleSort(Arr, 9);
	OutputArr(Arr, 9);
}