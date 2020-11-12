#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n = 3; // array size;
    int m; // number of values
    int data_arr[100000]; // data set
    int search_arr[100000]; // value for search

    cin >> n;
    for (int i = 0; i < n ; i++)
        cin >> data_arr[i];
    sort(data_arr, data_arr + n);
    cin >> m;
    for (int i = 0 ; i < m ; i++)
        cin >> search_arr[i];
    for (int i = 0 ; i < m ; i++)
    {
        if (binary_search(data_arr, data_arr + n, search_arr[i]))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}