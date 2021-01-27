#include <iostream>
#include <vector>

std::vector<int> num;
int result;
int n;


void output()
{
	std::cout << result;
}

void solution()
{
	int max;
	int subsum;

	max = subsum = num[0];
	for (int i = 1 ; i < n ; i++)
	{
		subsum += num[i];
		if (subsum < num[i])
			subsum = num[i];
		max = std::max(max, subsum);
	}
	result = max;
}

void input()
{
	std::cin >> n;
	num.resize(n);
	for (int i = 0; i < n ; i++)
	{
		std::cin >> num[i];
	}
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


