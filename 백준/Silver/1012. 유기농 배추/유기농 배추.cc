#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int test_case, M, N, K;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int start_x, int start_y, vector<vector<int>> &v, vector<vector<int>> &visited){
    visited[start_x][start_y] = 1;
    for(int i = 0; i< 4; i++){
        int nx = start_x + dx[i];
        int ny = start_y + dy[i];
        if(nx >=0 && ny >= 0 && nx < M && ny < N && v[nx][ny] == 1 && visited[nx][ny] != 1){
            dfs(nx,ny,v,visited);
        }
    }
}

int main(){
    cin >> test_case;
    for(int i =0; i< test_case; i++){
        cin >>M >> N >> K;
        vector<vector<int>> v(M, vector<int> (N,0));
        vector<vector<int>> visited(M, vector<int> (N,0));
        for(int j =0; j< K; j++){
            int a,b;
            cin >> a >> b;
            v[a][b] = 1;
        }
        int count = 0;
        for(int x = 0; x < M; x++){
            for(int y = 0; y < N; y++){
                if(v[x][y] == 1 && visited[x][y] != 1){
                    dfs(x,y,v,visited);
                    count ++;
                }
            }
        }
        cout << count << endl;
    }
    
    return 0;
}