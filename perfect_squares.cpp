// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

#include<limits.h>
class Solution {
public:

    int solve(int n){
        if(n == 0){
            return 0;
        }
        int ans = n;
        for(int i = 1; i <= (int)sqrt(n); i++){
            if((n-i) >= 0)
                ans = min(ans, 1 + solve(n-(i*i)));
        }
        return ans;
    }

    int solvemem(int n, vector<int> &dp){
        if(n == 0){
            return 0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }

        int ans = n;
        for(int i = 1; i <= (int)sqrt(n); i++){
            if((n-i) >= 0)
                ans = min(ans, 1 + solvemem(n - (i*i), dp));
        }
        dp[n] = ans;
        return dp[n];
    }

    int solveTab(int n){
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j*j <= n; j++){
                if(i - j*j >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }
        return dp[n];
    }
  
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        int ans = solveTab(n);
        return ans;
    }
};