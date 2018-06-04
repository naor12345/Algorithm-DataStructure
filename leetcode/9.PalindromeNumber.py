# 数位处理：不要用字符串（因为开销很大），用while循环除以10判断


class Solution(object):
    def getNum(self, x, y):
        return (x % pow(10, y)) // pow(10, y-1)
    
    
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        tmp = x
        c = 0
        if x < 0:
            return False
        elif x < 10: 
            return True
        elif x % 10 == 0:
            return False
        else:
            pass

        while tmp != 0:
            c += 1
            tmp = tmp // 10
        re = True
        i = 0
        for i in range(1, c//2+1):
            a1 = i
            a2 = c + 1 - i
            re = re and (self.getNum(x, a1) == self.getNum(x, a2))
        return re