#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>


using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    unordered_map<string, int> idx_map;
    for(int i = 0; i < id_list.size() ; ++i) 
        idx_map[id_list[i]] = i;
    
    unordered_map<string, set<string>> report_map;
    for (string content: report) {
        string send_id = content.substr(0, content.find(" "));
        string reported_id = content.substr(content.find(" ") + 1);
        report_map[reported_id].insert(send_id);
    }
    for (auto it: report_map) {
        if (it.second.size() >= k) {
            for (auto set_it: it.second) {    
                answer[idx_map[set_it]] += 1;
            }
        }
    }
    return answer;
}
