#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int N, NN, vill_count, K, result;
std::pair<int, int> start_position;
std::string vill;
std::vector<bool> visited;
std::vector<int> godo;
std::vector<std::pair<int, int>> direction;
std::vector<int> godo_set;

void input()
{
	int h;
	std::cin >> N;
	NN = N * N;
	vill.resize(NN);
	godo.resize(NN);
	direction = {{0, 1}, {0, -1}, {1, 0}, {-1 ,0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };
	result = 1e6;

	for (int i = 0; i < NN; i++)
	{
		std::cin >> vill[i];
		if (vill[i] == 'P')
			start_position = std::make_pair(i / N, i % N);
		else if (vill[i] == 'K')
			vill_count++;
	}
	for (int i = 0; i < NN; i++)
		std::cin >> godo[i];
	godo_set = godo;
	std::sort(godo_set.begin(), godo_set.end());
	godo_set.erase(std::unique(godo_set.begin(),godo_set.end()), godo_set.end());
}

void dfs(int x, int y, int min, int max)
{
	int xNy = x * N + y;

	if (x < 0 || y < 0 || x >= N || y >= N || visited[xNy] || godo[xNy] < min || godo[xNy]> max || K == vill_count)
		return;
	visited[xNy] = true;
	if (vill[xNy] == 'K')
		++K;
	for (int i = 0; i < 8; i++)
		dfs(x + direction[i].first, y + direction[i].second, min, max);
}

void solution()
{
	int r_idx = 0;
	int l_idx = 0;
	int size = static_cast<int>(godo_set.size());
	for (; r_idx < size; r_idx++){
		for (; l_idx < size; l_idx++)
		{
			visited = std::vector<bool>(NN, false);
			K = 0;
			dfs(start_position.first, start_position.second, godo_set[l_idx], godo_set[r_idx]);
			if (K != vill_count)
				break;
			result = std::min(result, godo_set[r_idx] - godo_set[l_idx]);
		}
	}
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void output() { std::cout << result; }

int main()
{
	preset();
	input();
	solution();
	output();
	return 0;
}
