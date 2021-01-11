#include <algorithm>
#include <iostream>
#include <vector>

int N, M;
std::vector<int> card;

void input()
{	
	int val;

	std::cin >> N;
	card.resize(N);
	for (int i = 0 ; i < N ; i++)
		std::cin >> card[i];
	std::cin >> M;
	std::sort(card.begin(), card.end());
	for (int i = 0 ; i <  M ; i++)
	{
		std::cin >> val;
		std::cout << std::upper_bound(card.begin(), card.end(), val) -
			std::lower_bound(card.begin(), card.end(), val) << '\n';
	}
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
}
