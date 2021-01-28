#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::vector<int> test;

	test.resize(2);

	test[0] = 2;
	test[1] = 1;
	test[2] = 0;

	std::cout << test[0] << std::endl;
	std::cout << test[1] << std::endl;
	std::cout << test[2] << std::endl;
	std::cout << test[3] << std::endl;

	sort(test.begin(), test.end());
	std::cout << test[0] << std::endl;
	std::cout << test[1] << std::endl;
	std::cout << test[2] << std::endl;
	std::cout << test[3] << std::endl;
	return (0);
}
