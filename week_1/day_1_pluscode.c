#include <stdio.h>

int main(void)
{
    int n;
    int m;
    int i;
    int data_array[100000];
    int search_array[100000];
    
    i = -1;
    scanf("%d", &n);
    while (++i < n)
        scanf("%d", &data_array[i]);
    i = -1;
    
}

int *insertion_sort(int *arr, int size)
{
    for (int i = 0 ; i < size - 1; i++)
    {
        for (int j = i ; j >= 0 && arr[j] > arr[j-1]; j--)
        {
            
        }
    }
    
    
    return (arr);
}