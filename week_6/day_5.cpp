#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int	N;
int	M;
int	S;
int	V;
int	result;
std::vector<std::pair<double, double> > mice;
std::vector<std::pair<double, double> > hole;
std::vector<std::vector<int> > connect;
std::vector<int> linked;
std::vector<bool> visited;

void output() { std::cout << result; }

bool dfs_matching(int mouse)
{
	if (visited[mouse])
		return false;
	visited[mouse] = true;
	for (size_t i = 0 ; i < connect[mouse].size() ; i++)
	{
		if (linked[connect[mouse][i]] == -1 || dfs_matching(linked[connect[mouse][i]]))
		{
			linked[connect[mouse][i]] = mouse;
			return true;
		}
		
	}
	return false;
}

void dfs()
{
	std::fill(linked.begin(), linked.end(), -1);
	for (int i = 0 ; i < N ; i++)
	{
		std::fill(visited.begin(), visited.end(), false);
		if(dfs_matching(i))
			--result;
	}
}

void cal_dist()
{
	int max = pow(S * V, 2);
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			if(pow(mice[i].first - hole[j].first, 2) + pow(mice[i].second - hole[j].second, 2) <= max)
				connect[i].push_back(j);

}

void solution()
{
	cal_dist();
	dfs();
}

void input()
{
	std::cin >> N >> M >> S >> V;
	mice.resize(N);
	hole.resize(M);
	connect.resize(N);
	visited.resize(M);
	linked.resize(M);
	for (int i = 0 ; i < N ; i++)
		std::cin >> mice[i].first >> mice[i].second;
	for (int i = 0 ; i < M ; i++)
		std::cin >> hole[i].first >> hole[i].second;
	result = N;
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
