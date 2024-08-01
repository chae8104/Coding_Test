#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string s, era;
    cin >> s >> era;
    string answer = "";
    for(char a : s){
        answer += a;
        if(answer.size() >= era.size() && answer.substr(answer.size() - era.size(), era.size()) == era){
            answer.erase(answer.end() - era.size(), answer.end());
        }
        //answer의 가장 끝 부분을 잘라서 erase해야할 문자와 같다면 지운다.
    }
    
    if(answer.size() == 0){
        cout << "FRULA" << endl;
    }
    
    else{
        cout << answer << endl;
    }
    
    return 0;
    
}