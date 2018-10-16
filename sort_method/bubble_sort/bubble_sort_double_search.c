#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//set flag variable and double search(max and min) version
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
	int low = 0;
	int high = len - 1;
	int i,pos;
	while (low<high)
	{
		pos = 0;
		//正向查找找最大值
		for ( i = low; i < high; i++)
		{
			if (p[i]>p[i+1])
			{
				pos = i;
				p[i] = p[i] ^ p[i + 1];
				p[i + 1] = p[i] ^ p[i+ 1];
				p[i] = p[i] ^ p[i + 1];
			}
		}
		high=pos;
		pos = 0;
		for (i = high; i >low; i--)
		{
			if(p[i]<p[i-1])
			{
				pos = i;
				p[i] = p[i] ^ p[i - 1];
				p[i -1] = p[i] ^ p[i - 1];
				p[i] = p[i] ^ p[i - 1];
			}
		}
		low=pos;
	}
}
int main(){
	int arr[10];
	int len = 10;
	generate_arr(arr, len);
	print_arr(arr, len);
	sort(arr, len);
	puts("\n");
	print_arr(arr, len);
	getchar();
}
