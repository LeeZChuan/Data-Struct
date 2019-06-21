//顺序查找

//1.查询某特定元素是否在查找表中；
//
//2.检索该特定元素的各种属性；
//
//3.在查找表中插入一个数据元素；
//
//4.从查找表中删除某个数据元素。

//numData[] = { 12,31,25,67,80,51,77,32 };

#include<iostream>
#include<malloc.h>

using namespace std;

int numData[] = { 12,31,25,67,80,51,77,32 };
int length = sizeof(numData) / sizeof(int);
//sizeof是判断运算的长度

//算法结构
int SequentialSearch(int numData[], int searchElem) {
	for (int i = 0; i < length; i++)
	{
		if (numData[i] == searchElem)
			return i;
	}
	return -1;
}



void main(){
	int se;
	cout << "Please input the data that you want to inquire : ";
	cin >> se;
	int k = SequentialSearch(numData, se);
	if (k == -1)
		cout << "There is no data that you want to query in this array. " << endl;
	else
		cout << "The number of the data that you inquiring is : " << k << endl;

}
