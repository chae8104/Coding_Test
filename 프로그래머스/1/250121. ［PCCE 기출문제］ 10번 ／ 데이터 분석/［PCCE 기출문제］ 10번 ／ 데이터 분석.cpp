#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//index 입력 받고 그걸 기준으로 정렬
bool compare(const vector<int>& a, const vector<int>& b, int sort_idx) {
    return a[sort_idx] < b[sort_idx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    map<string, int> mm;
    mm["code"] = 0;
    mm["date"] = 1;
    mm["maximum"] = 2;
    mm["remain"] = 3;

    vector<vector<int>> answer;
    
    for(int i = 0; i < data.size(); i++) {
        if(data[i][mm[ext]] < val_ext) {
            answer.push_back(data[i]);
        }
    }
    
    int sort_idx = mm[sort_by];
    
    sort(answer.begin(), answer.end(), [sort_idx](const vector<int>& a, const vector<int>& b) {
        return compare(a, b, sort_idx);
    });
    
    
    return answer;
}
