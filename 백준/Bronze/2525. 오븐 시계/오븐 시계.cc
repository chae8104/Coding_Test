#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int min, sec;
    cin >> min >> sec;
    
    int extra;
    cin >> extra;
    
    int extra_min = extra / 60;
    int extra_sec = extra % 60;
    if(extra_sec + sec > 59){
        cout << (min + extra_min + 1)%24 << " " << (sec + extra_sec) % 60 << endl;
    }
    else{
        cout << (min + extra_min)%24 << " " << extra_sec + sec << endl;
    }
    
    return 0;
}