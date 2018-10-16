#include<stdio.h>
#define STACK_SIZE 50
int start[STACK_SIZE];
int end[STACK_SIZE];
int por = 0;
//利用栈的记忆性,实现快速排序的迭代方式
void push(int a, int b){
	start[por] = a;
	end[por] = b;
	por++;
}
void pop(int *low,int *high){
	por--;
	*low = start[por];
	*high = end[por];
}

void generate_arr(int *p, int len){
	//设置随机数种子
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
		*p++ = rand() % 1000;
}
void sort(int *p, int len){
	int low = 0;
	int high = len - 1;
	int start, end,t;
	push(low,high);
	while (por)
	{
		pop(&low, &high);
		start = low;
		end = high;
		int flag = p[(start + end) / 2];
		while (start<=end)
		{
			while (flag > p[start])
				start++;
			while (flag < p[end])
				end--;
			if (start<=end)
			{
				t = p[start];
				p[start] = p[end];
				p[end] = t;
				start++;
				end--;
			}
		}
		if (end>low)
			push(low, end);
		if (start < high)
			push(start, high);
	}
}
void print_arr(int *p, int len){
	for (int i = 0; i < len; i++)
		printf("%d,", p[i]);
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
