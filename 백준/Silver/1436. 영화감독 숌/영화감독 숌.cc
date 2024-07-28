#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;



int main(){
    int x;
    int count = 1;
    cin >> x;
    map<int, string> mm;
    int i = 0;
    while(count <= x){
        string s = to_string(i);
        if(s.find("666") != string::npos){
            mm[count] = s;
            count++;
        }
        i++;
    }
    cout << mm[x] << endl;
    
    return 0;
}