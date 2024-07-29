#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool isBalanced(const string& s) {
    stack<char> st;
    map<char, char> matching;
    matching[')'] = '(';
    matching[']'] = '[';

    for (char c : s) {
        if (c == '(' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == ']') {
            if (!st.empty() && st.top() == matching[c]) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string s;
    while (true) {
        getline(cin, s);
        if (s == ".") break;

        if (isBalanced(s)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
