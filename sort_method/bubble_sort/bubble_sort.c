#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//normal version
void generate_arr(int *p, int len){
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
		*p++= rand()%1000;
}
void print_arr(int *p, int len){
	for (int i = 0; i < len; i++)
		printf("%d,", p[i]);
}
void sort(int *p, int len){
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			if (p[j]>p[j+1])
			{
				p[j] =  p[j] ^ p[j + 1];
				p[j + 1] = p[j] ^ p[j + 1];
				p[j] = p[j] ^ p[j + 1];
			}
		}
	}

}
int main(){
	int arr[10];
	int len = 10;
	generate_arr(arr, len);
	print_arr(arr, len);
	putchar('\n');
	sort(arr, len);
	print_arr(arr, len);
	putchar('\n');
}
