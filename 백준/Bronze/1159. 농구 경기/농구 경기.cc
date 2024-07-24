#include <iostream>
#include <map>
using namespace std;


int main(){
    int count;
    cin >> count;
    map<char, int> mm;
    string answer;
    
    for(int i =0; i<count; i++){
        string s;
        cin >> s;
        mm[s[0]]++;
    }
    
    for(char c = 'a'; c<='z'; c++){
        if(mm[c]>4){
            answer = answer + c;
        }
    }
    if(answer.size() >0){
        cout<< answer;
    }
    else{
        cout<< "PREDAJA";
    }
    return 0;
}