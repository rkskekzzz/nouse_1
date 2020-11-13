#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int length, int key);
int *insertion_sort(int *arr, int size);
int *set_arr(int do_sort, int size);
void solution(void);

int main(void)
{
    solution();
    return (0);
}

void solution(void)
{
    int *search_array;
    int *data_array;
    int n;
    int m;

    scanf("%d", &n);
    data_array = set_arr(1, n);
    scanf("%d", &m);
    search_array = set_arr(0, n);
    for (int i = 0 ; i < m ; i++)
        printf("%d\n", binary_search(data_array, n, search_array[i]));
}

int *set_arr(int do_sort, int size)
{
    int *array = (int *)malloc(sizeof(int) * size);
    
    for (int i = 0 ; i < size; i++)
        scanf("%d", &array[i]);
    if (do_sort == 1)
        return (insertion_sort(array, size));
    return (array);
}

int binary_search(int *arr, int length, int key)
{
    int start = 0;
    int end = length -1;
    int mid;
    while (end >= start)
    {
        mid = (start + end) / 2; // 중앙 값
        if (arr[mid] == key)
            return (1);
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return (0);
}

int *insertion_sort(int *arr, int size)
{
    int temp;

    temp = 0;
    for (int i = 0 ; i < size - 1; i++)
    {
        for (int j = i + 1 ; j > 0 && arr[j] < arr[j-1]; j--)
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
    return (arr);
}