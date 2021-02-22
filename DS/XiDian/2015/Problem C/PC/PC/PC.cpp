// 有bug
//


#include <stdio.h>
using namespace std;
int main() {
    char net[11][11];                           //记录方向
    int passed[11][11];                         //passed[i][j] = 1表示该点已走过
    int n, m, c;                                  //n行m列的迷宫 机器人从c列开始走
    int i, j, ii, jj, flag;
    int count;
    scanf_s("%d %d %d", &n, &m, &c);
    while (0 != n && 0 != m && 0 != c) {
        count = 1;
        flag = 0;
        for (i = 1; i <= n; ++i)//输入
            scanf_s("%s", &net[i][1]);
        for (i = 1; i <= n; ++i)//记录走过的二维数组初始化0表示未走过
            for (j = 1; j <= m; ++j)
                passed[i][j] = 0;
        ii = 1;
        jj = c;
        while (1)//一直循环 加break做退出循环条件{
            if (1 == passed[ii][jj])//机器人位置 ii jj走过
            {
                flag = 1;
                break;
            }
        if ('N' == net[ii][jj]) {
            if (1 == ii) {                     //已到达最上端还要往上走，
                printf("%d\n", count);
                break;
            }
            else {
                passed[ii][jj] = 1;//改变记录数组 1表示走过
                ii = ii - 1; //向上走一格
                count++;   //步子加一
            }
        }//end if('N' == net[ii][jj])
        else if ('S' == net[ii][jj]) {
            if (n == ii) {                     //已到达最下端还要往下走，
                printf("%d\n", count);
                break;
            }
            else {
                passed[ii][jj] = 1;
                ii = ii + 1;
                count++;
            }
        }//end else if('S' == net[ii][jj])
        else if ('W' == net[ii][jj]) {
            if (1 == jj) {                     //已到达最左端还要往左走，
                printf("%d\n", count);
                break;
            }
            else {
                passed[ii][jj] = 1;
                jj = jj - 1;
                count++;
            }
        }//end else if('W' == net[ii][jj])
        else if ('E' == net[ii][jj]) {
            if (m == jj) {                     //已到达最右端还要往右走，
                printf("%d\n", count);
                break;
            }
            else {
                passed[ii][jj] = 1;
                jj = jj + 1;
                count++;
            }
        }//end else if('E' == net[ii][jj])
    }//end while(true)
    if (1 == flag)//记录数组中都是一 ，都走完了
        printf("no\n");
    scanf_s("%d %d %d", &n, &m, &c);//寻找失败 从新输入
//end while
return 0;
}
