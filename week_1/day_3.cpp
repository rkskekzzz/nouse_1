#include <iostream>
#include <stdlib.h>
using namespace std;

void solution(void);
long long count_height(long long n, long long max, long long m);
long long trees[1000001];

int main(void)
{
    solution();
    return 0;
}

long long sum_height(long long n, long long height)
{
    long long sum = 0;
    for (int i = 0 ; i < n ; i++)
        if (trees[i] > height)
            sum += trees[i] - height;
    return sum;
}

long long count_height(long long n, long long max, long long m)
{
    long long sum = 0;
    long long start = 0;
    long long mid = 0;
    long long height = 0;
    
    while (start <= max)
    {
        mid = (max + start) / 2;
        sum = sum_height(n, mid);
        if (sum >= m)
        {
            if (height < mid)
                height = mid;
            start = mid + 1;
        }
        else
            max = mid - 1;
    }
    return height;
}

void solution(void)
{
    long long n; // 나무의 수
    long long m; // 필요한 나무의 길이
    long long max = 0;

    cin >> n;
    cin >> m;
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> trees[i];
        if (trees[i] > max)
            max = trees[i];
    }
    cout << count_height(n, max, m);
}