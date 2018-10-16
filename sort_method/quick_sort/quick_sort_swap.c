#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//quick sort swap version (special fcous on the =)
void  quick_sort(int *p, int low, int high);
void generate_arr(int *p, int len){
	//设置随机数种子
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
		*p++ = rand() % 1000;
}
void sort(int *p, int len){
	quick_sort(p, 0, len - 1);
}
void print_arr(int *p, int len){
	for (int i = 0; i < len; i++)
		printf("%d,", p[i]);
}
void quick_sort(int *arr, int low, int high){
	if (low >= high)
		return;
		int t;
		int i = low;
		int j = high;
		int flag = arr[(low + high) / 2];
		while (i <= j)
		{
			while (i<j&&flag > arr[i])
				i++;
			while (i<j&&flag < arr[j])
				j--;
			if (i <= j)
			{
 				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
				i++;
				j--;
			}
		}
		quick_sort(arr, low, j);
		quick_sort(arr, i, high);
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
