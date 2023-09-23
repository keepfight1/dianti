#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int num1,num2,i;
    int judge;
    int human,human1;
    int floornow1=1;
    int floornow2=1;
    int floor1,floor2;
    int t = 0;//声明时间
    int p1 = 0;
    int p2 = 0;//声明初始的人数
    printf("两个电梯的初始楼层");
    scanf("%d %d/n",&floornow1,&floornow2);
    printf("请输入有多少人准备乘坐电梯");
    scanf("%d", &human);
    int begin[human];
    int end[human];
    int time[human];
    int d[human];
    int aim1[human];
    int aim2[human];
    int endaim1[human];
    int endaim2[human];
    human1=human;
    for (i = 0; i < human; i++) {//循环输入起点和终点
        scanf("%d %d %d", &begin[i], &end[i], &time[i]);
        if(begin[i]<end[i])d[i]=1;
        else d[i]=-1;
    }
    printf("\t楼层\t时间\t乘客\t\n");
    for (i = 0; i < human; i++) {//初始化aim1数组
        aim1[i] = 100;
        aim2[i] = 100;
        endaim1[i] = 100;
        endaim2[i] = 100;
    }
    int timenow = 0;//声明实时时间
    do {
        for ( i= 0;  i< human; i++) {//判断乘客是否在当时按电梯
            if (timenow >= time[i]) {
                if (p1 != 4) aim1[i]=begin[i];
                if (p2 != 4) aim2[i]=begin[i];
                time[i] = 100;//使时间无法重复被读取
            }
        }
        int d1[human];
        int d2[human];
        int endd1[human];
        int endd2[human];
        int min = 100;
        int min1 = 100;
        int min2 = 100;
        for (i = 0; i < human; i++) {//数组的遍历
            d1[i]=abs(aim1[i]-floornow1);
            d2[i]=abs(aim2[i]-floornow2);
            endd1[i]=abs(endaim1[i]-floornow1);
            endd2[i]=abs(endaim2[i]-floornow2);
        }
        for (i = 0,judge = 0; i < human; i++){//判断响应哪个电梯及判断方向
            if (min > d1[i] && p1 != 4){
            min = d1[i];
            judge=1;
            }
            if (min > d2[i] && p2 != 4){
            min = d2[i];
            judge=2;
            }
        }
            for (i = 0; i < human; i++){//第一个电梯
            if (min1 > endd1[i] && p1 != 4) min1 = endd1[i];
            if (min1 > min && judge==1) min1 = min;
            }
            for (i = 0; i < human; i++){//第二个电梯
            if (min2 > endd2[i] && p2 != 4) min2 = endd2[i];
            if (min2 > min && judge==2) min2 = min;
            }
        timenow++;
        do{
        if (min1 > 50) {//如果电梯没有读入数据则时间加一并跳过
            continue;
        }//当没有目标aim楼层输入时停止循环
        for (i = 0; i < human; i++) {//到达最近楼层
            if (min1 == d1[i]) {
                floor1 = aim1[i];//目标楼层
                if (floor1 == floornow1) aim1[i] = 100;
                break;
            }
            if (min1 == endd1[i]) {
                floor1 =endaim1[i];//目标楼层
                if (floor1 == floornow1)endaim1[i] = 100;//使d2[i]很大，无法赋值给min
                break;
            }
        }
        if (floor1 > floornow1) {//楼层与时间实时变化
            floornow1++;
            continue;//要更改
        }
        if (floor1 < floornow1) {//楼层与时间实时变化
            floornow1--;
            continue;//要更改
        }
        if (floor1 == floornow1) {
            num1 = i;
            timenow--;
            if (floor1 == end[num1]) {//num1可能出问题,分两步
                p1--;//下电梯
                human1--;//减去下电梯的人
            }
            if (floor1 == begin[num1]) {
                aim2[num1]=100;
                p1++;//上电梯
                endaim1[num1] = end[num1];//aim数组是把乘客进入电梯后按下的楼层归入电梯的目标楼层
            }
            printf("elevator1 %d\t%d\t%d\n", floornow1, timenow, p1);//输出停靠点
        }
        }while(1!=1);
        do{
        if (min2 > 50) {//如果电梯没有读入数据则时间加一并跳过
            continue;
        }//当没有目标aim楼层输入时停止循环
        for (i = 0; i < human; i++) {//到达最近楼层
            if(min2 == d2[i]){
                floor2=aim2[i];
                if(floor2 == floornow2) aim2[i]=100;
                break;
            }
            if (min2 == endd2[i]) {
                floor2 =endaim2[i];//目标楼层
                if (floor2 == floornow2)endaim2[i] = 100;
                break;
            }
        }
        if (floor2 > floornow2){
            floornow2++;
            continue;
        }
        if (floor2 < floornow2) {
            floornow2--;
            continue;
        }
        if (floor2 == floornow2) {
            num2 = i;
            timenow--;
            if (floor2 == end[num2]) {//num1可能出问题,分两步
                p2--;//下电梯
                human1--;//减去下电梯的人
            }
            if (floor2 == begin[num2]) {
                aim1[num2]=100;
                p2++;//上电梯
                endaim2[num2] = end[num2];//aim数组是把乘客进入电梯后按下的楼层归入电梯的目标楼层
            }
            printf("Elevator2 %d\t%d\t%d\n", floornow2, timenow, p2);//输出第二个停靠点
        }
        }while(1!=1);
    } while ((p1+p2)!= 0 || human1 != 0);
    return 0;
}