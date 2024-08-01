#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> jewels(N); // 보석의 무게와 가치
    vector<int> bags(K); // 가방의 최대 무게

    // 보석 정보 입력
    for (int i = 0; i < N; i++) {
        cin >> jewels[i].first >> jewels[i].second; // {무게, 가치}
    }

    // 가방 정보 입력
    for (int i = 0; i < K; i++) {
        cin >> bags[i];
    }
    
    // 보석과 가방 정렬
    sort(jewels.begin(), jewels.end()); // 무게 기준으로 정렬
    sort(bags.begin(), bags.end()); // 가방 무게 기준으로 정렬
    
    priority_queue<int> pq; // 보석의 가치를 저장하는 최대 힙
    long answer = 0; // 최대 가격 합계
    int jewel_index = 0; // 보석 인덱스

    // 각 가방에 대해 처리
    for (int i = 0; i < K; i++) {
        // 현재 가방의 무게에 맞는 보석을 큐에 추가
        while (jewel_index < N && jewels[jewel_index].first <= bags[i]) {
            pq.push(jewels[jewel_index].second); // 보석의 가치를 큐에 추가
            jewel_index++;
        }
        
        // 최대 가치를 가진 보석을 선택
        if (!pq.empty()) {
            answer += pq.top(); // 가장 높은 가치의 보석을 선택
            pq.pop(); // 선택한 보석은 제거
        }
    }

    cout << answer << endl; // 최종 결과 출력
    return 0;
}
