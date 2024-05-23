#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    // 오름차순으로 정렬한다
    // 어떤 번호가 다른 번호의 접두어인 경우에 false이므로 vector를 순회하며
    // phone_book의 i번째의 길이만큼 phone_book i+1번째 항목의 접두를 substr하여
    // 비교한 후에 같다면 false를 return
    for (int i = 0; i < phone_book.size() - 1; ++i) {
        if (phone_book[i + 1].substr(0, phone_book[i].size()) == phone_book[i]) {
            return false;
        }
    }
    
    return true;
}
