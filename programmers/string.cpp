#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int number_of_digits(int n)
{
    if (n == 0)
        return 0;
    if (n + 1 < 10)
        return 1;
    return floor(log10(n + 1)+1);
}


int solution(string s) {
    int answer = s.length();
	string temp;
	for(int i = 1 ; i <= s.length() / 2 ; i++) {
        int loopResult = s.length();
        int flag = 0;
		for (int pos = 0; pos < s.length() ; pos += i) {
			if (temp.length() == 0 || temp != s.substr(pos, i)) {
				temp = s.substr(pos, i);
                loopResult += number_of_digits(flag);
				flag = 0;
			} else {
				loopResult -= i;
				flag += 1;
			}
		}
        loopResult += number_of_digits(flag);
        answer = min(loopResult, answer);
	}
    cout << answer;
    return answer;
}
