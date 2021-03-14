// 2293 번

#include <iostream>
#include <vector>
#include <algorithm>

int N, K;
int max;
std::vector<int> ip;
std::vector<int> dp;

void output()
{
	std::cout << dp[K] << add();
}

void solution()
{
	for(int i = 0 ; i < N ; i++)
		for(int j = ip[i] ; j <= K ; j++)
			dp[j] = dp[j] + dp[j - ip[i]];
}

void input()
{
	std::cin >> N >> K;
	ip.resize(N);
	dp.resize(K + 1);
	for (auto &i : ip)
		std::cin >> i;
	dp[0] = 1;
	for (auto &i : ip)
		std::cout << i << " ";
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
