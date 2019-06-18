//堆排序算法
//1.构造初始堆。将给定无序序列构造成一个大顶堆（一般升序采用大顶堆，降序采用小顶堆)。
//2.将堆顶元素与末尾元素进行交换，使末尾元素最大。然后继续调整堆，再将堆顶元素与末尾元素交换，
//得到第二大元素。如此反复进行交换、重建、交换。
//
//
//a.将无需序列构建成一个堆，根据升序降序需求选择大顶堆或小顶堆;
//b.将堆顶元素与末尾元素交换，将最大元素"沉"到数组末端;
//c.重新调整结构，使其满足堆定义，然后继续交换堆顶元素与当前末尾元素，反复执行调整 + 交换步骤，
//直到整个序列有序。


#include<iostream>
using namespace std;

void Heapsort(int Arr, int length)
{
	function fun;

	//数组排序为升序排列，则创建大根堆
	//1.构建大顶堆
	for (int i = int(length / 2) - 1; i >= 0; i--) {
		//从第一个非叶子结点从下至上，从右至左调整结构
		
	}
	//2.调整堆结构+交换堆顶元素与末尾元素
	for (int j = length - 1; j > 0; j--) {
		fun.swap(Arr, 0, j);//将堆顶元素与末尾元素进行交换
		fun.adjustHeap(Arr, 0, j);//重新对堆进行调整
	}

}


class function {

void adjustHeap(int Arr[], int i, int length)
{
	//将数据放入树状结构
	//从第一个非叶子结点从下至上，从右至左调整结构

	int temp = Arr[i];
	for (int k = i * 2 + 1; k < length; k = k * 2 + 1) {//从i结点的左子结点开始，也就是2i+1处开始
		if (k + 1 < length && Arr[k] < Arr[k + 1]) {//如果左子结点小于右子结点，k指向右子结点
			k++;
		}
		if (Arr[k] > temp) {//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
			Arr[i] = Arr[k];
			i = k;
		}
		else {
			break;
		}
	}
	Arr[i] = temp;//将temp值放到最终的位置

}

void swap(int Arr[], int a, int b) {
	//交换元素
	int temp = Arr[a];
	Arr[a] = Arr[b];
	Arr[b] = temp;
}

void OutputArr(int Arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << Arr[i] << ", ";

	}
	cout << endl;
}
};

void main()
{
	int Arr[] = { 9,8,7,6,5,4,3,2,1 };
	int length = 9;
	Heapsort(Arr, length);
	OutputArr(Arr, length);
}