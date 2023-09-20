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
    int* begin = (int*)malloc(sizeof(int) * human);
    int* end = (int*)malloc(sizeof(int) * human);
    int* time = (int*)malloc(sizeof(int) * human);
    int i;
    int human1 = human;
    for (i = 0; i < human; i++) {//循环输入起点和终点
        int x, y, z;
        scanf_s("%d %d %d", &x, &y, &z);
        begin[i] = x;
        end[i] = y;
        time[i] = z;
    }
    int* aim1 = (int*)malloc(sizeof(int) * human);
    int* aim2 = (int*)malloc(sizeof(int) * human);
    for (i = 0; i < human; i++) {//初始化aim1数组
        aim1[i] = 100;
    }
    for (i = 0; i < human; i++) {//初始化aim1数组
        aim2[i] = 100;
    }
    int timenow = 0;//声明实时时间
    do {
        while (p != 0 || human1 != 0)
        {
            for (i = 0; i < human; i++) {//判断乘客是否在当时按电梯
                if (timenow < time[i])
                    continue;
                else aim2[i] = begin[i];
            }
            timenow++;
            int judge = 0;
            for (i = 0; i < human; i++) {
                if (timenow >= time[i])
                    judge = 1;
                break;
            }
            if (judge == 1)break;
        }
        int* d1 = (int*)malloc(sizeof(int) * human);
        int* d2 = (int*)malloc(sizeof(int) * human);
        int t1 = 0;
        int min = 100;
        for (i = 0; i < human; i++) {//计算起始楼层与人们所在楼层的额最小距离
            d1[i] = abs(aim2[i] - floor);
            d2[i] = abs(aim1[i] - floor);
            if (min > d1[i] && p != 4) {
                min = d1[i];
            }
            if (min > d2[i]) {
                min = d2[i];
            }
        }
        if (min > 50)continue;//当没有目标aim楼层输入时停止循环
        for (i = 0; i < human; i++) {//到达最近楼层
            if (min == d1[i]) {
                t1 = abs(floor - aim2[i]);//计算时间差
                floor = aim2[i];
                aim2[i] = 100;
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
        /*printf("%d\n",n3um1);*/
        timenow += t1;
        t = timenow - 1;
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
    free(aim2);
    free(end);
    free(begin);
    free(time);
    return 0;
}