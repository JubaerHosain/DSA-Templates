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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        else if(head->next == NULL)
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) 
                return true;
        }
        
        return false;
    }
};

// how to find the first node of cycle?
// ফ্লয়েডের সাইকেল ফাইন্ডিং অ্যালগরিদম, শাফায়েতের ব্লগ