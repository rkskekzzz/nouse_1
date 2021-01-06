#include <iostream>
#include <vector>

int result;
int n;
std::vector<int> books;

void input()
{
	std::cin >> n;
	books.resize(n);
	for (int i = 0 ; i < n ; i++)
		std::cin >> books[i];
}

void solution()
{
	int pivot = n;

	for (int i = n - 1 ; i >= 0 ; i--)
		(pivot != books[i]) ? ++result : --pivot;
}

void output()
{
	std::cout << result;
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
	solution();
	output();
}
