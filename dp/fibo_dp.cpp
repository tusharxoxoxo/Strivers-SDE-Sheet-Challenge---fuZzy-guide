#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int f(int n, vector<int>&dp){
    if(n <= 1) return n;
    if(dp[n]!= -1) return dp[n];
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}
int tabulation(int n, vector<int>&dp){
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i < n; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
int space_optimisation(int n, vector<int>&dp){
    int prev = 1;
    int prev2 = 0;

    for(int i = 2; i < n; ++i){
        int curr = prev + prev2;

        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main(){
    int n = 6;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp);
    cout << endl;
    cout << tabulation(n, dp);
    cout << endl;
    cout << space_optimisation(n, dp);
}
