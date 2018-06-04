/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {     
        vector<TreeNode*> res;
        if(n == 0) return res;
        return helper(1,n);
    }
    
    vector<TreeNode*> helper(int a, int b)
    {
        vector<TreeNode *> res;
        if(a>b)
        {
            res.push_back(NULL);
            return res;
        }
        
        if(a == b)
        {
            TreeNode *m = new TreeNode(a);
            res.push_back(m);
        }
        
        if(a < b)
        {
            for(int i = a; i<=b; i++)
            {
                vector<TreeNode*> left = helper(a, i-1);
                vector<TreeNode*> right = helper(i+1, b);
                
                for(TreeNode *lnode : left)
                {
                    for(TreeNode *rnode : right)
                    {
                        TreeNode *m = new TreeNode(i);
                        m->left = lnode;
                        m->right = rnode;
                        res.push_back(m);
                    }
                }
            }
        }
        return res;
    }
};