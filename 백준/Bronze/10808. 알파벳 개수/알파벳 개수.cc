#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    string s;
    cin >> s;
    
    map<char, int> mm;
    
    for(char c : s){
        mm[c]++;
    }
    
    for(char c = 'a'; c<='z'; c++){
        cout<< mm[c] << " ";
    }
    
    return 0;
}