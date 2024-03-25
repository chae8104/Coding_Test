#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    
    for (int i = 0; i < progresses.size(); i++) {
        int day = ceil((100.0 - progresses[i]) / speeds[i]);
        days.push(day);
    }
    //1번예시에서 days = [7,4,9]
    
    while (!days.empty()) {
        int deploy = days.front();
        //제일 앞에 있는 것을 기준으로 한다
        int count = 0;
        while (!days.empty() && days.front() <= deploy) {
            //제일 앞에 있는 것보다 작다면 계속 pop해주고 count++
            days.pop();
            count++;
        }
        
        answer.push_back(count);
    }

    return answer;
}
