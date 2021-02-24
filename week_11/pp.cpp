#include <iostream>

int main()
{
	int visited = 8;

	if ((visited & (1 << 3)) == 1 << 3)
			std::cout << "된다!";
	else
	{
			std::cout << "안된다!";
	}

}
