#include <iostream>
#include <algorithm>
using namespace std;

void solution(void);

int main()
{
    solution();
    return 0;
}

long long cal_sum(int *arr, int n, long long mid)
{
    long long sum = 0;
    int i;
    for (i = 0 ; i < n ; i++)
    {
        if (arr[i] < mid)
            sum += arr[i];
        else
            break;
    }
    sum += (n - i) * mid;
    return sum;
}

int binary_search(int *arr, int n, int m, int end)
{
    long long mid, sum;
    int start = 0, result = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;
        sum = cal_sum(arr, n, mid);
        if (m > sum)
        {
            if (result < mid)
                result = mid;
            start = mid + 1;
        }
        else if(m == sum)
            return mid;
        else 
            end = mid - 1;
    }
    return result;
}

void set_arr(int *arr, int n)
{
    for (int i = 0 ; i < n ; i++)
        cin >> arr[i];
}

void solution(){
    int max_val = 0, n, m;
    int arr[100001];
    long long sum = 0;
    
    cin >> n;
    set_arr(arr, n);
    sort(arr, arr+n);
    cin >> m;
    for (int i = 0 ; i < n ; i++)
        sum += arr[i];
    if (sum <= m)
        cout << max_val;
    else
        cout << binary_search(arr, n, m, arr[n - 1]);
}