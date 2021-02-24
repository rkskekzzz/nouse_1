#include <iostream>
#include <vector>

int N;
std::vector<int> arr;
std::vector<int> dp;

void output()
{
	std::cout << dp[N];
}

void input_sol()
{
	std::cin >> N;
	arr.resize(N + 1);
	dp.resize(N + 1);
	for (int i = 1 ; i <= N ; i++)
	{
		std::cin >> arr[i];
		for (int j = 1 ; j <= i ; j++)
			dp[i] = std::max(dp[i], dp[i - j] + arr[j]);
	}
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
	input_sol();
	output();
}
