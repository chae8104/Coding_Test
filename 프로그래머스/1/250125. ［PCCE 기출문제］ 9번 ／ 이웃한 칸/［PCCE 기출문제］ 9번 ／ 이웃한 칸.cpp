#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    
    int x = board.size();
    int y = board[0].size();
    
    for(int i = 0; i < 4; i++) {
        int hh = h + dx[i];
        int ww = w + dy[i];
        if(hh >= 0 && hh < x && ww >= 0 && ww < y) {
            if(board[hh][ww] == board[h][w]) {
                answer++;
            }
        }
    }
    return answer;
}