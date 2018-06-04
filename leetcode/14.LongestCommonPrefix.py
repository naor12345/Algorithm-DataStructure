class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        re = ''
        sleng = len(strs)
        if sleng == 1:
            return strs[0]
        elif sleng == 0:
            return ''
        leng=[]
        for idx, strr in enumerate(strs):
            leng.append(len(strr))

        a = min(leng)    
        for i in range(0, a):
            t = True
            s = strs[0][i]
            for j in range(1,sleng):
                t = t and (s == strs[j][i])
            if t:
                re = re + s
            else:
                break
        return re