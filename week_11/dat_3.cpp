#include <iostream>
#include <vector>

int T;
int N;
int m;
std::vector<long long> dp;
std::vector<int> tests;

void output()
{
	for (int t = 0; t < T; t++)
		//std::cout << "tests[i] : " << tests[t] << std::endl;
		std::cout << dp[tests[t] - 1] << '\n';
}

void solution()
{
	for (int i = 0; i < 3 && i < m; i++)
		dp[i] = 1;
	for (int i = 3; i < m; i++)
		dp[i] = dp[i - 2] + dp[i - 3];
	//for (int i = 0; i <= m; i++)
	//	std::cout << dp[i] << " ";
	//std::cout << std::endl;
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void input()
{
	std::cin >> T;
	tests.resize(T);
	for (int i = 0; i < T; i++)
	{
		std::cin >> tests[i];
		m = std::max(m, tests[i]);
	}
	dp.resize(m);
}

int main()
{
	preset();
	input();
	solution();
	output();
}
