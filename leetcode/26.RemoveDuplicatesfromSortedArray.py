class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        leng = len(nums)
        minu = 0
        idx = 0
        while idx < (leng - minu - 1):
            if nums[idx] == nums[idx + 1]:
                del nums[idx+1]
                minu += 1
            else:
                idx += 1
        return len(nums)
        