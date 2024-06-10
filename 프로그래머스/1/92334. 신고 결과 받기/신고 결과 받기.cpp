#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0); //사용자가 받은 결과를 저장할 벡터
    map<string, int> report_count; //사용자가 신고 당한 횟수를 저장할 맵
    map<string, set<string>> report_map; //사용자가 신고한 사람들을 저장할 맵
    
    for(string r : report) {
        int space_idx = r.find(' ');
        //find를 통해 찾기
        string from = r.substr(0, space_idx);
        string to = r.substr(space_idx + 1);

        // 한 사람의 동일한 유저에 대한 중복 신고를 막기 위해 set을 사용
        if(report_map[from].find(to) == report_map[from].end()) {
            report_map[from].insert(to);
            report_count[to]++;
        }
    }

    // 정지된 사용자들을 확인하고 결과를 계산
    for(int i = 0; i < id_list.size(); i++) {
        for(string to : report_map[id_list[i]]) {
            if(report_count[to] >= k) {
                answer[i]++;
            }
        }
    }

    return answer;
}
