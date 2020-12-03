#include <iostream>


int main() {
	double x, y;
	x = 50;
	y = 29;

	double result_dou = y / x * 100;
	int result_int = y / x * 100;
	std::cout << "result_dou : " << result_dou << "\n" << "result_int : " << result_int << std::endl;
	return 0;
}
