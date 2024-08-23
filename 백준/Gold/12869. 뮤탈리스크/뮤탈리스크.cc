#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;

int dp[61][61][61], arr[3], n, visited[61][61][61];

//
int aa[6][3] = {
	{9, 3, 1}, 
	{9, 1, 3}, 
	{3, 1, 9}, 
	{3, 9, 1}, 
	{1, 3, 9}, 
	{1, 9, 3}
};

struct A{
    int a, b, c; 
};

queue<A> q; 

//큐에 push후 꺼낸다
//그리고 결승점 도달 시 break하도록 만들고 리턴 값으로 결과
//경우의 수 별로 여기선 aa의 경우지만 보통 상하좌우로 되는 경우가 대부분

int solve(int a, int b, int c){
    visited[a][b][c] = 1; 
    q.push({a, b, c}); 
    while(q.size()){
        int a = q.front().a; 
        int b = q.front().b; 
        int c = q.front().c; 
        q.pop();
        
        if(visited[0][0][0]) break;
        
        for(int i = 0; i < 6; i++){
            int na = max(0, a - aa[i][0]);
            int nb = max(0, b - aa[i][1]); 
            int nc = max(0, c - aa[i][2]); 
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;  
            q.push({na, nb, nc}); 
        }
    }
    return visited[0][0][0] - 1;   
}
int main() {
	cin >> n;
    
	for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
	cout << solve(arr[0], arr[1], arr[2]) << endl; 
    
    return 0;
}