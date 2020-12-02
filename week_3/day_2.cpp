#include <iostream>

typedef long long ll;

int x, y;
int before_rate;

void input()
{
	std::cin >> x >> y;
	before_rate = static_cast<ll>(y) * 100 / x ;
}

void solution()
{
	int end, start, val;
	int mid, after_rate;
	int result = -1;
	start = 1;
	end = 1000000000;
	if (before_rate >= 99){
		std::cout << result;
		return ;
	}
	while (start <= end)
	{
		mid = (start + end) / 2;
		after_rate = static_cast<ll>(y + mid) * 100 / (x + mid);
		if (after_rate - before_rate >= 1)
		{
			result = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	std::cout << result;
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
