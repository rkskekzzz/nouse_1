#include <iostream>
#include <set>

std::set<int> cards;
int N, M;

void input()
{
	int num, check;

	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> num;
		cards.insert(num);
	}
	std::cin >> M;
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> check;
		if (cards.end() == cards.find(check))
			std::cout << 0 << '\n';
		else
			std::cout << 1 << '\n';
		
	}

}
void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main(void)
{
	preset();
	input();
}
