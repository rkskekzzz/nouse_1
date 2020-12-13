#include <iostream>
#include <vector>

int K, Q;
long long N, result;
std::vector<std::pair<long long, long long> > nodes;

void input()
{
	std::cin >> N >> K >> Q;
	nodes.resize(Q);
	for (int i = 0; i < Q; i++)
		std::cin >> nodes[i].first >> nodes[i].second;
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void output() { std::cout << result << '\n'; }

void solution()
{
	for (int i = 0; i < Q; i++)
	{
		result = 0;
		if (K == 1)
			result = std::abs(nodes[i].first - nodes[i].second);
		else
		{
			while (nodes[i].first != nodes[i].second)
			{
				if (nodes[i].first > nodes[i].second)
					nodes[i].first = (nodes[i].first - 2) / K + 1;
				else
					nodes[i].second = (nodes[i].second - 2) / K + 1;
				++result;
			}
		}
		output();
	}
}

int main()
{
	preset();
	input();
	solution();
	return 0;
}
