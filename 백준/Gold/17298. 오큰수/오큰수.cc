#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    vector<int> answer(N, -1);
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    stack<int> st;
    
    for(int i = 0; i < N; i++) {
        while(!st.empty() && v[st.top()] < v[i]) {
            answer[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    
    for(int i = 0; i < N; i++) {
        cout << answer[i] << " ";
    }
    return 0;
    
}