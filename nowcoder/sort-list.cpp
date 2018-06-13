// 无序链表链表的归并排序
// 链表分为左右两节时，中间必须用NULL打断

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
    ListNode *sortList(ListNode *head) {
        if (head == NULL) return head;
        return mergeSort(head);
    }
    
    node *merge(node *n1, node *n2) // both should be ended as NULL
    {
        if(n1 == NULL) return n2;
        if(n2 == NULL) return n1;
        node* head = n1->val < n2->val ? n1 : n2;
        node* t1 = head == n1 ? n1->next : n1;
        node *t2 = head == n2 ? n2->next : n2;
        node *tmp = head;
        while(t1 && t2)
        {
            if(t1->val < t2->val)
            {
                tmp->next = t1;
                t1 = t1->next;
            }
            else
            {
                tmp->next = t2;
                t2 =t2->next;
            }
            tmp = tmp->next;
        }
        
        if(!t1)
        {
            tmp->next = t2;
            return head;
        }
        if(!t2)
        {
            tmp->next = t1;
            return head;
        }
        return head;
    }
    
    node* mergeSort(node *head)
    {
        if(head->next != NULL)
        {
            node *last1;
            node *mid = findMid(head, last1);
            last1->next = NULL;
            node *a = mergeSort(head);
            node *b = mergeSort(mid);
            return merge(a, b);
        }
        else 
        {
            return head;
        }
    }
    
    node *findMid(node *head, node* &last) 
    {
        node *tmp = head;
        node *mid = head;
        while(tmp ->next)
        {
            tmp = tmp->next;
            if(tmp->next)
            {
                tmp = tmp->next;
                mid = mid->next;
            }
            else
            {
                break;
            }
        }
        last = mid;
        return mid->next;
    }
};