#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;  

vector<int> num; 
vector<char> oper_str; 
int n, ret = -987654321;
string s;

int oper(char a, int b, int c){
    if(a == '+') {
        return b + c;
    }
    if(a == '-') {
        return b - c;
    }
    if(a == '*') {
        return b * c;
    }
}
//+ - * 계산

void go(int here, int _num){
    if(here == num.size() - 1){ 
        ret = max(ret, _num); 
        return;
    }  
    go(here + 1, oper(oper_str[here], _num, num[here + 1]));

    if(here + 2 <= num.size() - 1){
        int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]); 
        go(here + 2, oper(oper_str[here], _num, temp));  
    } 
    return;
}

int main(){
    cin >> n;  
    cin >> s; 
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            num.push_back(s[i] - '0');
        }
        else{ 
            oper_str.push_back(s[i]);
        }
    }
    
    go(0, num[0]);
    cout << ret << "\n";
    return 0;
}