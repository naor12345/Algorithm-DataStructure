class Solution {
public:
    
    struct str
    {
        string a;
        int l;
        int r;
        str(){}
        str(string x, int l, int r):a(x), l(l), r(r){}
        int size(){return a.size();}
    };
    
    vector<str> res;
    vector<string> generateParenthesis(int n) {
        vector<string> a;
        str s("(", n-1, 1);
        res.push_back(s);
        while(res[0].size() != 2*n)
        {
            process(res);
        }
        
        for(vector<str>::iterator it = res.begin(); it!=res.end(); it++){
            a.push_back(it->a);
        }
        return a;
    }
    
    void process(vector<str> &res)
    {
        vector<str>::iterator it;
        int c = res.size();
        vector<str> tmp;
        for(it=res.begin(); c>0; c--, it++)
        {
            if(it->l>0 && it->r>0)
            {
                string x = it->a;
                int l = it->l, r = it->r;
                it->a = x + "("; it->l--; it->r++;
                tmp.push_back(str(x + ")", l, --r));
            }
            else if(it->l==0 && it->r>0){
                it->a += ")"; it->r--;
            }
            else if(it->l>0 && it->r==0){
                it->a += "("; it->l--; it->r++;
            }
            else if(it->l==0 && it->r==0) continue;
            else continue;
        }

        for(int i = 0; i<tmp.size(); i++) res.push_back(tmp[i]);
    }
};