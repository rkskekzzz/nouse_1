#include <string>
#include <vector>

using namespace std;



int solution(string s) {
    int answer = s.length();
	string temp;

	for(int i = 1 ; i < s.length() / 2 ; i++) {
		for (int pos = 0; pos < s.length() ; pos += i) {
			int flag = 0;
			if (temp.length() == 0 || temp != s.substr(pos, i)) {
				temp = s.substr(pos, i);
				flag = 0;
			} else {
				answer -= i + !flag;
				flag = 1;
			}
		}
	}
    return answer;
}
