#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i =0; i< prices.size(); i++){
        int now = 0;
        for(int j =i+1; j<prices.size(); j++){
            now++;
            if(prices[i]>prices[j]){
                break;
            }
        }
        answer.push_back(now);
    }
    return answer;
}