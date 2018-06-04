class Solution {
public:
    string longestPalindrome(string s) {
        string res = "$#";
        
        for(int i = 0; i<s.size(); i++)
        {
            res += s[i];
            res += "#";
        }
        
        vector<int> P(res.size(), 0);
        
        int maxMid = 0;
        int right = 0;
        
        int res_i = 0, res_l = 0;
        
        for(int i = 1; i<res.size(); i++)
        {
            P[i] = right > i ? min(P[2*maxMid-i], right - i) : 1;
            
            while(res[i+P[i]] == res[i-P[i]])
                ++P[i];
            
            if(right < i+P[i])
            {
                right = i+P[i];
                maxMid = i;
            }
            
            if(res_l < P[i])
            {
                res_i = maxMid;
                res_l = P[i];
            }
        }
        
        return s.substr((res_i - res_l)/2, res_l - 1);
    }
};