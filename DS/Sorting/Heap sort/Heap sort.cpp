//堆排序/希尔排序
//原文地址：https://blog.csdn.net/qq_29542611/article/details/79356378



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#define MAXSIZE 1000000
//交换值
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//打印数组元素
void PrintArr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}
long GetSysTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

//堆调整 大堆顶，将最大值放在根结点
void BigHeadAdjust(int* arr, int index, int length)
{
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int max = index;
	if (lchild<length && arr[lchild]>arr[max])
	{
		max = lchild;
	}
	if (rchild<length && arr[rchild]>arr[max])
	{
		max = rchild;
	}
	if (max != index)
	{
		Swap(&arr[max], &arr[index]);
		BigHeadAdjust(arr, max, length);
	}
	return;
}

//堆排序，采用大顶堆 升序
void HeapSort_Up(int* arr, int length)
{
	//初始化堆，将每个非叶子结点倒叙进行大顶堆调整。
	//循环完毕 初始大顶堆（每个根结点都比它孩子结点值大）形成
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		BigHeadAdjust(arr, i, length);
	}
	//printf("大堆顶初始化顺序：");
	//PrintArr(arr, length);
	//将堆顶值放到数组尾部，然后又进行大堆顶调整，一次堆调整最值就到堆顶了。 
	for (int i = length - 1; i >= 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		BigHeadAdjust(arr, 0, i);
	}
	return;
}

//堆调整 小堆顶，将最小值放在根结点
void SmallHeadAdjust(int* arr, int index, int length)
{
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int min = index;
	if (lchild < length && arr[lchild] < arr[min])
	{
		min = lchild;
	}
	if (rchild < length && arr[rchild] < arr[min])
	{
		min = rchild;
	}
	if (min != index)
	{
		Swap(&arr[min], &arr[index]);
		SmallHeadAdjust(arr, min, length);
	}
	return;
}

//堆排序，采用小顶堆 降序
void HeapSort_Down(int* arr, int length)
{
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		SmallHeadAdjust(arr, i, length);
	}
	for (int i = length - 1; i >= 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		SmallHeadAdjust(arr, 0, i);
	}
	return;
}
//希尔排序 升序
//根据插入排序的原理，将原来的一个大组，采用间隔的形式分成很多小组，分别进行插入排序
//每一轮结束后 继续分成更小的组进行 插入排序，直到分成的小组长度为1，说明插入排序完毕
void ShellSort_Up(int* arr, int length)
{
	int increase = length;
	int i, j, k, temp;
	do
	{
		increase = increase / 3 + 1;//每个小组的长度
									//每个小组的第0个元素
		for (i = 0; i < increase; i++)
		{
			//对每个小组进行插入排序，因为是间隔的形式分组，每个小组下一个元素为 j+=increse
			for (j = i + increase; j < length; j += increase)
			{
				temp = arr[j];//待插入元素

				for (k = j - increase; k >= 0 && temp < arr[k]; k -= increase)
				{
					arr[k + increase] = arr[k];
				}
				arr[k + increase] = temp;
			}
		}
	} while (increase > 1);
}

int main(int argc, char* argv[])
{
	srand((size_t)time(NULL));//设置随机种子
	int arr[10] = { 6,8,2,3,9,7,4,1,5,10 };
	int* arr2 = (int*)malloc(sizeof(int) * MAXSIZE);
	int* arr3 = (int*)malloc(sizeof(int) * MAXSIZE);
	//给每个元素设置一个随机值
	for (int i = 0; i < MAXSIZE; i++)
	{
		int num = rand() % MAXSIZE;
		arr2[i] = num;
		arr3[i] = num;
	}
	printf("排序前:\n");
	PrintArr(arr, 10);
	printf("堆排序升序:\n");
	HeapSort_Up(arr, 10);
	PrintArr(arr, 10);
	printf("堆排序降序:\n");
	HeapSort_Down(arr, 10);
	PrintArr(arr, 10);

	long start1 = GetSysTime();
	ShellSort_Up(arr2, MAXSIZE);
	long end1 = GetSysTime();
	printf("%d个元素 希尔排序耗费%d毫秒\n", MAXSIZE, end1 - start1);

	long start2 = GetSysTime();
	HeapSort_Up(arr3, MAXSIZE);
	long end2 = GetSysTime();
	printf("%d个元素 堆排序耗费%d毫秒\n", MAXSIZE, end2 - start2);
	return 0;
}