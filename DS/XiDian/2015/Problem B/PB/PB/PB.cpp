//压缩字符串
//测试数据：    ABBCCC
//有小问题
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main()
{
    int cou = 1;
    char c;
    char s1[1000]; //保存初始输入的字符串
    while (scanf_s("%s", s1) != EOF)
    {
        char s2[1000] = { '\0' };  //字符数组初始化为空
        int size = strlen(s1);
        for (int i = 0; i < size; i++)
        {
            c = s1[i];
            for (int j = i + 1; j < size; j++)
            {
                if (c == s1[j])
                    cou++;   //cou是计算出来的连续的字母的个数
                else break;
            }
            i = i + cou - 1; //因为字母有重复的，所以计算出 i 需要向后面跳几个格
            char s3[2];
            char str[4];
            s3[0] = c;
            s3[1] = '\0';
            strcat_s(s2, s3);
            if (cou != 1)
            {
                _itoa_s(cou, str, 10);  //类型转换函数。将十进制无符号整形cou转化成字符串str
                strcat_s(s2, str);
            }
            cou = 1;
        }
        puts(s2);
    }
    return 0;
}

