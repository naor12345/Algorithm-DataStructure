class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        int tsum = 0;
        helper(candidates, res, 0, tsum, tmp, target);
        return res;
    }
    
    void helper(vector<int> &nums, vector<vector<int>> &res, int start, int &tsum, vector<int> &tmp, int target)
    {
        if(tsum == target) res.push_back(tmp);
        else if(tsum > target) return;
        else
        {
            int last = nums[start];
            for (int i = start; i<nums.size(); i++)
            {
                if(i>start && nums[i] == last) continue;
                else last = nums[i];
                tmp.push_back(nums[i]);
                tsum+=nums[i];
                helper(nums, res, i+1, tsum, tmp, target);
                tsum-=nums[i];
                tmp.pop_back();
            }
        }
    }
};