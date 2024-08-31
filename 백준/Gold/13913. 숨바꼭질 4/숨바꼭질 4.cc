#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int max_n = 200004;
int visited[max_n], pr[max_n], n, k, ret, here, cnt, next;

vector<int> v; 
queue<int> q;  
int main() { 
    cin >> n >> k; 
    visited[n] = 1; 
    q.push(n);  
    while(q.size()){
        here = q.front();  
        q.pop();
        if(here == k){
            ret = visited[k]; 
            break;
        }
        //큐에 넣기전 체크
		for(int next : {here + 1, here - 1, here * 2}){
            if(next >= max_n || next < 0 || visited[next]) continue;  
            visited[next] = visited[here] + 1; 
            pr[next] = here; 
            q.push(next); 
		} 
    }   
    for(int i = k; i != n; i = pr[i]){
        v.push_back(i);
    }
    v.push_back(n);
    cout << ret - 1<< endl;
    reverse(v.begin(), v.end());
	for(int i : v) cout << i << ' '; 
    return 0;
}