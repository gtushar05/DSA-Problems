// A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

// Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

// Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

// Example 1:

// Input: satisfaction = [-1,-8,0,5,-9]
// Output: 14
// Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
// Each dish is prepared in one unit of time.

class Solution {
public:

    int solve(vector<int> &sat, int index, int time){
        if(index == sat.size()){
            return 0;
        }
        int include = sat[index]*(time+1) + solve(sat, index+1, time+1);
        int exclude = solve(sat, index+1, time);
        return max(include, exclude);
    }

    int solveMem(vector<int> &sat, int index, int time, vector<vector<int>> &dp){
        if(index == sat.size()){
            return 0;
        }
        if(dp[index][time] != -1){
            return dp[index][time];
        }
        int include = sat[index]*(time+1) + solveMem(sat, index+1, time+1, dp);
        int exclude = solveMem(sat, index+1, time, dp);
        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }

    int solveTab(vector<int> &sat){

        int n = sat.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int index = n-1; index >= 0; index--){
            for(int time = index; time >= 0; time--){
                int include = sat[index]*(time+1) + dp[index+1][time+1] ;
                int exclude = dp[index+1][time];
                dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int solveSO(vector<int> &sat){

        int n = sat.size();
        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);

        for(int index = n-1; index >= 0; index--){
            for(int time = index; time >= 0; time--){
                int include = sat[index]*(time+1) + next[time+1] ;
                int exclude = next[time];
                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {

        int n = satisfaction.size();
        //vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        sort (satisfaction.begin(), satisfaction.end());

        return solveSO(satisfaction);
    }
};