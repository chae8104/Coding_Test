#include <iostream>

using namespace std;

int main(){
    int x;
    
    while(cin >> x){
        int i = 1;
        int count = 1;
        while(i % x != 0){
            i = (i * 10 + 1) % x;
            ++count;
        }
        cout << count << endl;
    }
    
    return 0;
}