class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        return c(m+n-2, m-1);
        
    }
    
    int c(int n, int m)
    {
        double tmp = n/1.0;
        for(int i = 1; i<m; i++)
        {
            tmp *= (n-i);
            tmp /= (m-i+1);
        }

        return round(tmp);
    }
};