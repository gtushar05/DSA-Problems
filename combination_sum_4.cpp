// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

// The test cases are generated so that the answer can fit in a 32-bit integer.

// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.

class Solution {
public:

    int solve(vector<int>& nums, int target){
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += solve(nums, target - nums[i]);
        }
        return sum;
    }

    int solvemem(vector<int>& nums, int target, vector<int> &dp){
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        int n = nums.size();
        
        if(dp[target] != -1){
            return dp[target];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += solvemem(nums, target - nums[i], dp);
        }
        dp[target] = ans;
        return dp[target];
    }

    int solveTab(vector<int>& nums, int target){
        
        vector<int>dp(target+1, 0);

        dp[0] = 1;
        int n = nums.size();
        
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < n; j++){
                if((i - nums[j]) >= 0)
                    dp[i] += dp[i-nums[j]];
            }
        }

        return dp[target];

    }

    int combinationSum4(vector<int>& nums, int target) {

        vector<int>dp(target+1, -1);

        int ans = solvemem(nums, target, dp);
        return ans;      
    }
};