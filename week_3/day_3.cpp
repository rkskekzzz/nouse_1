#include <iostream>
#include <algorithm>

int N, H;
int up_obstacle[100001];
int down_obstacle[100001];

void input()
{
	std::cin >> N >> H;
	for (int i = 0; i < (N / 2); i++)
	{
		std::cin >> down_obstacle[i] >> up_obstacle[i];
	}
	std::sort(up_obstacle, up_obstacle + (N / 2));
	std::sort(down_obstacle, down_obstacle + (N / 2));
}

void solution()
{
	int count_result;
	int i = 0, count = 0, section_result = 0;

	count_result = N / 2;
	while (++i <= H)
	{
		int up_lower_bound = std::upper_bound(up_obstacle, up_obstacle + (N / 2), H - i) - up_obstacle;
		int down_lower_bound = std::lower_bound(down_obstacle, down_obstacle + (N / 2), i) - down_obstacle;

		count = N - up_lower_bound - down_lower_bound;
		if (count_result == count)
			++section_result;
		else if (count_result > count){
			count_result = count;
			section_result = 1;
		}

	}
	std::cout << count_result << " " << section_result << std::endl;
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
