class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        leng1 = len(haystack)
        leng2 = len(needle)
        if leng1 == 0 and leng2 == 0:
            return 0
        elif leng1 == 0 and leng2 != 0:
            return -1
        elif leng1 != 0 and leng2 == 0:
            return 0
        re = -1
        mat = True
        for idx, val in enumerate(haystack):
            if val == needle[0]:
                if len(haystack[idx:]) >= leng2:
                    for i in range(leng2):
                        mat = mat and (needle[i] == haystack[idx+i])
                        if mat == False: 
                            break
                    if mat:
                        return idx
                    else:
                        mat = True

                else:
                    return -1
        return -1