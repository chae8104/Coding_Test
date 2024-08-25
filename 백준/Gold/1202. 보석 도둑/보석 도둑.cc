#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

//가방과 보석
//가방무게를 초과해서 넣을 순 없다.
//

int main(){
    int N, K;
    cin >> N >> K;
    
    vector<int> bag;
    vector<pair<int, int>> v;
    
    for(int i =0; i< N; i++){
        int M,V;
        cin >> M >> V;
        v.push_back({M,V});
    }
    
    for(int i =0; i< K; i++){
        int x;
        cin >> x;
        bag.push_back(x);
    }
    
    //크기 순으로 정렬 후
    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());
    
    int count = 0;
    long answer = 0;
    priority_queue<int> pq;
    
    
    for(int i =0; i< K; i++){
        //가방마다 넣기
        while(count < N && bag[i] >= v[count].first){
            //가방무게보다 보석무게(v.first)가 작다면
            //pq에 보석가격(v.second)을 push
            pq.push(v[count].second);
            //그리고 count++
            //count는 보석가방의 vector위치를 정하기위해
            count++;
        }
        
        if(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
    }
    
    cout << answer << endl;
    
    return 0;
}