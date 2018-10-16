#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//set flag variable version
void generate_arr(int *p, int len){
	//设置随机数种子
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
		*p++ = rand() % 1000;
}
void print_arr(int *p, int len){
	for (int i = 0; i < len; i++)
		printf("%d,", p[i]);
}
void sort(int *p, int len){
	int i = len - 1;
	int pos;
	while (i>0)
	{
		pos = 0;
		for (int j = 0; j <i; j++)
		{
			if (p[j]>p[j + 1])
			{
				pos = j;
				p[j] = p[j] ^ p[j + 1];
				p[j + 1] = p[j] ^ p[j + 1];
				p[j] = p[j] ^ p[j + 1];
			}
		}
		i = pos;
	}

}
int main2(){
	int arr[10];
	int len = 10;
	generate_arr(arr, len);
	print_arr(arr, len);
	sort(arr, len);
	puts("\n");
	print_arr(arr, len);
	getchar();
	return 0;
}
