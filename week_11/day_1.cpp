#include <iostream>
#include <vector>

int N;
int result;
std::vector<int> arr;
std::vector<int> dp;

void output()
{
	std::cout << result;
}

void solution()
{
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < i ; j++)
		{
			if (arr[i] > arr[j])
				dp[i] = std::max(dp[i], dp[j] + 1);
		}
		result = std::max(result, dp[i]);
	}
}

void input()
{
	std::cin >> N;
	arr.resize(N);
	dp = std::vector(N, 1);
	for (int i = 0 ; i < N ; i++)
		std::cin >> arr[i];
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
