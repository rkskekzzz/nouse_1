#include <iostream>
#include <vector>

int N;
int MAX = 9999999;
std::vector<std::vector<int> > map;
std::vector<std::vector<int> > cache;


void input()
{
	std::cin >> N;
	map = std::vector(N, std::vector(N, 0));
	cache = std::vector(N, std::vector(65536, MAX));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			std::cin >> map[i][j];

}

int tsp(int cur, int visited)
{
	if (visited == (1 << (N)) - 1)
	{
		if (map[cur][0] > 0)
			return map[cur][0];
		return MAX;
	}
	if (cache[cur][visited] == MAX)
	{
		for (int i = 0; i < N; i++)
		{
			//std::cout << "방문노드 : " << visited << std::endl;
			if ((visited == (visited | (1 << i))) || !map[cur][i])
				continue;
			cache[cur][visited] = std::min(cache[cur][visited], tsp(i, visited | (1 << i)) + map[cur][i]);
		}
	}
	return cache[cur][visited];
}

void solution()
{
	std::cout << tsp(0, 1);
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
	solution();
}


