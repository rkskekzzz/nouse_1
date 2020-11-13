#include <iostream>
using namespace std;

int solution(void);

int main(void)
{
    cout << solution() << endl;
    return 0;
}

int count_days(int up_len, int down_len, int stick_hei)
{
    int idx;
    
    if (up_len == stick_hei)
        return 1;
    idx = (stick_hei - down_len) / (up_len - down_len);
    if ((stick_hei - down_len) % (up_len - down_len) != 0)
        ++idx;
    return idx;
}

int solution()
{
    int up_length, down_length, stick_height;
    
    cin >> up_length;
    cin >> down_length;
    cin >> stick_height;
    
    return count_days(up_length, down_length, stick_height);
}