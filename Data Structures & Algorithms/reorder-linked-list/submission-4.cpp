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

        stack<ListNode*> nodes; 
        ListNode* current = head;
        while (current) { 
            nodes.push(current);
            current = current->next;
        }

        int cnt = 0;
        ListNode* prevLt = head;
        ListNode* lt = head->next; 
        ListNode* rt = nodes.top();
        
        while (lt != rt && cnt < nodes.size()) { 
            //reorder links
            prevLt->next = rt; 
            rt->next = lt;
            rt->next = lt; 
            //move pointers
            prevLt = lt;
            lt = lt->next;
            nodes.pop(); 
            rt = nodes.top();
            cnt++;
        }
        lt->next = nullptr;
    }
};
