#include <iostream>

int N;
int M;

void output()
{
	std::cout << N * M - 1;
}

void input()
{
	std::cin >> N >> M;
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
	output();
}
