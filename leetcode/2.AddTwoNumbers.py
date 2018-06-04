# 大数相加

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        carry = 0
        tmp1 = l1
        tmp2 = l2
        re = ListNode(0)
        tmp = re
        while True:          
            tmp.val = (tmp1.val + tmp2.val + carry) % 10
            carry = (tmp1.val + tmp2.val + carry) // 10
            if tmp1.next == None or tmp2.next == None:
                break
            else:
                tmp1 = tmp1.next
                tmp2 = tmp2.next
                tmp.next = ListNode(0)
                tmp = tmp.next
        if tmp2.next == None and tmp1.next != None:
            tmp1 = tmp1.next
            tmp.next = ListNode(0)
            tmp = tmp.next
            while True:
                tmp.val = (carry + tmp1.val) % 10
                carry = (carry + tmp1.val) // 10
                if tmp1.next == None:
                    if carry == 1:
                        tmp.next = ListNode(1)
                    break
                else:
                    tmp1 = tmp1.next
                    tmp.next = ListNode(0)
                    tmp = tmp.next

        elif tmp2.next != None and tmp1.next == None:
            tmp2 = tmp2.next
            tmp.next = ListNode(0)
            tmp = tmp.next
            while True:
                tmp.val = (carry + tmp2.val) % 10
                carry = (carry + tmp2.val) // 10
                if tmp2.next == None:
                    if carry == 1:
                        tmp.next = ListNode(1)
                    break
                else:
                    tmp2 = tmp2.next
                    tmp.next = ListNode(0)
                    tmp = tmp.next

        else:
            if carry == 1:
                tmp.next = ListNode(0)
                tmp = tmp.next
                tmp.val = 1
        return re
        
