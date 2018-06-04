class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        int tsum = 0;
        helper(target, res, tmp, 0, tsum, candidates);
        return res;
    }
    
    void helper(int target, vector<vector<int>> &res, vector<int> &tmp, int start, int &tsum, vector<int> &nums)
    {
        if(tsum == target) res.push_back(tmp);
        else if(tsum > target) return;
        else
        {
            for(int i = start; i<nums.size(); i++)
            {
                tmp.push_back(nums[i]);
                tsum += nums[i];
                helper(target, res, tmp, i, tsum, nums);
                tsum -= nums[i];
                tmp.pop_back();
            }
        }
    }
};