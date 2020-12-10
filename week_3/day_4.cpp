#include <iostream>
#include <vector>

int N, M;
int start, end, MAX;
int mid, ans;
std::vector <std::vector<std::pair <int, int> > > bridge_weight;
std::vector <bool> visited;

bool dfs(int st)
{
	if (visited[st])
		return false;
	visited[st] = true;
	if (st == end)
		return true;
	for(size_t i = 0; i < bridge_weight[st].size() ; i++)
		if (bridge_weight[st][i].second >= mid && dfs(bridge_weight[st][i].first))
			return true;
	return false;
}

void binary_search(int min, int max)
{
	while (min <= max){
		mid = (min + max) / 2;
		visited = std::vector<bool>(N, false);
		if (dfs(start))
			min = mid + 1;
		else
			max = mid - 1;
	}
	ans = max;
}

void preset(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main()
{
	preset();
	int a, b, c;

	std::cin >> N >> M;
	bridge_weight.resize(N + 1);
	for(int i = 0 ; i < M ; i++)
	{
		std::cin >> a >> b >> c;
		MAX = std::max(MAX, c);
		bridge_weight[a].push_back(std::make_pair(b, c));
		bridge_weight[b].push_back(std::make_pair(a, c));
	}
	std::cin >> start >> end;
	binary_search(0, MAX);
	std::cout << ans;
	return (0);
}
