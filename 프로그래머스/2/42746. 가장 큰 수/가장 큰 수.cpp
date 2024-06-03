#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b){
    return a+b > b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    
    for(int i = 0; i< numbers.size(); i++){
        str.push_back(to_string(numbers[i]));
    }
    
    //크기에 맞게 정렬
    sort(str.begin(), str.end(), compare);
    
    for(int i = 0; i< str.size(); i++){
        answer += str[i];
    }
    
    if(answer[0] == '0'){
        return "0";
    }
    
    return answer;
}