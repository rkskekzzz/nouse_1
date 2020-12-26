#include <iostream>
#include <vector>

int number_of_beads, number_of_group, result;
int MAX, MIN;
std::vector<int> beads;
void input()
{
	std::cin >> number_of_beads >> number_of_group;
	beads.resize(number_of_beads);
	for (int i = 0; i < number_of_beads; i++)
	{
		std::cin >> beads[i];
		MAX += beads[i];
		MIN = std::max(MIN, beads[i]);
	}


bool calculate(int mid)
{
	int counts_of_group = 1;
	int sum_of_beads = 0;

	for (int i = 0; i < number_of_beads; i++)
	{
		if (sum_of_beads + beads[i] > mid)
		{
			sum_of_beads = 0;
			++counts_of_group;
		}
		sum_of_beads += beads[i];
	}
	return counts_of_group <= number_of_group;
}

void solution()
{
	int start = MIN;
	int mid;
	int end = MAX;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (calculate(mid))
			end = mid - 1;
		else
			start = mid + 1;
	}
	result = start;
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void output()
{
	int counts_of_beads = 0;
	int sum_of_beads = 0;

	std::cout << result << '\n';
	for (int i = 0; i < number_of_beads; i++)
	{
		if (sum_of_beads + beads[i] > result)
		{
			std::cout << counts_of_beads << ' ';
			counts_of_beads = 0;
			sum_of_beads = 0;
			--number_of_group;
		}
		++counts_of_beads;
		sum_of_beads += beads[i];
		if (number_of_beads - i == number_of_group)
			break;
	}
	while (number_of_group--)
	{
		std::cout << counts_of_beads << ' ';
		counts_of_beads = 1;
	}
}

int main()
{
	preset();
	input();
	solution();
	output();
}
