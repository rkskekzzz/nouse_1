#include <iostream>
#include <vector>

int n;
std::vector<int> wines;
std::vector<int> dp_vector;

void output()
{
	std::cout << dp_vector[n];
}

void solution()
{
	dp_vector[1] = wines[1];
	if (n > 1)
		dp_vector[2] = wines[1] + wines[2];
	for (int i = 3 ; i <= n ; i++)
	{
		dp_vector[i] = wines[i] + std::max(dp_vector[i - 2], wines[i - 1] + dp_vector[i - 3]);
		dp_vector[i] = std::max(dp_vector[i - 1], dp_vector[i]);
	}
}

void input()
{
	std::cin >> n;
	wines.resize(n + 1);
	dp_vector.resize(n + 1);
	for (int i = 1 ; i <= n ; i++)
		std::cin >> wines[i];
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
