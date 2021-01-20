#include <iostream>
#include <vector>

std::vector<int> dp_vector;
int X;
int result;

void output()
{
	std::cout << result;
}

void solution()
{
	dp_vector[1] = 0;
	for (int i = 2 ; i <= X ; i++)
	{
		dp_vector[i] = dp_vector[i - 1] + 1;
		if (i % 2 == 0)
			dp_vector[i] = std::min(dp_vector[i],dp_vector[i / 2] + 1);
		if (i % 3 == 0)
			dp_vector[i] = std::min(dp_vector[i],dp_vector[i / 3] + 1);
	}
	result = dp_vector[X];
}

void input()
{
	std::cin >> X;
	dp_vector.resize(X + 1);
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
