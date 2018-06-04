class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        helper(nums, res, tmp);
        return res;
    }
    
    void helper(vector<int> &nums, vector<vector<int>> &res, vector<int> &tmp)
    {
        if(tmp.size() == nums.size()) res.push_back(tmp);
        else
        {
            for(int i = 0; i<nums.size(); i++)
            {
                if(contain(tmp, nums[i])) continue;
                else tmp.push_back(nums[i]);
                helper(nums, res, tmp);
                tmp.pop_back();
            }
        }
    }
    
    bool contain(vector<int> &a, int m)
    {
        bool res = false;
        for(int i = 0; i<a.size(); i++)
        {
            res = res || a[i] == m;
            if(res) break;
        }
        return res;
    }
};