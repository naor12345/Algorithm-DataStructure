class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        helper(tmp, res, nums, used);
        return res;
    }
    
    void helper(vector<int> &tmp, vector<vector<int>> &res, vector<int> &nums, vector<bool> used)
    {
        if(tmp.size() == nums.size()) res.push_back(tmp);
        else
        {
            for(int i = 0; i<nums.size(); i++)
            {
                if(used[i] || i>0 && nums[i] == nums[i-1] && !used[i-1]) continue;
                tmp.push_back(nums[i]);
                used[i] = true;
                helper(tmp, res, nums, used);
                used[i] = false;
                tmp.pop_back();
            }
        }
        
    }
};