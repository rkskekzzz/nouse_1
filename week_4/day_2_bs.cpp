#include <iostream>
#include <vector>
#include <algorithm>

int x, n;
std::vector<int> array;

void input()
{
	std::cin >> n;
	array.resize(n);
	for (int i = 0; i < n; i++)
		std::cin >> array[i];
	std::sort(array.begin(), array.end());
}

void solution()
{
	int start, mid, end;
	int hole_size = 10000000 * x;

	for (int i = 0; i < n; i++)
	{
		start = i + 1;
		end = n - 1;
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (array[mid] + array[i] > hole_size)
				end = mid - 1;
			else if (array[mid] + array[i] < hole_size)
				start = mid + 1;
			else
			{
				std::cout << "yes " << array[i] << ' ' << array[mid] << '\n';
				return;
			}
		}
	}
	std::cout << "danger\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (std::cin >> x)
	{
		input();
		solution();
	}
	return 0;
}
