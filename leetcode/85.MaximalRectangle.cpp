class Solution {
public:
    
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int maxx = 0;
        vector<int> nums(matrix[0].size(), 0);
        stack<int> st;
        for(int i = 0; i<matrix.size(); i++)
        {
            for(int k = 0; k<nums.size(); k++)
            {
                nums[k] = matrix[i][k] == '0' ? 0 : nums[k] + 1;
            }
            
            if(!st.empty()) st.empty();
            
            for(int k = 0; k<nums.size(); k++)
            {
                if(st.empty()) 
                {
                    st.push(k);
                    continue;
                }
                
                if(nums[k] > nums[st.top()]) 
                    st.push(k);
                else
                {
                    while(!st.empty() && nums[k] <= nums[st.top()])
                    {
                        int m = st.top();
                        st.pop();
                        maxx = max(maxx, nums[m]*(k-1- (st.empty() ? -1 : st.top()) ));
                    }
                    st.push(k);
                }
            }
            
            while(!st.empty())
            {
                int m = st.top();
                st.pop();
                int k = nums.size();
                maxx = max(maxx, nums[m]*(k-1- (st.empty() ? -1 : st.top()) ));
            }
        }
        
        
        
        
        return maxx;
    }
};