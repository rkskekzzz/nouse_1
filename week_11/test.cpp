#include <iostream>
#include <vector>
#include <algorithm>

size_t N;
std::vector<int> A;
std::vector<int> save;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N;
	A.resize(N);
	save.resize(N, 1);
	for (size_t i = 0 ; i < N ; i++)
		std::cin >> A[i];
}

void print_val()
{
	std::cout << save[N - 1];
}

void recursive(size_t ind)
{
	for (size_t i = ind + 1; i < N; i++)
	{
		if (A[ind] < A[i])
		{
			save[ind] = save[ind] < save[i] + 1 ? save[i] + 1 : save[ind];
		}
	}

}

void solve()
{
	for (size_t i = 0 ; i < N ; i++)
		recursive(i);
	for (size_t i = 1; i < N; i++)
	{
		std::cout << save[i] << " ";
	}
	std::sort(save.begin(), save.end());
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
