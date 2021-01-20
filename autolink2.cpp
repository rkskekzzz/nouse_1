#include <iostream>

// Github Markdown AutoLink Code

// /boj/bronze/boj_qqqq.cpp
int main()
{
	int a[] = {1348, 2191, 2842, 2842, 2912, 9202};
	int cnt = 0;
	std::string status[] = {"Ongoing", "Incomplete", "Complete"};
	std::string dif[] = {"bronze", "silver", "gold", "platinum"};
	int level = 3;
	std::cout << "|[" << dif[level] << "](/boj/" << dif[level] <<")|";
	for (int i = 0 ; i <  6; i++)
	{
		std::cout << "[" << a[i] << "](" << "/boj/" << dif[level] << "/boj_" << a[i] << ".cpp" << ") ";
		++cnt;
		if (cnt == 5)
		{
			//std::cout << "<br>";
			cnt = 0;
		}
	}
	std::cout << "|" << std::endl;
}
