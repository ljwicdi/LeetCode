class Solution {
public:
    int uniquePaths(int m, int n) {
        // ~ 4 ^ 100 x 
        int row = m;
        int col = n;
        int dp[row][col];
        
        for (int i = 0; i < col; i++) {
            dp[0][i] = 1;
        }
        
        for (int i = 0; i < row; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        
        return dp[row - 1][col - 1];
    }
};