class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        for(vector<int>::iterator it = nums.end()-1; ; it--)
        {
            if(*it == val) nums.erase(it);
            if(it == nums.begin()) break;
        }
        return nums.size();
    }
};