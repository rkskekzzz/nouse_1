// 1010 번

#include <iostream>
#include <vector>
#include <algorithm>

int T;
int N, M;
int max;
std::vector<int> ip;
std::vector<std::vector<int> > dp;


void output()
{
	for (int i = 0 ; i < T ; i += 2)
		std::cout << dp[ip[i + 1] - 1][(ip[i] > ((ip[i + 1] - 1) >> 1) ? ip[i + 1] - ip[i] : ip[i])] << '\n';
}

void solution()
{
	for(int i = 2 ; i < max ; i++)
		for(int j = 1; j < (((i + 1) >> 1) + 1) ; j++)
			dp[i][j] = (i % 2) && (j == (i >> 1) + 1) ? dp[i - 1][j - 1] << 1 : dp[i - 1][j] + dp[i - 1][j - 1];
}

void input()
{
	std::cin >> T;
	T = T << 1;
	ip.resize(T);
	for (int i = 0 ; i < T ; i += 2)
		std::cin >> ip[i] >> ip[i + 1];
	max = *std::max_element(ip.begin(), ip.end());
	dp.resize(max);
	for(int i = 0 ; i < max ; i++)
		dp[i] = std::vector<int>(((i + 1) >> 1) + 1, 1);
	if (max > 1)
		++dp[1][1];
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
