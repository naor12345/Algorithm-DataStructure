// Sort a linked list using insertion sort.

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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL) return NULL;
        
        node *fhead = new node(-1);
        fhead->next = head;
        node *sorted = fhead;
        node *cur = fhead->next;
        
        while(cur != NULL)
        {
            node *tmp = fhead;
            while(tmp != cur)
            {
                if(tmp == sorted) // final one
                {
                    sorted = sorted->next;
                    cur = cur->next;
                    break;
                }
                else
                {
                    if(tmp->next->val > cur->val)
                    {
                        // insert here
                        sorted->next = cur->next;
                        cur->next = tmp->next;
                        tmp->next = cur;
                        cur = sorted->next;
                        break;
                    }
                    else
                    {
                        tmp = tmp->next;
                    }
                }
                
            }
        }
        return fhead->next;
    }
};