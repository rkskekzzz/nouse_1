#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* dest, int* src);
void bubble_sort(int* arr, int length);
void selection_sort(int* arr, int length);
void insertion_sort(int* arr, int length);
void shell_sort(int *arr, int length);
int* counting_sort(int *arr, int length, int maxnum);
int arr[10000000];
char file_name[10000000];

int main(void)
{
	clock_t start, end;
	FILE* file;
	int temp, i = 0, size = 0, c_maxnum;
	int *c_arr;

	printf("Files list\n");
	printf("************************\n");
	printf("10.txt : 10 nums\n");
	printf("10000.txt : 10000 nums\n");
	printf("************************\n");
	printf("Which file to sort ? ");
	scanf("%s", &file_name);
	file = fopen(file_name, "rt");
	if (file == NULL)
	{
		printf("No file!\n");
		return (1);
	}
	while (feof(file)==0)
	{
		fscanf(file, "%d", &temp);
		arr[i++] = temp;
		size++;
	}
	fclose(file);

	printf("\n<before sorting>\n");
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	start = clock();

//	bubble_sort(arr, size);
//	selection_sort(arr, size);
//	insertion_sort(arr, size);
//	shell_sort(arr, size);
	c_maxnum = (file_name == "10.txt") ?  10 : 100;
	c_arr = counting_sort(arr, size, c_maxnum);
	
	end = clock();

	printf("\n\n<after sorting>\n");
	for (i = 0; i < size; i++)
		printf("%d ", c_arr[i]);
	printf("\nsorting time : %f\n", (float)(end - start) / CLOCKS_PER_SEC);
	return (0);
}

void swap(int* dest, int* src)
{
	int tmp;

	tmp = *dest;
	*dest = *src;
	*src = tmp;
}
/*
void quick_sort(int*arr, int length)
{
	
}
*/

void shell_sort(int *arr, int length)
{
	int h = 1;
	while(h < length / 3)
		h = 3 * h + 1;
	while(h >= 1)
	{
		for (int i = h; i <length ; i++)
			for (int j = i; j >= h && arr[j] < arr[j - h] ; j -= h)
				swap((arr + j), (arr + j - h ));
		h /= 3;
	}
}

int *counting_sort(int *arr, int length, int maxnum)
{
	int i;
	int *arr_result = (int *)calloc(length, sizeof(int));
	int *arr_counting = (int *)calloc(maxnum, sizeof(int));
	
	for (i = 0 ; i < length ; i++)
		arr_counting[arr[i]]++;
	for (i = 1 ; i < maxnum ; i++)
		arr_counting[i] += arr_counting[i - 1];
	for (i = length - 1 ; i >= 0 ; i--)
		arr_result[--arr_counting[arr[i]]] = arr[i];
	return (arr_result);
}

void insertion_sort(int* arr, int length)
{
	for (int i = 1; i < length; i++) 
		for (int j = i; j >= 0 && arr[j] < arr[j - 1]; j--) 
			swap((arr + j), (arr + j - 1));
}

void selection_sort(int* arr, int length)
{
	int min;

	
	for (int i = 0; i < length; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
			if (arr[i] > arr[j])
				min = j;
		if (min != i)
			swap((arr + i), (arr + min));
	}
}

void bubble_sort(int* arr, int length)
{
	for (int i = 0; i < length - 1; i++)
		for (int j = 0; j < length - i - 1; j++)
			if (*(arr + j) > *(arr + j + 1))
				swap((arr + j), (arr + j + 1));
}