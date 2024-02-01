#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> map1;
    for (int i = 0; i < want.size(); ++i) {
        map1[want[i]] = number[i];
    }

    map<string, int> map2;
    
    for (int i = 0; i < 10; ++i) {
        map2[discount[i]]++;
    }
    
    bool check = true;
    
    for (const auto& w : map1) {
        if (map2[w.first] != w.second) {
            check = false;
            break;
        }
    }
    
    if (check){
        answer++;
    }

    for (int i = 10; i < discount.size(); ++i) {
        map2[discount[i - 10]]--;
        map2[discount[i]]++;
        
        check = true;
        
        for (const auto& w : map1) {
            if (map2[w.first] != w.second) {
                check = false;
                break;
            }
        }
        if (check){
            answer++;
        }
    }

    return answer;
}
