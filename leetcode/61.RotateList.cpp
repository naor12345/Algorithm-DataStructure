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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode *nhead, *bbreak, *rear;
        int length = 0; 
        rear = head;
        bbreak = head;
        while(rear->next != NULL)
        {
            rear = rear->next;
            length++;
        }
        
        k = k%(length+1);
        
        if(k >= length+1)
        {
            return head;
        }
        
        
        rear->next = head;
        
        for(int i = 0; i<length-k; i++)
        {
            bbreak = bbreak->next;
        }
        nhead = bbreak->next;
        bbreak->next = NULL;
        return nhead;
    }
};