#include <iostream>
#include <bitset>

int main()
{
	int arr[8];

	arr[1 << 0] = 1;
	arr[1 << 1] = 2;
	std::cout << "arr[1] : " << arr[1] << std::endl;
	std::cout << "arr[2] : " << arr[2] << std::endl;
	//std::cout << std::bitset<2>(a) << std::endl;
}

