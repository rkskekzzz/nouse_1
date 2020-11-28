#include <cstdio>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void solution();

vector<int>::iterator it;
vector<int> arr[10001];
int visited[10001];
int count = 0;


int main(void)
{
    solution();
    return 0;
}

void dfs(int j)
{
    if (visited[j])
        return ;
    visited[j] = 1;
    count++;
    for(int i = 0; i < arr[j].size(); i++){
        int y = arr[j][i];
        dfs(y);
    }
}

void solution()
{
    int n, m, c1, c2;
    int max = 0;
    int depth[10001];
    scanf("%d %d", &n, &m);
    
    for (int i = 0 ; i < m ; i++)
    {
        scanf("%d %d", &c1, &c2);
        arr[c2].push_back(c1);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0 ; j < m ; j++)
            visited[j] = 0;
        count = 0;
        dfs(i);
        depth[i] = count;
    }
}

