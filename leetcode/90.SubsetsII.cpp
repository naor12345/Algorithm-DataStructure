class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        helper(0, tmp, nums, res);
        return res;
    }
    
    void helper(int start, vector<int> &tmp, vector<int> &nums, vector<vector<int>> &res)
    {
        res.push_back(tmp);
        for(int i = start; i<nums.size(); i++)
        {
            
            tmp.push_back(nums[i]);
                helper(i+1, tmp, nums, res);
            while(i+1<nums.size() && nums[i+1] == nums[i])
            {
                i++;
            }
            
            tmp.pop_back();
        }
    }
};