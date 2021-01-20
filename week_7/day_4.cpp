#include <iostream>
#include <vector>

std::vector<int> dp_vector;
std::vector<int> points;
int cnt;


void output()
{
	std::cout << dp_vector[cnt];
}

void solution()
{
	dp_vector[1] = points[1];
	dp_vector[2] = points[2] + points[1];
	for (int i = 3; i <= cnt ; i++)
	{
		dp_vector[i] = points[i] + std::max(dp_vector[i - 2], dp_vector[i - 3] + points[i - 1]);
	}
}

void input()
{
	std::cin >> cnt;
	points.resize(cnt + 1);
	dp_vector = std::vector<int>(cnt + 1, 0);
	for (int i = 1 ; i <= cnt ; i++)
		std::cin >> points[i];
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
