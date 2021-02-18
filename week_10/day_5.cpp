#include <iostream>
#include <vector>

int N;
int K;
int result;
std::vector<std::vector<int> > dp;

void output()
{
	std::cout << dp[K][N];
}

void solution()
{
	for (int i = 2 ; i <= K; i++)
	{
		for (int j = 0 ; j <= N ; j++)
		{
			for (int k = 0 ; k <= j ; k++ )
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000000000;
			}
		}
	}
	/*
	for (int i = 0 ; i <= K; i++)
	{
		for (int j = 0 ; j <= N ;j++)
		{
			std::cout << dp[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/
}

void input()
{
	std::cin >> N >> K;
	dp = std::vector(K + 1, std::vector(N + 1, 0));
	for (int i = 0 ; i <= N ; i++)
		dp[1][i] = 1;

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
