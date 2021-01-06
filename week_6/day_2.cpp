#include <iostream>
#include <queue>
#include <string>
#include <vector>

int		result;
int		R;
int		C;
int		car_cnt;
;
int		park_cnt;

std::string map;
std::vector<std::pair<int, int>> dir;
std::vector<std::pair<int, int>> park;
std::vector<std::pair<int, int>> cars;
std::vector<std::vector<int>> dis;
std::vector<int> visited;
std::queue<std::pair<int, int>> qqq;

void	input()
{
	std::cin >> R >> C;
	map.resize(R * C);
	dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
	for (int i = 0; i < R * C; i++)
	{
		std::cin >> map[i];
		if (map[i] == 'C')
		{
			++car_cnt;
			cars.push_back(std::make_pair(i / C, i % C));
		}
		else if (map[i] == 'P')
		{
			++park_cnt;
			park.push_back(std::make_pair(i / C, i % C));
		}
	}
	dis.reserve(car_cnt);
	for (int i = 0; i < car_cnt; i++)
		dis[i].reserve(park_cnt);
	for (int i = 0; i < park_cnt; i++)
	{
		if (i % C == 0)
			std::cout << '\n';
		std::cout << map[i];
	}
}

void	bfs()
{
	int	x;
	int	y;
	int	next_x;
	int	next_y;

	std::cout << "\nstart bfs!" << std::endl;
	for (int i = 0; i < car_cnt; i++)
	{
		visited = std::vector<int>(R * C, -1);
		qqq = std::queue<std::pair<int, int>>();
		qqq.push({ cars[i].first, cars[i].second });
		visited[cars[i].first * C + cars[i].second] = 0;
		while (!qqq.empty())
		{
			x = qqq.front().first;
			y = qqq.front().second;
			std::cout << "x, y : " << x << ", " << y << std::endl;
			qqq.pop();
			for (int j = 0; j < 4; j++)
			{
				next_x = x + dir[j].first;
				next_y = y + dir[j].second;
				if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C &&
					visited[next_x * C + next_y] == -1)
				{
					visited[next_x * C + next_y] = visited[x * C + y] + 1;
					qqq.push({ next_x, next_y });
				}
			}
		}
		for (int k = 0; k < park_cnt; k++)
		{
			dis[i][k] = visited[park[k].first * C + park[k].second];
		}
	}
	for (int i = 0; i < car_cnt; i++)
	{
		std::cout << "car "<< i << "!!!" << std::endl;
		for (int j = 0; j < park_cnt; j++)
		{
			std::cout << "len : " << dis[i][j] << std::endl;
		}
	}
}

bool	ispossible()
{
	if (car_cnt != park_cnt)
		return (false);
	return (true);
}

void	solution()
{
	if (!ispossible())
	{
		result = -1;
		return ;
	}
	bfs();
}

void	preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	output()
{
	std::cout << result;
}

int		main()
{
	preset();
	input();
	solution();
	output();
}
