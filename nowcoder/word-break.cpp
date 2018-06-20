class Solution {
public:
    
    unordered_map<string, bool> memo;
    
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(memo.count(s)) return true;
        
        if(dict.count(s)) return true;
        bool res = false;
        for(int i = 1; i<s.size(); i++)
        {
            string right = s.substr(i);
            
            if(dict.count(right))
            {
                string left = s.substr(0, i);
                bool subres = wordBreak(left, dict);
                if(subres)
                {
                    memo[s] = true;
                    return true;
                }
                else
                {
                    continue;
                }
            }
        }
        
        
        return false;
    }
};