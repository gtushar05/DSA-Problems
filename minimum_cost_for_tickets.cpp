// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.

class Solution {
public:

    int solveMem(int n, vector<int>& days, vector<int>& cost, int index, vector<int> &dp){

        if(index >= n){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int option1 = cost[0] + solveMem(n, days, cost, index + 1, dp);


        int i;
        for( i = index; i < n && days[i] < (days[index]+7); i++);
        int option2 = cost[1] + solveMem(n, days, cost, i, dp);

        for(i = index; i < n && days[i] < days[index]+30; i++);
        int option3 = cost[2] + solveMem(n, days, cost, i, dp);
        
        dp[index] = min(option1, min(option2, option3));

        return dp[index];

    }

    int solveTab(int n, vector<int>& days, vector<int>& cost){

        vector<int> dp(n+1, INT_MAX);

        dp[n] = 0;

        for(int k = n-1; k >= 0; k--){

        int option1 = cost[0] + dp[k+1];


        int i;
        for( i = k; i < n && days[i] < (days[k]+7); i++);
        int option2 = cost[1] + dp[i];

        for(i = k; i < n && days[i] < days[k]+30; i++);
        int option3 = cost[2] + dp[i];
        
        dp[k] = min(option1, min(option2, option3));
        
        }
        
        return dp[0];

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1, -1);
        int ans = solveTab(n, days, costs);
        return ans;
    }
};