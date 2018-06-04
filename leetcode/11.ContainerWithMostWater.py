class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i = 0
        j = len(height) - 1
        mx = 0
        while i < j:
            mx = max(mx, (j - i) * min(height[i], height[j]))
            if height[i] < height[j]:
                while(height[i+1] <= height[i]) and i < j:
                    i += 1
                i += 1
            else:
                while(height[j-1] <= height[j]) and i < j:
                    j -= 1
                j -= 1
        return mx
            