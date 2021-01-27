#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int> > cost;
int n;

void output()
{
	std::cout << std::min({cost[n-1][0], cost[n-1][1], cost[n-1][2]});
}

void solution()
{
	for (int i = 1 ; i <  n ; i++)
		for (int j = 0 ; j < 3 ; j++)
			cost[i][j] += std::min(cost[i - 1][(j + 1) % 3], cost[i - 1][(j + 2) % 3]);
}

void input()
{
	std::cin >> n;
	cost.resize(n + 2, std::vector<int>(3, 0));
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < 3 ; j++)
			std::cin >> cost[i][j];
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main(void)
{
	preset();
	input();
	solution();
	output();
}
