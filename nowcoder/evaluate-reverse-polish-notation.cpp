// stack实现波兰表达式
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int a, b;
        for(auto str : tokens)
        {
            if(str == "+")
            {
                a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(str == "-")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(str == "*")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if(str == "/")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b/a);
            }
            else 
            {
                a = stoi(str);
                s.push(a);
            }                
        }
        return s.top();
    }
};