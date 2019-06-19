//希尔排序
//可以选择增量为2或者3的增量
//算法介绍
//先将排序表分割成若干形如L[i,i+d,....,i+nd]的特殊子表，分别进行直接插入排序，


#include <iostream>;
using namespace std;

void ShellSort(int Array[], int length) {
	int gap;//序列个数
	int temp;//暂存变量
	//进行希尔排序，按照数组长度的一半来进行划分
	for (gap = length / 2; gap > 0; gap = gap / 2)
		//“增量每次除以2递减”的Shell 排序  
	{
		for (int i = 0; i < gap; i++)
			//开始对每个小序列进行比对
		{
			for (int i = gap; i < length; i += gap)
				//对序列进行倍数的增加遍历
			{
				for (int j = i; j >= gap; j -= gap)
				{
					if (Array[j] < Array[j - gap])
						//小序列的头尾比较，如果序列头部大于尾部，进行交换，否则不交换
					{
						temp = Array[j];
						Array[j] = Array[j - gap];
						Array[j - gap] = temp;
					}
				}
			}
			//ModInsSort(Array[i], length, gap);
		}
	}
}

//void ModInsSort(Array[], int length, int gap)
//{
//	int i, j;
//	int temp;
//	for (int i = gap; i < length; i += gap)
//	{
//		for (int j = i; j >= gap; j -= gap)
//		{
//			if (Array[j] < Array[j - gap])
//			{
//				temp = Array[j];
//				Array[j] = Array[j - gap];
//				Array[j - gap] = temp;
//			}
//		}
//	}
//}

void OutputArray(int Array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << Array[i] << ",";
	}
	cout << endl;
}

void main()
{
	int Array[] = { 45,57,12,31,1,60,92,71,87,89,25,48,47,15 };
	ShellSort(Array, 14);
	OutputArray(Array, 14);
}
