#include <iostream>

// Github Markdown AutoLink Code

int main()
{
	int a[] = {1003, 11726, 1463, 2579, 9095};		//문제번호
	int weeknum = 7;					//작성 주차
	int weekcnt = 1;					//원하는 주 개수
	int quesnum = 5;					//문제 개수
	std::string status[] = {"Ongoing", "Incomplete", "Complete"};

	for (int i =  weeknum; i < weeknum + weekcnt ; i++)
	{
		std::cout << "|[week_" << i  << "]|(/week_" << i << ")|" ;
		for (int j = 0 ; j < quesnum ; j++)
		{
			std::cout << "[" << a[j] << "](/week_" << i << "/day_" << j + 1  <<".cpp) ";
		}
		std::cout << "|" << status[0] << "|" << std::endl;
	}

}
