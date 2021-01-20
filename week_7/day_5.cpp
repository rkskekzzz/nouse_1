#include <iostream>
#include <vector>

std::vector<int> dp_vector;
int n;

void output()
{
	std::cout << dp_vector[n];
}

void solution()
{
	dp_vector[1] = 1;
	dp_vector[2] = 2;
	for (int i = 3 ; i <= n ; i++)
	{
		dp_vector[i] = dp_vector[i - 2] + dp_vector[i - 1];
		if (dp_vector[i] >= 10007)
			dp_vector[i] %= 10007;
	}
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

int main()
{
	preset();
	input();
	solution();
	output();
}
