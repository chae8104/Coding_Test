#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> vp;
    int answer = 0;
    
    for(int i = 0; i< N; i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    
    sort(vp.begin(), vp.end());
    priority_queue<int,vector<int>, greater<int>> pq;
    
    for(int j = 0; j< N; j++){
        pq.push(vp[j].second);
        if(pq.size() > vp[j].first){
            pq.pop();
        }
    }
    
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }
    
    cout << answer << endl;
    
    return 0;
}