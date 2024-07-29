#include <iostream>
#include <map>
using namespace std;

// 모음을 나타내는 map
map<char, int> vowel = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};

// 1번 조건: 모음을 반드시 포함할 것
bool vowel_check(const string &s) {
    for (char c : s) {
        if (vowel[c] == 1) {
            return true;
        }
    }
    return false;
}

// 2번 조건: 모음이 3개 혹은 자음이 3개 연속으로 오면 안된다.
bool three_check(const string &s) {
    int count1 = 0;
    int count2 = 0;
    for (char c : s) {
        if (vowel[c] == 1) {
            count2 = 0;
            count1++;
            if (count1 > 2) {
                return false;
            }
        } else {
            count1 = 0;
            count2++;
            if (count2 > 2) {
                return false;
            }
        }
    }
    return true;
}

// 3번 조건: 같은 글자가 연속으로 오면 안된다, 단 ee랑 oo는 가능
bool same_check(const string &s) {
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o') {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    while (cin >> s) {
        if (s == "end") {
            break;
        }
        if (vowel_check(s) && three_check(s) && same_check(s)) {
            cout << "<" << s << "> is acceptable." << endl;
        } 
        else {
            cout << "<" << s << "> is not acceptable." << endl;
        }
    }
    return 0;
}
