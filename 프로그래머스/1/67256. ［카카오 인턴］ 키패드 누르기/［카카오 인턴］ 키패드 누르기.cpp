#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    map<int, pair<int, int>> mm = {
        {1, {0, 0}}, {2, {0, 1}}, {3, {0, 2}},
        {4, {1, 0}}, {5, {1, 1}}, {6, {1, 2}},
        {7, {2, 0}}, {8, {2, 1}}, {9, {2, 2}},
        {0, {3, 1}}
    };
    
    pair<int, int> left = {3, 0};
    pair<int, int> right = {3, 2};
    for(int c : numbers){
        if(c == 1 || c == 4 || c == 7){
            answer += "L";
            left = mm[c];
        }
        else if(c == 3 || c == 6 || c == 9){
            answer += "R";
            right = mm[c];
        }
        else {
            pair<int, int> mid = mm[c];
            
            int Ldist = abs(mid.first - left.first) + abs(mid.second - left.second);
            int Rdist = abs(mid.first - right.first) + abs(mid.second - right.second);
            if(Ldist < Rdist || (Ldist == Rdist && hand == "left")){
                answer += "L";
                left = mm[c];
            }
            else if(Ldist > Rdist || (Ldist == Rdist && hand == "right")){
                answer += "R";
                right = mm[c];
            }
        }
    }
    return answer;
}
