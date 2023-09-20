#include<stdio.h>
#include<math.h>
int main()
{
    int A, B, C;
    int t = 0;
    int human = 0;
    printf("请输入您的楼层号");
    scanf_s("%d %d %d", &A, &B, &C);
    printf("%d %d %d\n", C, t, human);
    t = abs(C - A);
    human += 1;
    printf("%d %d %d\n", A, t, human);
    t += abs(A - B);
    human -= 1;
    printf("%d %d %d\n", B, t, human);
    return 0;
}