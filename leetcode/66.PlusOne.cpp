class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 0;
        int add = 1;
        int l = digits.size();
        int tmp;
        
        for(int i = l-1; i>=0; i--)
        {
            tmp = digits[i] + add + carry;            
            add = 0;
            if(tmp >= 10)
            {
                carry = 1;
                res.push_back(tmp % 10);
            }
            else
            {
                carry = 0;
                res.push_back(tmp);
            }
        }
        
        if(carry == 1)
        {
            res.push_back(1);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};