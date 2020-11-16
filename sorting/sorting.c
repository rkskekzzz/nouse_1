#include <stdio.h>
#include <time.h>

void swap(int* dest, int* src);
void bubble_sort(int* arr, int length);
void selection_sort(int* arr, int length);
void insertion_sort(int* arr, int length);
int arr[10000000];
char file_name[10000000];

int main(void)
{
	clock_t start, end;
	FILE* file;
	int temp, i = 0, size = 0;

	printf("Files list\n");
    printf("************************\n");
    printf("10.txt : 10 nums\n");
    printf("1000.txt : 1000 nums\n");
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
    
    printf("<before sorting>\n");
    for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	start = clock();

	bubble_sort(arr, size);
	selection_sort(arr, size);
	insertion_sort(arr, size);

	end = clock();

    printf("\n\n<after sorting>\n");
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
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