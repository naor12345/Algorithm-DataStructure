class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        bool find = false;
        vector<int> ans;
        int iend = nums.size();
        int i0 = 0;
        int i1 = 1;
        for (i0 = 0; i0 < iend; i0++)
		{
			for (i1 = i0 + 1; i1 < iend; i1++)
			{
				if (nums[i0] + nums[i1] == target)
				{
					find = true;
					break;
				}
			}
			if (find)
			{
				ans.push_back(i0);
				ans.push_back(i1);
				return ans;
			}
		}
		return ans;
    }
};