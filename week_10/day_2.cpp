#include <iostream>
#include <vector>

int T;
std::vector<int> tests;
std::vector<int> dp;

void output()
{
	for (int i = 0 ; i < T ; i++)
		std::cout << dp[tests[i]] << '\n';
}

void solution()
{
	int stone;

	for (int i = 0 ; i < T ; i++)
	{
		stone = tests[i];
		while (stone != 1)
		{
			if (stone <= 100000 && dp[stone] != 1 || ((stone & (-stone)) == stone))
				break;
			dp[tests[i]] = std::max(dp[tests[i]], stone);
			if (stone % 2 == 0)
				stone /= 2;
			else
				++(stone *= 3);
		}
		dp[tests[i]] = std::max(dp[stone], dp[tests[i]]);
	}
}

void input()
{
	std::cin >> T;
	tests.resize(T);
	dp = std::vector(100001, 1);
	for (int i = 0 ; i < T ; i++)
		std::cin >> tests[i];
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
