#include <iostream>
#include <algorithm>

int N, H;
int up_obstacle[100001];
int down_obstacle[100001];

void input()
{
	std::cin >> N >> H;
	for (int i = 0; i < N / 2; i++)
	{
		std::cin >> up_obstacle[i] >> down_obstacle[i];
	}
	std::sort(up_obstacle, up_obstacle + (N / 2));
	std::sort(down_obstacle, down_obstacle + (N / 2));
}

void solution()
{
	int mid, section, result;
	int start = 0, end = H, i = 0, count = 0;

	section = 0;
	while (start <= end)
	{
		int up_lower_bound = std::lower_bound(up_obstacle, up_obstacle + N / 2, up_obstacle[mid]) - up_obstacle + 1;
		int down_lower_bound = std::lower_bound(down_obstacle, down_obstacle + N / 2, down_obstacle[mid])- down_obstacle + 1;

		if (up_lower_bound > down_lower_bound)
		{
			start = mid + 1;
		}
		else if (up_lower_bound == down_lower_bound){
			count = N - up_lower_bound + N - down_lower_bound;
			break;
		}
		else {
			end = mid - 1;
		}
		mid = (start + end) / 2;
		if (result > count)
			result = count;
	}
	std::cout << std::endl;
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
