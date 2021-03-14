// 9465 번

#include <iostream>
#include <vector>
#include <algorithm>

size_t T;
size_t N;
std::vector<std::vector<std::vector<int> > > ip;
std::vector<std::vector<std::vector<int> > > dp;

void output()
{
	size_t len;
	for (size_t i = 0 ; i < T ; i++)
	{
		len = ip[i].size() - 1;
		std::cout << std::max(dp[i][len][0], dp[i][len][1]) << '\n';
	}
}

void solution()
{
	size_t len;

	for (size_t i = 0 ; i < T ; i++)
	{
		len = ip[i].size();
		for (size_t j = 2 ; j < len; j++)
		{
			dp[i][j][0] = std::max(dp[i][j - 1][1], dp[i][j - 2][1]) + ip[i][j][0];
			dp[i][j][1] = std::max(dp[i][j - 1][0], dp[i][j - 2][0]) + ip[i][j][1];
		}
	}

	// for(size_t i = 0 ; i < T ; i++)
	// {
	// 	len = dp[i].size();
	// 	for (size_t j = 0 ; j < len * 2; j++)
	// 		std::cout << dp[i][((j < len) ? j : j - len)][((j < len) ? 0 : 1)] << " ";
	// 	std::cout << '\n';
	// }
}

void input()
{
	// size_t len;

	std::cin >> T;
	ip.resize(T);
	dp.resize(T);
	for(size_t i = 0 ; i < T ; i++)
	{
		std::cin >> N;
		ip[i] = std::vector(N + 1, std::vector(2, 0));
		dp[i] = std::vector(N + 1, std::vector(2, 0));
		for (size_t j = 0 ; j < N * 2; j++)
				std::cin >> ip[i][(j % N)+ 1][j / N];
		dp[i][1][0] = ip[i][1][0];
		dp[i][1][1] = ip[i][1][1];
	}
	// std::cout << "input test\n";
	// for(size_t i = 0 ; i < T ; i++)
	// {
	// 	len = dp[i].size();
	// 	for (size_t j = 0 ; j < len* 2; j++)
	// 		std::cout << dp[i][((j < len) ? j : j - len)][((j < len) ? 0 : 1)] << " ";
	// 	std::cout << '\n';
	// }
	// std::cout << "solution\n";

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
