#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

//스택을 이용해 풀기 새로 들어오는 것과 스택의 top이 같다면 top을 빼고 새로 들어오는 것은 push안함
//스택의 top과 다르다면 push

int main(){
    int num;
    cin >> num;
    string s;
    int answer;
    
    for(int i =0; i<num; i++){
        cin >> s;
        stack<char> st;
        for(char a: s){
            if(st.size() && st.top() == a){
                st.pop();
            }
            else{
                st.push(a);
            }
        }
        if(st.size() == 0){
            answer++;
        }
    }
    
    cout<< answer<<endl;
    
    return 0;
}