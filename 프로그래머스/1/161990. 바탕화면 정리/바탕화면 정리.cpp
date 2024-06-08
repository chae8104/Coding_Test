#include <string>
#include <vector>
#include <algorithm>



using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minx = 2147483647, miny = 2147483647, maxx = 0, maxy = 0;
    for(int i = 0; i < wallpaper.size(); i++){
        for(int j = 0; j < wallpaper[i].size(); j++){
            if(wallpaper[i][j] == '#'){
                minx = min(minx, i);
                maxx = max(maxx, i);
                miny = min(miny, j);
                maxy = max(maxy, j);
            }
        }
    }
    
    answer.push_back(minx);
    answer.push_back(miny);
    answer.push_back(maxx + 1);
    answer.push_back(maxy + 1);
    return answer;
}
