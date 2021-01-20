#include <iostream>
#include <vector>

std::vector<int> dp_vector;
std::vector<int> input_vector;
int MAX;
int n;

void output()
{

	for (int i = 0 ; i < n ; i++)
	{
		if (!input_vector[i])
			std::cout << "1 0\n";
		else
			std::cout << dp_vector[input_vector[i] - 1] << " " << dp_vector[input_vector[i]] << '\n';
	}
}

void solution()
{
	dp_vector[0] = 0;
	dp_vector[1] = 1;
	for (int j = 2; j <= MAX; j++)
		dp_vector[j] = dp_vector[j - 2] + dp_vector[j - 1];
}

void input()
{
	std::cin >> n;
	input_vector.resize(n);
	for (int i = 0 ; i < n ; i++)
	{
		std::cin >> input_vector[i];
		MAX = std::max(MAX, input_vector[i]);
	}
	dp_vector.resize(MAX + 1);
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
