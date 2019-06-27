//折半查找

//被查找的序列应该是有序的
//首先，假设表中元素是按升序排列，将表中间位置记录的关键字与查找关键字比较，如果两者相等，则查找成功；
//
//否则利用中间位置记录将表分成前、后两个子表，如果中间位置记录的关键字大于查找关键字，则进一步查找前一子表，否则进一步查找后一子表。
//
//重复以上过程，直到找到满足条件的记录，使查找成功，或直到子表不存在为止，此时查找不成功。

//Notes：1.必须采用顺序存储结构。2.必须按关键字大小有序排列。

//给定一组随机数列，然后使用冒泡排序进行排列，再使用折半查找算法进行查找

//使用C++的结构体来进行对返回数组的再次在方法中调用

#include<iostream>
#include<malloc.h>
using namespace std;


           //在结构里面包含数组
int numData[9] = { 31,15,85,95,74,16,88,95,10 };
int length = sizeof(numData) / sizeof(int);


int BinarySearch(int numData[], int searchElem)
{
	int small = 0;
	int middle;
	int large=length-1;
	if (searchElem > numData[large] || searchElem < numData[small])
	{
		return -1;
	}

	if (small < large)
	{
		middle = (small + large) / 2;
		if (searchElem == numData[middle])
			return middle;
		else if (searchElem > numData[middle])
			small = middle + 1;
		else
			large = middle - 1;

	}
	return -1;

}

void main()
{

	int se;
	cout << "Please input the data that you want to inquire : ";
	cin >> se;
	int k;

	k = BinarySearch(numData, se);
	if (k == -1)
		cout << "There is no data that you want to query in this array. " << endl;
	else
		cout << "The number of the data that you inquiring is : " << k << endl;

}