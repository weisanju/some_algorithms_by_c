#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//quick sort end2end version
void  quick_sort(int *p, int low, int high);
void generate_arr(int *p, int len){
	//设置随机数种子
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
		*p++ = rand() % 1000;
}
int get_middle(int *arr, int low, int high){
	int flag = arr[low];
	while (low<high)
	{
		while (low<high&&arr[high]>flag)
			high--;
		arr[low] = arr[high];
		while (low<high&&arr[low]<flag)
			low++;
		arr[high] = arr[low];
	}
	arr[low] = flag;
	return low;
}
void sort(int *p, int len){
	quick_sort(p, 0, len - 1);
}
void print_arr(int *p, int len){
	for (int i = 0; i < len; i++)
		printf("%d,", p[i]);
}
void quick_sort(int *p, int low, int high){
	if (low<high)
	{
		int index = get_middle(p, low, high);
		quick_sort(p, low, index - 1);
		quick_sort(p, index+1,high);
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
