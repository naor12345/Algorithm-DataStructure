class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        int width = obstacleGrid[0].size();
        int height = obstacleGrid.size();
        
        bool obst = false;
        for(int i = 0; i<width; i++)
        {
            if(!obst) obst = (obstacleGrid[0][i] == 1);
            
            if(obst)
            {
                dp[0][i] = 0;
            }
            else
            {
                dp[0][i] = 1;                
            }
        }
        
        obst = false;
        for(int i = 0; i<height; i++)
        {
            if(!obst) obst = (obstacleGrid[i][0] == 1);
            
            if(obst)
            {
                dp[i][0] = 0;
            }
            else
            {
                dp[i][0] = 1;                
            }
        }
        
        for(int i = 1; i<width; i++)
        {
            for(int j = 1; j<height; j++)
            {
                if(obstacleGrid[j][i] == 1) continue;
                dp[j][i] = dp[j-1][i] + dp[j][i-1];
            }
        }
        return dp[height-1][width-1];
    }
};