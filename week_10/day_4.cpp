#include <iostream>
#include <queue>
#include <vector>

int col;
int row;
std::vector<std::vector<int>> arr;
std::vector<std::vector<int>> dp;
std::string x_dir = "2101";
std::string y_dir = "1012";
int result;

void output()
{
	std::cout << result;
}

int dfs(int x, int y)
{
	int next_x;
	int next_y;

	if (x == row - 1 && y == col - 1)
		return 1;
	if (dp[x][y] == -1)
	{
		dp[x][y] = 0;
		for (int i = 0; i < 4; i++)
		{
			next_x = x_dir[i] - '1' + x;
			next_y = y_dir[i] - '1' + y;
			if (next_x < 0 || next_y < 0 || next_x >= row || next_y >= col ||
				arr[x][y] <= arr[next_x][next_y])
				continue;
			dp[x][y] += dfs(next_x, next_y);
		}
	}
	return dp[x][y];
}

void solution()
{
	result = dfs(0, 0);
	/*
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			std::cout << dp[i][j] << " ";
		std::cout << std::endl;
	}
	*/
}

void input()
{
	std::cin >> row >> col;
	arr = std::vector(row, std::vector(col, 0));
	dp = std::vector(row, std::vector(col, -1));
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			std::cin >> arr[i][j];
	/****************	출력용   ***************/
	// for (int i = 0 ; i < row ; i++)
	//{
	//			for (int j = 0 ; j < col ; j++)
	//		std::cout << arr[i][j] << " ";
	//	std::cout << std::endl;
	//}
	// for (int i = 0 ; i < 4 ; i++)
	// std::cout << "(x, y) : " << x_dir[i] - '1' << "," << y_dir[i] - '1' << std::endl;
	/****************	출력용   ***************/
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
