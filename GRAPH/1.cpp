#include <bits/stdc++.h> 
using namespace std;

long countWaysToMakeChange(int *a, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long>(value+1, 0));
    for(int j = 0; j<=value; j++){
        dp[0][j] = j%a[0] == 0 ? 1 : 0 ;
    }

    for(int i = 1; i<n; i++){
        for(int j=0; j<= value; j++){
            for(int coins = 0; coins * a[i] <= j; coins += a[i]){
                dp[i][j] += dp[i-1][j - coins];
            }
        }
    }
    return dp[n-1][value];

}


int main(){

}