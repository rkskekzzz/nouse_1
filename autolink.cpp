// Github Markdown AutoLink Code

#include <iostream>
#include <vector>

std::vector<std::pair<std::vector<int >, int> > questions;
std::vector<std::string> status = {"Ongoing", "Incomplete", "Complete"};
std::string directory_name = "week_";
std::string question_name = "day_";
int question_cnt;
int week;
int week_cnt;

void input_check()
{
	//
}

void input()
{
	week_cnt = 1;
	std::cout << "* 몇 주차 부터 등록하실 건가요?\t\t";
	std::cin >> week;
	std::cout << "* 몇 주치를 등록하실 건가요?   \t\t";
	std::cin >> week_cnt;
	std::cout << std::endl;
	questions.resize(week_cnt);
	for (int i = 0 ; i < week_cnt ; i++)
	{
		std::cout << "-----------------< week " << week + i << " >----------------\n"; 
		std::cout << "1. 이번주에 몇 문제를 풀었나요?\t\t";
		std::cin >> question_cnt;
		questions[i].first.resize(question_cnt);
		std::cout << "2. 문제 번호를 입력하세요 !\n";
		for (int j = 0 ; j < question_cnt ; j++)
		{
			std::cout << "Question " << j + 1 << " : ";
			std::cin >> questions[i].first[j];
		}
		std::cout << "3. 이주의 Status ? (Ongoing : 0 / Incomplete : 1 / Complete : 2)\nStatus : ";	
		std::cin >> questions[i].second;
		std::cout << std::endl;
	}
}

int main()
{
	input();

	std::cout << "******************* Result ********************\n\n";
	for (int i =  week; i < week + week_cnt ; i++)
	{
		std::cout << "|[week_" << i  << "](/" << directory_name << i << ")|" ;
		for (size_t j = 0 ; j < questions[i - week].first.size() ; j++)
		{
			std::cout << "[" << questions[i - week].first[j] << "](/" << directory_name << i
				<< "/" << question_name << j + 1  <<".cpp) ";
		}
		std::cout << "|" << status[questions[i - week].second] << "|" << std::endl;
	}
	std::cout << std::endl;
}
