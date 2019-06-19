//该算法为冒泡排序

//算法介绍
//1.比较相邻的元素。如果第一个比第二个大，就交换他们两个。
//2.对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
//3.针对所有的元素重复以上的步骤，除了最后一个。
//4.持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

//Notes:每次冒泡排序过后，总会有一个元素被放在最终位置上。
//最终位置：就是该此排序每个元素的最终结果情况

#include<iostream>
using namespace std;

void BubbleSort(int Arr[], int length) {
	int temp;
	int flag;//表示本趟冒泡是否发生了交换的标志
	for (int i = 0; i < length - 1; i++)
		//每次遍历一遍数组总会把一个元素放置于正确的位置，
	{
		flag = 1;
		for (int j = 0; j < length - i - 1; j++)
		{
			//在每次遍历中，会把错误的元素放置于正确的位置上
			//当如果判断前面的数字大于后面的数字，需要进行交换，然后并且把交换信息置于0
			if (Arr[j] > Arr[j + 1])
			{
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag)
			return;//本趟遍历后没有发生交换，说明该表已经有序，无需再次进行遍历
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