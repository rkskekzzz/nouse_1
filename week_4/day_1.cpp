#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> array;

void input(){
	std::cin >> N;
	array.resize(N);
	for (int i = 0 ; i < N ; i++){
		std::cin >> array[i];
	}
	std::sort(array, array+N);
}

void solution(){

}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	input();
	solution();
	return 0;
}
