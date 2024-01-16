#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> count;
    char last = 0;
    
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        
        if (i >= 1 && word.front() != last || count.find(word) != count.end())
        {
            //첫 번째 단어는 마지막 글자와 일치하는지 체크하면 안됨
            return {(i % n) +1, (i / n) +1};
        }
        //몇 번째 사람인지 찾기 위해 i%n을 통해 체크
        //몇 번째 차례인지 찾기 위해 i/n을 통해 체크

        last = word.back();
        
        count.insert(word);
    }
    
    return {0, 0};
}