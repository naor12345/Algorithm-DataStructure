// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution{
    public:
        int search(vector<int> &nums, int target){
            if(nums.size() == 0) return -1;
            int n = nums.size();
            int high = n-1;
            int low = 0;
            int mid;

            // find the idx of min
            while(low < high){
                mid = (low+high)/2;
                if(nums[mid] > nums[high]) low = mid+1;
                else high = mid;
            }

            // now low=high is the idx of min
            // use regular binary search

            int idx = low;
            low = 0; high = n-1;

            while(low <= high){
                mid = (low+high)/2;
                int realmid = (mid + idx)%n;   // pay attention to here

                // new high and low is based on mid, not realmid
                if(nums[realmid] < target) low = mid+1;  
                else high = mid-1;
            }
            return -1;            
        }
}
