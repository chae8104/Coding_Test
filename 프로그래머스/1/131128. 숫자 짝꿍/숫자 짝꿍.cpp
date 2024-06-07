#include <string>
#include <map>

using namespace std;

string solution(string X, string Y) {
    map<char, int> countX;
    map<char, int> countY;

    for (char c : X) {
        countX[c]++;
    }
    for (char c : Y) {
        countY[c]++;
    }

    string answer = "";

    for (char c = '9'; c >= '0'; c--) {
        if (countX[c] > 0 && countY[c] > 0) {
            int commonCount = min(countX[c], countY[c]);
            answer += string(commonCount, c);
        }
    }

    if (answer.empty()) {
        return "-1";
    }

    if (answer[0] == '0') {
        return "0";
    }

    return answer;
}
