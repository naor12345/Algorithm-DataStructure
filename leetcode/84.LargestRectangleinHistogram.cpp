class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxx = 0;
        for(int i = 0; i<heights.size(); i++)
        {
            if(st.empty())
            {
                st.push(i);
                continue;
            }
            
            if(heights[i] > heights[st.top()])
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && heights[i] <= heights[st.top()])
                {
                    int m = st.top();
                    st.pop();
                    maxx = max(maxx, heights[m]*(i - 1 - (st.empty() ? -1 : st.top())));
                }
                st.push(i);
            }
            
            
        }
        while(!st.empty())
        {
            int m = st.top();
            st.pop();
            int k = heights.size();
            maxx = max(maxx, heights[m]*(k - 1 - (st.empty() ? -1 : st.top())));
        }
        return maxx;
    }
};