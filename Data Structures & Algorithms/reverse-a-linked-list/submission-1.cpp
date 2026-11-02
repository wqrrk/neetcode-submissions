class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) { 
            return nullptr; 
        }   
        ListNode* newHead = head; 
        
        if (head->next) { 
            newHead = reverseList(newHead->next); 
            head->next->next = head; 
        }
        head->next = nullptr; 
        
        return newHead;
    }
};