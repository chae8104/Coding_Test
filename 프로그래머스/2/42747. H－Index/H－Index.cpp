#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int &a, int& b){
    return a<b;
}

int solution(vector<int> citations) {
    int answer = 0;
    vector<pair<int, int>> p(citations.size());
    //citations.size만큼 크기 할당해서 초기화 할 것
    
    for(int i = 0; i < citations.size(); i++) {
        p[i].first = citations[i];
        p[i].second = 0;
        //citations 순회하며 pair를 이용해 각 인용횟수보다 높으면 second에 1씩 더하기
        for(int j = 0; j < citations.size(); j++) {
            if(citations[j] >= p[i].first) {
                p[i].second++;
            }
        }
    }
    
    sort(p.begin(), p.end(), greater<pair<int, int>>());
    //p.first를 기준으로 정렬해주기
    
    //p[i].first와 p[i].second 둘 다 그 숫자보다 높으면 
    for(int i = 0; i < p.size(); i++) {
        if(p[i].first >= i + 1 && p[i].second >= i + 1) {
            answer = i + 1;
        }
    }
    
    return answer;
}

//33446
//22445


//10101
//21212
//21312
//31423
//31524
//12345

//p.second로 각 기준마다 최대 몇번인지 체크