// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

class Solution {
public:

    int solve(vector<int>& cost, int n){
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }
        int ans = cost[n] + min(solve(cost, n-2), solve(cost, n-1));
        return ans;
    }

    int solveMem(vector<int>& cost, int n, vector<int>& dp){
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }

        if(dp[n] != -1){
            return dp[n];
        }
        
        dp[n] = cost[n] + min(solveMem(cost, n-2, dp), solveMem(cost, n-1, dp));
        return dp[n];
    }

    int solveTab(vector<int>& cost, int n, vector<int>& dp){
        
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        
        return min(dp[n-1], dp[n-2]);
    }

    int solveSO(vector<int>& cost, int n){
        
        int prev1 = cost[0];
        int prev2 = cost[1];
        int curr = 0;
        for(int i = 2; i < n; i++){
            curr = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }

        int ans = min(prev2, prev1);
        
        return ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        //vector<int> dp(n+1, -1);
        int ans  = solveSO(cost, n);
        return ans;
    }
};