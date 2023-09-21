#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int num1;
    int human;
    int floor = 1;
    int floor1;
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
        scanf_s("%d %d %d", &begin[i], &end[i], &time[i]);
    }
    int* aim1 = (int*)malloc(sizeof(int) * human);
    int* aim2 = (int*)malloc(sizeof(int) * human);
    for (i = 0; i < human; i++) {//初始化aim1数组
        aim1[i] = 100;
        aim2[i] = 100;
    }
    int timenow = 0;//声明实时时间
    int j = 0;
    do {
        for (j = 0; j < human; j++) {//判断乘客是否在当时按电梯
            if (timenow >= time[j]) {//使时间无法重复被读取
                aim2[j] = begin[j];
                time[j] = 100;
                break;
            }
        }
        int* d1 = (int*)malloc(sizeof(int) * human);
        int* d2 = (int*)malloc(sizeof(int) * human);
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
        if (min > 50) {//如果电梯没有读入数据则时间加一并跳过
            timenow++;
            continue;
        }//当没有目标aim楼层输入时停止循环
        for (i = 0; i < human; i++) {//到达最近楼层
            if (min == d1[i]) {
                floor1 = aim2[i];//目标楼层
                if (floor1 == floor)aim2[i] = 100;//使d1[i]很大，无法赋值给min
                break;
            }
            if (min == d2[i]) {
                floor1 = aim1[i];//目标楼层
                if (floor1 == floor)aim1[i] = 100;//使d2[i]很大，无法赋值给min
                break;
            }
        }
        if (floor1 > floor) {//楼层与时间实时变化
            floor++;
            timenow++;
            continue;
        }
        if (floor1 < floor) {
            floor--;
            timenow++;
            continue;
        }
        if (floor1 == floor) {
            num1 = i;
            if (floor == end[num1]) {
                p--;//下电梯
                human1--;//减去下电梯的人
            }
            else {
                p++;//上电梯
                aim1[num1] = end[num1];//aim数组是把乘客进入电梯后按下的楼层归入电梯的目标楼层
            }
            printf("%d %d %d\n", floor, timenow, p);//输出第二个停靠点
        }
    } while (p != 0 || human1 != 0);
    free(aim1);
    free(aim2);
    free(end);
    free(begin);
    free(time);
    return 0;
}