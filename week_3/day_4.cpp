#include <iostream>

int N, M;
int island[10001][10001];
int factory1, factory2;

void input(){
	int A, B, tmp;

	std::cin >> N >> M;
	for (int i = 0 ; i < M ; i++){
		std::cin >> A >> B;
		std::cin >> tmp;
		if (island[A][B] < tmp){
			island[A][B] = island[B][A] = tmp;
		}

	}
	std::cin >> factory1 >> factory2;
}

void dfs(int i, int j){
	if (i = )
	dfs(j, i);
}

void solution(){
	dfs(factory1, 0);
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
