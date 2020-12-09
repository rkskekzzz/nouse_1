#include <iostream>
#include <vector>

int N, M, max;
std::vector<int> array;

void input()
{
	std::cin >> N >> M;
	array.resize(M);
	for (int i = 0; i < M; i++)
	{
		std::cin >> array[i];
		max = (array[i] > max) ? array[i] : max;
	}
}

int calculate(int mid)
{
	int div_sum = 0;
	for (int i = 0; i < M; i++)
	{
		div_sum += array[i] / mid;
		if (array[i] % mid)
			++div_sum;
	}
	return div_sum;
}

void solution()
{
	int start = 1;
	int mid;
	int end = max;

	while (start <= end)
	{
		mid = (start + end) / 2;
		int div_sum = calculate(mid);

		if (div_sum > N)
			start = mid + 1;
		else
			end = mid - 1;
	}
	std::cout << start;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	input();
	solution();
	return 0;
}
