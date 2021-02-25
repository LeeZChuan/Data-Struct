
/*
2008 problem A
使用C++编写
作者:Lee,时间:2021.2.25
判定给定数列是否构成等差数列
cin:多组数据：测试个数 N N个数 n
cout:排序后可以构成等差数列 yes 否则：no
输入样本：
6
23 15 4 18 35 11
3
3 1 2
0
输出样本：
yes
no
*/

#include<cstdio> 
#include<algorithm> 
#include<iostream>
using namespace std;
int n;

//arithmetic progression 等差数列判定
bool AP(int a[]) {
	//用排好序的数列进行判断
	int temp = a[1] - a[0];
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] - a[i] != temp)
			return false;
	}
	return true;
}

int main() {
	while (cin >>"输入数列长度:">> n) {
		//输入数列长度n
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >>a[i];
		}
		sort(a, a + n); 
		// 按题目的意思是给定的序列，按说不该打乱数组的顺序，
		//emmmmmm,但是,列子输出结果应该是进行排序过后的效果
		if (AP(a))cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}