#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int N;
int M;
int result;
std::vector<std::vector<int> > map;

void output()
{
	std::cout << result * result;
}

void solution()
{
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= M ; j++)
		{
			if(map[i][j] == 1)
				map[i][j] += std::min({map[i - 1][j], map[i - 1][j - 1], map[i][j - 1]});
			result = std::max(result, map[i][j]);
		}
}

void input()
{
	std::string str;

	std::cin >> N >> M;
	map = std::vector(N + 1, std::vector(M + 1, 0));
	for (int i = 1 ; i <= N ; i++)
	{
		std::cin >> str;
		for (int j = 1 ; j <= M ; j++)
		{
			map[i][j] = str[j - 1] - '0';
			if(map[i][j] == 1)
				map[i][j] += std::min({map[i - 1][j], map[i - 1][j - 1], map[i][j - 1]});
			result = std::max(result, map[i][j]);
		}
	}
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main()
{
	preset();
	input();
	//solution();
	output();
}

