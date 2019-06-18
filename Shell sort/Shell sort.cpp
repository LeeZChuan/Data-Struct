//希尔排序

//算法介绍
//先将排序表分割成若干形如L[i,i+d,....,i+nd]的特殊子表，分别进行直接插入排序，


#include <iostream>;
using namespace std;

void ShellSort(int Array[], int length) {
	int j;
	int gap;
	int temp;
	//进行希尔排序，按照数组长度的一半来进行划分
	for (gap = int(length / 2); gap > 0; gap = int(gap / 2))
	{
		for (int i = 0; i < gap; i++)
		{
			for (int i = gap; i < length-1; i += gap)
			{
				for (int j = i; j >= gap; j -= gap)
				{
					if (Array[j] < Array[j - gap])
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

void ModInsSort(Array[], int length, int gap)
{
	int i, j;
	int temp;
	for (int i = gap; i < length - 1; i += gap)
	{
		for (int j = i; j >= gap; j -= gap)
		{
			if (Array[j] < Array[j - gap])
			{
				temp = Array[j];
				Array[j] = Array[j - gap];
				Array[j - gap] = temp;
			}
		}
	}
}

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
	int Array[] = { 45,57,12,31,1,60,92,71,87,89,25,48,47,12 };
	ShellSort(Array, 14);
	OutputArray(Array, 14);
}
