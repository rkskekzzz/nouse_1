#include <iostream>
#include <algorithm>

int N, M, max;
long long lines[100001];


void input() {
	std::cin >> N >> M;
	for (int i =0 ; i < N ; i++){
		std::cin >> lines[i];
		if (max < lines[i])
			max = lines[i];
	}
}

long long count_finish(long long mid){
	long long count = 0;
	for (int i = 0 ; i < N ; i++){
		count += mid / lines[i];
	}
	return count;
}

void solution() {
	long long start = 1, mid, end, count;
	long long result;

	end = max * M;
	while (start <= end){
		mid = (start + end) / 2;
		count = count_finish(mid);
		if (count >= M){
			end = mid - 1;
			if (result > mid)
				result = mid;
		}
		else {
			start = mid + 1;
		}
	}
	std::cout << result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	input();
	solution();
	return 0;
}

