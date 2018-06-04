class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.length();
        
        for(int i = l-1; i>=0; i--)
        {
            if(s[i] == ' ') l--;
            else break;
        }
        
              
        
        int countt = 0;
        if(l <= 0) return 0;
        
        for(int i = l-1; i>=0; i--)
        {
            if(s[i] != ' ') countt++;
            else break;
        }
        
        return countt;
    }
};