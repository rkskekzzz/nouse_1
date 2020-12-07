#include <iostream>
#include <vector>

int n, m, sum, min;
std::vector<int> money_to_use;

void input()
{
	std::cin >> n >> m;
	money_to_use.resize(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> money_to_use[i];
		sum += money_to_use[i];
		min = (min < money_to_use[i]) ? money_to_use[i] : min;
	}
}

void solution()
{
	int start = min;
	int end = sum;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int used_day = 1;
		int disappeared_money = 0;

		for (int i = 0; i < n; i++)
		{
			if (disappeared_money + money_to_use[i] > mid)
			{
				disappeared_money = 0;
				++used_day;
				if (used_day > m)
					break;
			}
			disappeared_money += money_to_use[i];
		}
		if (used_day <= m)
			end = mid - 1;
		else
			start = mid + 1;
	}
	std::cout << start;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	input();
	solution();
}
