// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:

int solve(vector<int>& nums, int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }

    int include = nums[n] + solve(nums, n-2);
    int exclude = solve(nums, n-1);

    return max(include, exclude);
}

int solveMem(vector<int>& nums, int n, vector<int> &dp){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int include = nums[n] + solveMem(nums, n-2, dp);
    int exclude = solveMem(nums, n-1, dp);

    dp[n] = max(include, exclude);

    return dp[n];
}

int solveTab(vector<int>& nums){
    
    int n = nums.size();

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    if(n > 1)
        dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i <= n-1; i++){

    int include = nums[i] + dp[i-2];
    int exclude = dp[i-1];

    dp[i] = max(include, exclude);
    }

    return dp[n-1];
}

    int solveSO(vector<int>& nums){
        int n = nums.size();

        int prev1 = 0;
        int prev2 = nums[0];
        
        for(int i = 1; i < n; i++){
            int include = prev1 + nums[i];
            int exclude = prev2 + 0;
            
            int ans = max(include, exclude);

            prev1 = prev2;
            prev2 = ans;
        }

        return prev2;

    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        vector<int> first, second;

        for(int i = 0; i < n; i++){
            if(i != n-1){
            first.push_back(nums[i]);
            }
            if(i != 0){
                second.push_back(nums[i]);
            }
            
        }

        //vector<int>dp1(n-1, -1);
        //vector<int>dp2(n-1, -1);

        int ans = max(solveSO(first), solveSO(second));
        return ans;
    }
};