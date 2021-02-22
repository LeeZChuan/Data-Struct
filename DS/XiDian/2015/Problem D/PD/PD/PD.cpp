// PD.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include<stdio.h>
#include<algorithm>
using namespace std;
struct Score {
    char num[22]; //学号
    int cou;   //回答题目数
    int score; //成绩
}Stu[1000];
bool cmp(Score a, Score b)
{
    if (a.cou != b.cou) return a.cou > b.cou;
    else return a.score < b.score;
}
int main()
{
    FILE* fp; //定义一个指向文件型数据的指针变量
    int i = 0;
    fp = fopen("Score.txt", "r"); //fopen("filename","使用打开方式");
    while (!feof(fp))   //如果未遇到输入文件的结束标志就继续执行
    {
        fscanf(fp, "%s%d%d", Stu[i].num, &Stu[i].cou, &Stu[i].score); //文件标准读入方式
        i++;
    }
    sort(Stu, Stu + i, cmp);  //库函数，排序
    for (int j = 0; j < i; j++)
        printf("%s %d %d\n", Stu[j].num, Stu[j].cou, Stu[j].score);
    fclose(fp); //fclose(文件指针); 关闭数据文件。
    return 0;
}
