#include <iostream>
#include <vector>
#include <algorithm>

int number_of_points, number_of_newpoints, length_of_load;
int result;
std::vector<int> point;

void input(){
	int i;
	std::cin >> number_of_points >> number_of_newpoints >> length_of_load;
	point.resize(number_of_points + 2);
	point[0] = 0;
	for (i = 1 ; i <= number_of_points ; i++)
		std::cin >> point[i];
	point[i] = length_of_load;
	std::sort(point.begin(), point.end());
}

void solution(){
	int start = 1;
	int mid;
	int end = length_of_load - 1;

	while (start <= end){
		mid = (start + end) / 2;

		int count_of_newpoints = 0;
		for(int i = 1 ; i < number_of_points + 2 ; i++){
			int length_of_two_points = point[i] - point[i - 1];
			count_of_newpoints += length_of_two_points / mid;
			if (!(length_of_two_points % mid))
				--count_of_newpoints;
		}
		if (count_of_newpoints<= number_of_newpoints)
			end = mid - 1;
		else
			start = mid + 1;
	}
	result = start;
}

void preset(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void output(){ std::cout << result; }

int main(){
	preset();
	input();
	solution();
	output();
}
