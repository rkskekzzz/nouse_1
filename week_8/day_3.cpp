#include <iostream>
#include <vector>

std::vector<std::vector<int> > dp_vector;
int n;
int result;

void output()
{
	for (int i = 1 ; i <= n ; i++)
		result = std::max(result, dp_vector[n + 1][i]);
	std::cout << result;
}

void solution()
{
	for (int i = 2 ; i < n + 2; i++)
		for (int j = 0 ; j < i; j++)
			dp_vector[i][j] += std::max(dp_vector[i - 1][j], dp_vector[i - 1][j - 1]);
}

void input()
{
	std::cin >> n;
	dp_vector.resize(n + 2);
	for (int i = 0 ; i < n + 2; i++)
		dp_vector[i].resize(i + 1);
	for (int i = 2 ; i < n + 2 ; i++)
		for (int j = 1 ; j < i; j++)
			std::cin >> dp_vector[i][j];
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
