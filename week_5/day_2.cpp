#include <iostream>
#include <vector>
#include <algorithm>

int result;
int N, NN;
std::vector<bool> visited;
std::vector<int> matrix;
std::vector<int> matrix_unique;
std::vector<std::pair<int, int>> direction;
std::vector<int> a;
void input()
{
	std::cin >> N;
	NN = N * N;
	matrix.resize(NN);
	direction = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	for (int i = 0; i < NN; i++)
		std::cin >> matrix[i];
	matrix_unique = matrix;
	std::sort(matrix_unique.begin(), matrix_unique.end());
	matrix_unique.erase(std::unique(matrix_unique.begin(), matrix_unique.end()), matrix_unique.end());
	result = matrix_unique[static_cast<int>(matrix_unique.size()) - 1] - matrix_unique[0];

	a.resize(200000);
	for (int i = 0 ; i < 200000; i++)
	{
		a[i] = i;
		//a[i].second = i;
	}
}

bool dfs(int x, int y, int min, int max)
{
	int xNy = x * N + y;
	if (x < 0 || y < 0 || x >= N || y >= N || visited[xNy] || matrix[xNy] < min || matrix[xNy] > max)
		return false;
	visited[xNy] = true;
	if (xNy == NN - 1)
		return true;
	for (int i = 0; i < 4; i++)
		if (dfs(x + direction[i].first, y + direction[i].second, min, max))
			return true;
	return false;
}

void solution()
{
	int size = static_cast<int>(matrix_unique.size());
	int left = 0;
	int right = 0;

	for (; right < size; right++)
	{
		for (; left < size; left++)
		{
			if (matrix_unique[right] - matrix_unique[left] < result)
			{
				visited = std::vector<bool>(NN, false);
				if (!dfs(0, 0, matrix_unique[left], matrix_unique[right]))
					break;
				result = matrix_unique[right] - matrix_unique[left];
			}
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
}
