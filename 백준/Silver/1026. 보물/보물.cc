#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int num;
    cin >> num;
    vector<int> a;
    vector<int> b;
    
    for(int i = 0; i< num; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i< num; i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int answer = 0;
    
    for(int i =0; i< num; i++){
        answer += a[i]*b[num - i - 1];
    }
    
    
    cout <<answer <<endl;
    
    return 0;
}