//Given a linked list, return the node where the cycle begins. If there is no cycle, returnnull.

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
    ListNode *detectCycle(ListNode *head) {
        node *fast = head;
        node *slow = head;
        bool noCircle = false;
        if(head == NULL) return head;
        
        // while -> NULL
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            // break -> equal
            if(slow == fast) break;
        }
        
        if(fast == NULL || fast->next == NULL) return NULL;
        
        
        
        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};