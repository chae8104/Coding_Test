#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    
    for(int i = 0; i< commands.size(); i++){
        int x = commands[i][0];
        int y = commands[i][1];
        int z = commands[i][2];
        vector<int> save;
        for(int j = x - 1; j< y; j++){
            save.push_back(array[j]);
        }
        sort(save.begin(), save.end());
        answer.push_back(save[z - 1]);
    }
    //x는 시작 인덱스 y는 엔드 인덱스 z는 몇 번째 원소인지 체크
    
    
    return answer;
}