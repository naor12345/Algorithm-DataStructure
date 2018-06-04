class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i<=n; i++)
        {
            int t = i-1;
            for(int k = 0; k<=t; k++)
            {
                dp[i] += dp[k]*dp[t-k];
            }
        }
        return dp[n];
    }
};