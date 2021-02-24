#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int> > map;
std::vector<bool> dp;

void input()
{
	std::cin >> N;
	map = std::vector(N, std::vector(N, 0));
	dp = std::vector(10);
	//dp = std::vector(N, std::vector(N, 0));
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			std::cin >> map[i][j];
	std::cout << "****************************\n";
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N ; j++)
			std::cout << map[i][j] << " ";
		std::cout << std::endl;
	}
	dp[1010101010] = 1;
	dp[1111111111] = 1
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
}
