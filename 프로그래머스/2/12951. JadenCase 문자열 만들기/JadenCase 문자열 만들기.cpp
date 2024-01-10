#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int size = s.size();
    bool count = true;

    for (int i = 0; i < size; i++) {
        if (s[i] == ' ') {
            count = true;
            answer += ' ';
        } 
        
        else if (count && isalpha(s[i])) {
            answer += toupper(s[i]);
            count = false;
        }
        
        else {
            answer += tolower(s[i]);
            
            if (isdigit(s[i])) {
                count = false;
            }
        }
    }

    return answer;
}
