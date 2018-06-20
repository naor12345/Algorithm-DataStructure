class Solution {
public:
    unordered_map<string, vector<string>> memo;
    
    vector<string> combine(string right, vector<string> leftRes)
    {
        for(auto &str : leftRes)
        {
            str += " ";
            str += right;
        }
        return leftRes;
    }
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if(memo.count(s))
        {
            return memo[s];
        }
        vector<string> res;
        if(dict.count(s))
        {
            res.push_back(s);
        }
        
        for(int i = s.size()-1; i>=1; i--)
        {
            string right = s.substr(i);
            if(dict.count(right))
            {
                string left = s.substr(0, i);
                vector<string> subres = combine(right, wordBreak(left, dict));
                res.insert(res.end(), subres.begin(), subres.end());
            }
        }
        
        memo[s] = res;
        return res;
    }
};