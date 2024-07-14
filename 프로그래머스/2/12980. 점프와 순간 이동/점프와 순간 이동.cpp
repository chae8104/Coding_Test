#include <iostream>
using namespace std;

//dp로 풀기

int solution(int n)
{
    int ans = 0;
    while(n>0){
        if(n%2 == 1){
            ans++;
        }
        n= n/2;
    }
    

    return ans;
}