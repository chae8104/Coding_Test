#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//검수 안하는 시간도 있다.

int main(){
    int cow;
    cin >> cow;
    vector<pair<int, int>> v;
    
    for(int i = 0; i< cow; i++){
        int start, end;
        cin >> start >> end;
        pair<int, int> pp = {start,end};
        v.push_back(pp);
    }
    
    sort(v.begin(), v.end());
    int answer = v[0].first;
    
    for(int i =0; i< v.size(); i++){
        if(v[i].first > answer){
            answer = v[i].first;
        }
        answer += v[i].second;
    }
    
    
    cout << answer << endl;
    
    return 0;
}