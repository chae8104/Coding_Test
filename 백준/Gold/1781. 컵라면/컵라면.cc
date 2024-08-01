#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int case1;

int main(){
    cin >> case1;
    vector<pair<int,int>> v;
    for(int i =0; i< case1; i++){
        int x,y;
        cin >> x >> y;
        pair<int,int> pp = {x,y};
        v.push_back(pp);
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    sort(v.begin(), v.end());
    
    for(int j =0; j< case1; j++){
        pq.push(v[j].second);
        if(pq.size() > v[j].first){
            pq.pop();
        }
    }
    int answer = 0;
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }
    
    cout << answer << endl;
    
    return 0;
}