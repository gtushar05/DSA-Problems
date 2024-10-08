// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:

    int solveMem(int n, vector<int>& dp){
       if(n == 0 || n == 1){
        return 1;
       } 
       
       if(dp[n] != -1){
        return dp[n];
       }

       dp[n] = solveMem(n-1, dp) + solveMem(n-2, dp);
       return dp[n];
    }

    int solveTab(int n){

       vector<int> dp(n+1, 0);

       dp[0] = 1;
       dp[1] = 1;

       
       for(int i = 2; i <= n; i++){
       dp[i] = dp[i-1] + dp[i-2];
       }
       return dp[n];
    }

    int solveSO(int n){

       int prev1 = 1;
       int prev2 = 1; 
       
       int curr = prev2;;
       
       for(int i = 2; i <= n; i++){
       curr = prev1 + prev2;

       prev1 = prev2;
       prev2 = curr;
       }
       return curr;
    }

    int climbStairs(int n){
      // vector<int>dp(n+1, -1);
       int ans = solveSO(n); 
       return ans;
    }
};