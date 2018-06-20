/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    using node = RandomListNode;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return head;
        node *p;
        node *tmp;
        for(p = head; p!=NULL; p = p->next)
        {
            tmp = p->next;
            p->next = new node(p->label);
            p = p->next;
            p->next = tmp;
        }
        
        for(p = head; p!=NULL; p = p->next)
        {
            tmp = p->random ? p->random->next : NULL;
            p = p->next;
            p->random = tmp;
        }
        
        node *res = head->next;
        node *tar;
        for(p = head; p!=NULL; )
        {
            tar = p->next ? p->next->next : NULL;
            tmp = p->next;
            p->next = tar;
            p = tmp;
        }
        return res;
    }
};