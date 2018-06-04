class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        ress(0, nums, tmp, res);
        return res;
    }
    
    void ress(int start, vector<int> &nums, vector<int> &tmp, vector<vector<int>> &re)
    {
        re.push_back(tmp);
        for(int i = start; i<nums.size(); i++)
        {
            tmp.push_back(nums[i]);
            ress(i+1, nums, tmp, re);
            tmp.pop_back();
        }
    }
};