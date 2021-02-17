#include <iostream>
#include <vector>

int N;
int M;
std::vector<std::vector<int> > arr;
int test_size;
std::vector<std::vector<int > > test_arr;

void output()
{
	for (int i = 0 ; i < test_size ; i++)
	{
		std::cout << arr[test_arr[i][2]][test_arr[i][3]]
		 - arr[test_arr[i][0] - 1][test_arr[i][3]]
		 - arr[test_arr[i][2]][test_arr[i][1] - 1]
		 + arr[test_arr[i][0] - 1][test_arr[i][1] - 1] << '\n';
	}
}

void solution()
{
	for(int i = 1; i <= N ; i++)
		for (int j = 1 ; j <= M ; j++)
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
}

void input()
{
	std::cin >> N >> M;
	arr.resize(N + 1, std::vector(M + 1, 0));
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= M ; j++)
			std::cin >> arr[i][j];
	std::cin >> test_size;
	test_arr.resize(test_size, std::vector(4, 0));
	for (int i = 0  ; i < test_size ; i++)
		for (int j = 0 ; j < 4; j++)
			std::cin >> test_arr[i][j];
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

