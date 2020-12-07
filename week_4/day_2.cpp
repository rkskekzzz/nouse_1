#include <iostream>
#include <algorithm>
#include <vector>

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
	int down_pointer = 0;
	int up_pointer = n - 1;
	int hole_size = 10000000 * x;

	while (down_pointer < up_pointer)
	{
		int sum = array[down_pointer] + array[up_pointer];

		if (sum == hole_size)
		{
			std::cout << "yes " << array[down_pointer] << " " << array[up_pointer] << "\n";
			return;
		}
		else if (sum < hole_size)
			++down_pointer;
		else
			--up_pointer;
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
