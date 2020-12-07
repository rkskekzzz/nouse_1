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
	int start;
	int end = n - 1;
	int mid;
	int hole_size = 10000000 * x;

	for (int i = 0; i < n; i++)
	{
		start = i;
		while (start <= end)
		{
			mid = (start + end) / 2;
			std::cout << "mid : " << mid << std::endl;
			if (array[mid] + array[i] > hole_size)
				end = mid - 1;
			else if (array[mid] + array[i] == hole_size)
			{
				std::cout << "yes " << array[i] << ' ' << array[mid];
				return ;
			}
			else
				start = mid + 1;
		}
	}
	std::cout << "danger";
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
}
