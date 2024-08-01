#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int a,b;
int answer;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;



int main(){
    int n;
    cin >> n;
    
    for(int i =0; i< n; i++){
        cin >>a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    //정렬하는 이유 : 날짜가 가장 임박한 것 부터 처리해야한다.
    //
    for(int i =0; i<n; i++)
    {
        pq.push(v[i].second);
        //
        if(pq.size()> v[i].first){
            pq.pop();
        }
    }
    while(pq.size()){
        answer += pq.top();
        pq.pop();
    }
    cout << answer << endl;
}