//  Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

class Solution {
public:

    int solve(vector<vector<char>>& mat, int i, int j, int &maxi){
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }

        int right = solve(mat, i, j+1, maxi);
        int down = solve(mat, i+1, j, maxi);
        int diagonal = solve(mat, i+1, j+1, maxi);

        if(mat[i][j] == '1'){
            int ans = 1 + min(right, min(down, diagonal));
            maxi = max(maxi, ans);
            return ans; 
        }else
            return 0;
    } 

    int solveMem(vector<vector<char>>& mat, int i, int j, int &maxi, vector<vector<int>> &dp){
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solveMem(mat, i, j+1, maxi, dp);
        int down = solveMem(mat, i+1, j, maxi, dp);
        int diagonal = solveMem(mat, i+1, j+1, maxi, dp);

        if(mat[i][j] == '1'){
            dp[i][j] = 1 + min(right, min(down, diagonal));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j]; 
        }else
            return 0;
    } 

    int solveTab(vector<vector<char>>& mat, int &maxi){
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int right = dp[i][j+1];
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];

            if(mat[i][j] == '1'){
                dp[i][j] = 1 + min(right, min(down, diagonal));
                maxi = max(maxi, dp[i][j]); 
            }else
                dp[i][j] = 0;
            }
        }

        return dp[0][0];

    }

    int solveSO(vector<vector<char>>& mat, int &maxi){
        int n = mat.size();
        int m = mat[0].size();

        vector<int>curr(m+1, 0);
        vector<int>next(m+1, 0);

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int right = curr[j+1];
                int down = next[j];
                int diagonal = next[j+1];

            if(mat[i][j] == '1'){
                curr[j] = 1 + min(right, min(down, diagonal));
                maxi = max(maxi, curr[j]); 
            }else
                curr[j] = 0;
            }

            next = curr;
        }

        return curr[0];

    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        //vector<vector<int>> dp(n, vector<int>(m, -1));
        solveSO(matrix, maxi);
        return maxi*maxi;
    }
};