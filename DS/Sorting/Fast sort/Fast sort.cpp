//此算法为快速排序算法

//基于冒泡排序的改进算法
//1．先从数列中取出一个数作为基准数。
//2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
//3．再对左右区间重复第二步，直到各区间只有一个数。
//



#include<iostream>
using namespace std;

int circle = 0;//遍历次数变量
void QuickSort(int* pdata, int low, int high)
{
	if (low < high)
	{
		int first = low, last = high;
		int key = pdata[first];
		while (first < last)
		{
			while (first < last && pdata[last] >= key)  //从右向左找第一个小于标准值的位置
				last--;
			if (first < last)
				pdata[first] = pdata[last];    //小的数排到前面
			while (first < last && pdata[first] <= key) //从左向右找比key小的值的位置,位置正确就不会进行调整
				first++;
			if (first < last)
				pdata[last] = pdata[first];    //大的数排到后面
			cout << "the " << ++circle << "round:";
		}
		pdata[first] = key;
		for (int i = 0; i < 10; i++)
			cout << pdata[i];
		cout << endl;
		QuickSort(pdata, low, first - 1);  //以first为中心分成两部分，
		QuickSort(pdata, first + 1, high);
	}
}
//方法二
//参考 http://developer.51cto.com/art/201403/430986.htm#commment
//很好理解（巡视的数组元素，不是比基准大的，就是比基准小的）
void quickSort(int* pdata, int left, int right)
{
	if (left >= right)//排序元素为0
	{
		return;
	}
	if (left < right)//如果需要排序的元素大于1个
	{
		int temp = 0;//暂存变量
		int key = pdata[left];
		int i = left, j = right;
		while (i != j)
			//排序中数据目前不考虑有相同数字的情况
		{
			while (pdata[j] >= key && i < j) //右边的哨兵开始向左巡逻
				j--;
			while (pdata[i] <= key && i < j) //左边的哨兵开始训练
				i++;
			if (i < j)  //如果两个哨兵没有相遇，则数据进行交换
			{
				temp = pdata[j];
				pdata[j] = pdata[i];
				pdata[i] = temp;
			}
			cout << "the " << ++circle << "round:";
		}
		pdata[left] = pdata[i];//i停的位置即<key的位置,i的值放到最左边
		pdata[i] = key;//基准位归位
		for (int m = 0; m < 10; m++)
			cout << pdata[m];
		cout << endl;
		quickSort(pdata, left, i - 1);//以i的位置为基准,分成两部分，左部分
		quickSort(pdata, i + 1, right);//右半部分
	}
}
int main()
{
	/*int data[] = { 6,1,2,7,9,3,4,5,10,8 };
	int data2[] = { 1,2,3,4,5,6 };
	int data3[] = { 9,8,7,6,5,4,3,2,1 };
	int data4[,],, = { 1,2,3,4,5,6,7,8,9 };*/
	int data[] = { 10,15,19,5,4,1,8,29,48,2,56 };
	cout << "----------------------------------" << endl;
	quickSort(data, 0, 10);
	for (int i = 0; i < 10; i++)
		cout << data[i] << ' ';
	cout << endl;
	return 0;
}