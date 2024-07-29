#include <iostream>
#include <stack>

using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    
    for (int i = 0; i < test_case; i++) {
        string s;
        cin >> s;
        stack<char> st;
        bool isValid = true;
        
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    isValid = false;
                    break;
                }
            }
        }
        
        if (isValid && st.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    
    return 0;
}