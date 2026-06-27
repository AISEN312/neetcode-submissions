class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()||obstacleGrid[0][0] ==  1){
              return 0;
        }
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<int> dp(cols,0);
        dp[0] = 1;
        for(int i =0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;                }
else{
    if(j>0){ 
        dp[j] += dp[j-1];
    }
}
            }
        }
        return dp[cols-1];
    }
};