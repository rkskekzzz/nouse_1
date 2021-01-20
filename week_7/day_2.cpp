#include <iostream>
#include <vector>

std::vector<int> dp_vector;
std::vector<int> dp_input;
std::vector<int> result;
int n;

void output()
{
	for (int i = 0 ; i < n ; i++)
		std::cout << dp_vector[dp_input[i]] << '\n';
}

void solution()
{
	dp_vector[1] = 1;
	dp_vector[2] = 2;
	dp_vector[3] = 4;
	for (int i = 0 ; i < n ; i++)
		for (int j = 4 ; j <= dp_input[i]; j++)
			dp_vector[j] = dp_vector[j - 3] + dp_vector[j - 2] + dp_vector[j - 1];
}

void input()
{
	int MAX = 0;

	std::cin >> n;
	dp_input.resize(n);
	for (int i = 0 ; i < n ; i++)
	{
		std::cin >> dp_input[i];
		MAX = std::max(MAX, dp_input[i]);
	}
	dp_vector.resize(MAX);
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
