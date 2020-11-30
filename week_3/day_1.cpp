#include <iostream>
#include <algorithm>

int n, ABpointer, CDpointer;
int A[4001];
int B[4001];
int C[4001];
int D[4001];
int AB[16000001];
int CD[16000001];

void set_array()
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			AB[ABpointer] = A[i] + B[j];
			CD[ABpointer] = C[i] + D[j];
			ABpointer++;
		}
	}
	CDpointer = ABpointer - 1;
	std::sort(AB, AB + ABpointer);
	std::sort(CD, CD + ABpointer);
}

void two_pointer()
{
	long long count = 0;
	int i = 0;

	while (i < ABpointer && CDpointer >= 0)
	{
		int ABsum = AB[i];
		int CDsum = CD[CDpointer];
		int ABcnt = 0;
		int CDcnt = 0;
		int ABCDsum = ABsum + CDsum;

		if (ABCDsum == 0)
		{
			while (i < ABpointer && ABsum == AB[i])
			{
				++i;
				++ABcnt;
			}
			while (CDpointer >= 0 && CDsum == CD[CDpointer])
			{
				--CDpointer;
				++CDcnt;
			}
			count += (long long)ABcnt * (long long)CDcnt;
		}
		else if(ABCDsum > 0)
			--CDpointer;
		else
			++i;
	}
	std::cout << count;
}

void solution()
{
	set_array();
	two_pointer();
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	solution();
	return 0;
}
