class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        d = {')': '(', ']': '[', '}': '{'}
        st = []
        i = -1
        for idx, val in enumerate(s):
            if val == '(' or val == '[' or val == '{':
                st.append(val)
                i = len(st) - 1
            elif val == ')' or val == ']' or val == '}':
                if i < 0:
                    return False
                if st[i] == d[val]:
                    st.pop()
                    i -= 1
                else:
                    return False
        if len(st) == 0:
            return True
        else:
            return False