#include <iostream>
#include <vector>

int T;
std::vector<int> tests;

void output()
{
	for (int i = 0 ; i < T ; i++)
		std::cout << tests[i] << '\n';
}

void solution()
{
	int n;

	for (int i = 0 ; i < T ; i++)
	{
		n = tests[i];
		while (n != 1)
		{
			tests[i] = std::max(n, tests[i]);
			if (n % 2 == 0)
				n /= 2;
			else
				(n *= 3)++;
		}
	}
}

void input()
{
	//std::cin >> T;
	T = 10;
	tests.resize(T);
	for (int i = 0 ; i < T ; i++)
		tests[i] = i + 1;
		//std::cin >> tests[i];
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

