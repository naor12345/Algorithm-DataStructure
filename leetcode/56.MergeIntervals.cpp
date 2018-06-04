/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), mysort);
        vector<Interval> res;
        int i = 0, j = 0;
        int end = 0;
        
        while(i < intervals.size())
        {
            j = i;  
            end = intervals[i].end;
            while(j+1 < intervals.size())
            {
                if(end >= intervals[j+1].end)
                {
                    j++;
                }                
                else if(end >= intervals[j+1].start)
                {
                    j++;
                    if(intervals[j].end > end) end = intervals[j].end;
                } 
                else break;
            }
            
            res.push_back(Interval(intervals[i].start, end));
            i = j+1;
        }
        
        return res;
    }
    
    struct myclass
    {
        bool operator() (Interval a, Interval b){
            if(a.start < b.start)
                return true;
            else if(a.start == b.start)
                return a.end < b.end;
            else return false;
        }
    } mysort;
};