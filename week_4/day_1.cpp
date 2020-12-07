#include <iostream>
#include <vector>

int N, M;
int S, E;
std::vector<int> array;

void input()
{
	std::cin >> N >> M;
	array.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> array[i];
		E += array[i];
		S = (S < array[i]) ? array[i] : S;
	}
}

void solution(int n, int m)
{
	int mid, cnt, sum;
	int start = S, end = E;

	while (start <= end)
	{
		sum = 0;
		cnt = 1;
		mid = (start + end) / 2;
		for (int i = 0; i < N; i++)
		{
			if (sum + array[i] > mid)
			{
				sum = 0;
				++cnt;
			}
			sum += array[i];
		}
		if (cnt <= M)
			end = mid - 1;
		else
			start = mid + 1;
	}
	std::cout << start;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	input();
	solution(N, M);
	return 0;
}
