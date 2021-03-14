// 9465 번

#include <algorithm>
#include <iostream>
#include <vector>

size_t T;
size_t N;
std::vector<std::vector<int>> ip;

void output()
{
	std::cout << std::max(ip[N][0], ip[N][1]) << '\n';
}

void input()
{
	std::cin >> N;
	ip = std::vector(N + 1, std::vector(2, 0));
	for (size_t j = 0; j < N * 2; j++)
		std::cin >> ip[(j % N) + 1][j / N];
}

void solution()
{
	input();
	for (size_t j = 2; j <= N; j++)
	{
		ip[j][0] = std::max(ip[j - 1][1], ip[j - 2][1]) + ip[j][0];
		ip[j][1] = std::max(ip[j - 1][0], ip[j - 2][0]) + ip[j][1];
	}
	output();
}

void rep()
{
	std::cin >> T;
	for (size_t i = 0; i < T; i++)
		solution();
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
	rep();
}
