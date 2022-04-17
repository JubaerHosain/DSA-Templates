used min heap, see marge k sorted array


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        if(n == 0)
            return NULL;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for(int i = 0; i < n; i++) {
            if(lists[i] == NULL) continue;
            min_heap.push({lists[i]->val, i});
            lists[i] = lists[i]->next;
        }
        
        if(min_heap.size() == 0)
            return NULL;
        
        ListNode *head;
        pair<int, int> curr = min_heap.top();
        min_heap.pop();
        head = new ListNode(curr.first);
        if(lists[curr.second] != NULL) {
            min_heap.push({lists[curr.second]->val, curr.second});
            lists[curr.second] = lists[curr.second]->next;
        }
        
        ListNode *tmp = head;
        while(!min_heap.empty()) {
            curr = min_heap.top();
            min_heap.pop();
            tmp->next = new ListNode(curr.first);
            if(lists[curr.second] != NULL) {
                min_heap.push({lists[curr.second]->val, curr.second});
                lists[curr.second] = lists[curr.second]->next;
            }
            tmp = tmp->next;
        }
        
        return head;
    }
};














