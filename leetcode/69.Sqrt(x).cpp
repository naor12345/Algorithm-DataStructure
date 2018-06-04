class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        
        while(r*r-x > 0)
        {
            r = (r*r+x)/2/r;
        }
        
        return r;        
        
    }
};