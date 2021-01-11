#include <iostream>
#include <vector>
#include <algorithm>

int house_cnt;
int router_cnt;
int result;
std::vector<int> house;

void output() { std::cout << result; }

int cal_dist(int mid)
{
	int start = house[0];
	int count= 1;

	for (int i = 1 ; i < house_cnt ; i++)
	{
		if (house[i] - start >= mid)
		{
			++count;
			start = house[i];
		}
	}
	return count;
}

void solution()
{
	int left = 1;
	int mid;
	int right = house[house_cnt - 1] - house[0];

	while(left <= right)
	{
		mid = (left + right) / 2;
		if (cal_dist(mid) >=router_cnt)
		{
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
}

void input()
{
	std::cin >> house_cnt >> router_cnt;
	house.resize(house_cnt);
	for (int i = 0 ; i < house_cnt ; i++)
		std::cin >> house[i];
	std::sort(house.begin(), house.end());
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
