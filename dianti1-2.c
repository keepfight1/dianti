#include<stdio.h>
#include<math.h>
int main()
d
{
	FILE* fp;
	errno_t err = fopen_s(&fp, ".\\shuju.dat", "r");
	int A, B, C;
	int human = 0;
	int t = 0;
	fscanf_s(fp, "%d %d %d", &A,&B,&C);
	printf("%d %d %d\n", C, t, human);
	t = abs(C - A);
	human += 1;
	printf("%d %d %d\n", A, t, human);
	t += abs(A - B);
	human -= 1;
	printf("%d %d %d\n", B, t, human);
	fclose(fp);
	return 0;
}
