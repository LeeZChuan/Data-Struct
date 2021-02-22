// PA.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//此版本为测试版本

#include <iostream>

using namespace std;
int main()
{
    const int arr = 10; //数组长度为
    int data[arr];

    int getNum;//输入的数字
    int k;  // getNum的平方根 
    int i = 0;//循环次数
    int sum=0;//求和
    int arry=0;//循环的数组变量

    do {
        cout<< "请输入一个大于1的数字，0代表结束:\n"<<endl;
        cin >> getNum;

        if (getNum > 0&& getNum!=1)
        {
            data[arry] = getNum;
            arry++;
            cout << arry;
            //求素数：步骤
            // 求平方根，注意sqrt()的参数为 double 类型，这里要强制转换m的类型 
            k = (int)sqrt((double)getNum);
            //循环判断
            for (i = 2; i <= k; i++)
            {
                if (getNum % i == 0)
                    break;
            }
            if (i > k)
            {
                cout << "该数是素数";
                sum += getNum;
            }
            

        }
    } while (getNum != 0);
    {
        cout <<"当前数组大小为：" <<arry<<endl;
        cout << "当前数组为：" << data << endl;
        cout << "输出和为" << sum << endl;
    }
}



