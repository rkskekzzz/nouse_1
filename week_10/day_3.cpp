#include <iostream>
#include <vector>


int N;
std::vector<int> dp;

void output()
{
	std::cout << dp[N];
}

void solution()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3 ; i <= N ; i++)
	{
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
		if (dp[i] >= 10007)
			dp[i] %= 10007;
	}
}

void input()
{
	std::cin >> N;
	dp.resize(N + 1);
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
	output();
}
