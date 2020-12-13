#include <iostream>
#include <vector>
#include <algorithm>

int N, M, L;
int result;
std::vector<int> array;

void input(){
	int i;
	std::cin >> N >> M >> L;
	array.resize(N + 2);
	array[0] = 0;
	for (i = 1 ; i <= N ; i++)
		std::cin >> array[i];
	array[i] = L;
	std::sort(array.begin(), array.end());
}

void solution(){
	int start = 1;
	int mid;
	int end = L - 1;

	while (start <= end){
		mid = (start + end) / 2;

		int count = 0;
		for(int i = 1 ; i < N + 2 ; i++){
			int length = array[i] - array[i - 1];
			count += length / mid;
			if (!(length % mid))
				--count;
		}
		if (count <= M)
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
