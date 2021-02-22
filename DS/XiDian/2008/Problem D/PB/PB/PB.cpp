/*
2008 problem D
Smith数：各位和等于所有质因数各位数字和
cin:多组数据，每组一个数（n<100000）,0结束
cout:yes no
*/
#include<iostream>
using namespace std;
// 各位数之和
int sum_n(int n) {
	int s = 0;
	while (n / 10 != 0 || n % 10 != 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}
// 质因子之和 
int sum_factor(int n) {
	int sum = 0;
	for (int i = 2; i * i < n; i++) {
		while (n % i == 0) {
			sum += sum_n(i);	// 各位数之和 
			n /= i;
		}
	}
	if (n > 1) sum += sum_n(n);
	return sum;
}
int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		if (sum_n(n) == sum_factor(n))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}