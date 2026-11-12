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
    void reorderList(ListNode* head) {
        if (!head || !head->next) { 
            return;
        }
        stack<ListNode*> list;
        ListNode* current = head; 
        while (current) { 
            list.push(current); 
            current = current->next;
        }

        ListNode* prevLt = head;
        ListNode* lt = head->next;
        ListNode* rt = list.top();
        int cnt = 0;
        while (lt != rt && cnt < list.size()) {  
            ListNode* n = lt;
            prevLt->next = rt;
            rt->next = lt;
            prevLt = lt; 
            lt = lt->next;
            list.pop();
            rt = list.top();
            cnt++;
        }
        lt->next = nullptr;
    }
};
