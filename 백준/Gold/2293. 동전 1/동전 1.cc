#include <cstdio>
#include <vector> 
#include <iostream>
using namespace std; 

int dp[10001];
int n, k, temp;

int main(){
    cin >> n >> k;
    
    dp[0] = 1; 
    
	for(int i = 1; i <= n; i++){
        cin >> temp;
        
        for(int j = temp; j <= k; j++){  
            dp[j] += dp[j - temp]; 
        }
    }
    
    cout << dp[k] << endl;
    
    return 0;
}