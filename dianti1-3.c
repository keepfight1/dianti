#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int num1;
    int human;
    int floor = 1;
    printf("电梯的初始楼层%d\n", floor);
    int t = 0;//声明时间
    int p = 0;//声明初始的人数
    printf("请输入有多少人准备乘坐电梯");
    scanf_s("%d", &human);
    int i;
    int human1 = human;
    int* begin = (int*)malloc(sizeof(int) * human);
    int* end = (int*)malloc(sizeof(int) * human);
    for (i = 0; i < human; i++) {//循环输入起点和终点
        scanf_s("%d %d", &begin[i], &end[i]);
    }
    int* aim1 = (int*)malloc(sizeof(int) * human);
    for (i = 0; i < human; i++) {//初始化aim1数组
        aim1[i] = 100;
    }
    do {
        int* d1 = (int*)malloc(sizeof(int) * human);
        int* d2 = (int*)malloc(sizeof(int) * human);
        int t1 = 0;
        int min = 100;
        for (i = 0; i < human; i++) {//计算起始楼层与人们所在楼层的额最小距离
            d1[i] = abs(begin[i] - floor);
            d2[i] = abs(aim1[i] - floor);
            if (min > d1[i] && p != 4) {
                min = d1[i];
            }
            if (min > d2[i]) {
                min = d2[i];
            }
        }
        for (i = 0; i < human; i++) {//到达最近楼层
            if (min == d1[i]) {
                t1 = abs(floor - begin[i]);//计算时间差
                floor = begin[i];
                begin[i] = 100;//使d1[i]很大，无法赋值给min
                break;
            }
            if (min == d2[i]) {
                t1 = abs(floor - aim1[i]);//计算时间差
                floor = aim1[i];
                aim1[i] = 100;//使d2[i]很大，无法赋值给min
                break;
            }
        }
        num1 = i;
        /*printf("%d\n",num1);*/
        t += t1;
        if (floor == end[num1]) {
            p--;//下电梯
            human1--;//减去下电梯的人
        }
        else {
            p++;//上电梯
            aim1[num1] = end[num1];//aim数组是把乘客进入电梯后按下的楼层归入电梯的目标楼层
        }
        printf("%d %d %d\n", floor, t, p);//输出第二个停靠点
        free(d1);
        free(d2);
    } while (p != 0 || human1 != 0);
    free(aim1);
    free(end);
    free(begin);
    return 0;
}