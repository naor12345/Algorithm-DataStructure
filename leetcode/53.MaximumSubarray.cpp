class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int tmp = nums[0];
        
        for(int i = 1; i<nums.size(); i++)
        {
            if(tmp < 0)
            {
                tmp = nums[i];
            }
            else
            {
                tmp += nums[i];
            }
            if(tmp > sum) sum = tmp;
        }
        return sum;
    }
};