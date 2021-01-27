#include <iostream>
#include <vector>

int n;
std::vector<long long> dp_vector;

void output()
{
	std::cout << dp_vector[n - 1];
}

void solution()
{
	dp_vector[0] = 1;
	dp_vector[1] = 1;
	for (int i = 2; i < n ; i++)
		dp_vector[i] = dp_vector[i - 1] + dp_vector[i - 2];
}

void input()
{
	std::cin >> n;
	dp_vector.resize(n + 1);
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
