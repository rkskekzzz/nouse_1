#include <iostream>
#include <algorithm>
using namespace std;

void solution();
int arr[100000];

int main(void)
{
    solution();
    return 0;
}

long long count_cable(int k, int mid)
{
    long long sum = 0;
    for (int i = 0 ; i < k ; i++)
    {
        if (arr[i] < mid)
            break;
        sum += arr[i] / mid;
    }
    return  sum;
}

int max_length(int k, int m, int top)
{
    long long count = 0, start = 1, result = 0;
    long long mid, sum;
    while (start <= top)
    {
        mid = (start + top) / 2;
        sum = count_cable(k, mid);
        if (sum >= m)
        {
            if (result < mid)
                result = mid;
            start = mid + 1;
        }
        else
            top = mid - 1;
    }
    return result;
}

void solution()
{
    int k, m, top_length = 0;
    
    cin >> k >> m;
    for (int i = 0 ; i < k ; i++)
        cin >> arr[i];
    sort(arr, arr + k, greater<int>());
    cout << max_length(k, m, arr[0]);
}