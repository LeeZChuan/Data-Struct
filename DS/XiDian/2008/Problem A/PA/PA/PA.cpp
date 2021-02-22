
/*
2008 problem A
判定给定数列是否构成等差数列
cin:多组数据：测试个数 N N个数 n
cout:排序后可以构成等差数列 yes 否则：no
*/
#include<cstdio> 
#include<algorithm> 
#include<iostream>
using namespace std;
int n;

bool fun(int a[]) {
	int temp = a[1] - a[0];
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] - a[i] != temp)
			return false;
	}
	return true;
}

int main() {
	while (cin >> n) {
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n); // 按题目的意思是给定的序列，按说不该打乱数组的顺序，emmmmmm
		if (fun(a))cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}