#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::pair<int, int> > station;
std::vector<bool> visited;

int n;
int k;
int result;

void input()
{
	std::cin >> n >> k;
	station.resize(n + 1);
	station[0] = std::make_pair(0, 0);
	for (int i = 1 ; i <= n; i++)
		std::cin >> station[i].first >> station[i].second;
}

int cal(int x1, int y1, int x2, int y2)
{
	return ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool dfs(int idx, int mid, int count)
{
	if (count > k)
		return false;
	visited[idx] = 1;
	for (int i = 1 ; i <= n ; i++)
	{
		if (visited[i] || cal(station[idx].first, station[idx].second, station[i].first, station[i].second) > mid)
			continue ;
		if (cal(station[i].first, station[i].second, 10000, 10000) <= mid || dfs(i, mid, count + 1))
			return true;
	}
	return false;
}

void solution()
{
	int left = 1;
	int mid;
	int right = 14143;

	while (left <= right)
	{
		mid = (left + right) / 2;
		visited = std::vector<bool>(n, false);
		if (dfs(0, mid * mid * 100, 0))
			right = mid - 1;
		else
			left = mid + 1;
	}
	result = left;
}

void preset(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void output(){std::cout << result; }

int main(){
	preset();
	input();
	solution();
	output();
}
