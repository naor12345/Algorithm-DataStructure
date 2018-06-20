// Given a linked list, determine if it has a cycle in it.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    using node = ListNode;
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        node *fast = head;
        node *slow = head;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) break;
        }
        
        if(!fast || !fast->next) return false;
        if(slow == fast) return true;
        else return false;
    }
};