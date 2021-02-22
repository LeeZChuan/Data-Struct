/*求一串数中大于1素数之和
输入输入个数  数字  不超过100个数 不超过10组 多组输入  0结束
例
输入
4 1 2 3 4
5 1 2 3 4 5
0
输出
5
10
*/
#include <iostream>
#include<algorithm>
using namespace std;

bool Isprime(int m)  //判断是否是素数
{
    //注意：sqrt放在循环外面使用。不要放在for的括号里面
    int bound = (int)sqrt(m) + 1; //计算枚举上界
    for (int i = 2; i < bound; i++)
    {
        if (m % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int num[100] = { 0 };
    int n;
    while (scanf_s("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            scanf_s("%d", &num[i]);
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (num[i] == 0 || num[i] == 1) //如果输入是0或者1，则跳过处理
                continue;
            else
            {
                if (Isprime(num[i]) == true)
                    sum = sum + num[i];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}



