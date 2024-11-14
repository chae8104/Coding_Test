#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        stack<char> st;
        
        bool is = true;
        
        for(char c : s){
            if(c == '('){
                st.push(c);
            } else if(c == ')'){
                if(st.empty()){
                    is = false;
                    break;
                } else {
                    st.pop();
                }
            }
        }
        
        if(!st.empty()){
            is = false;
        }
        
        cout << (is ? "YES" : "NO") << endl;
    }
    
    return 0;
}
