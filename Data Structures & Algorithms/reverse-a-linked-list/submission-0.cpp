class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) { 
            return nullptr; 
        }

        ListNode* prev = nullptr; 
        ListNode* next = nullptr; 
        ListNode* curr = head; 
        
        while (curr != nullptr) { 
            
            //swapping the nodes
            next = curr->next; 
            curr->next = prev; 

            //move pointers
            prev = curr;
            curr = next; 
        }

        return prev; 
    }
};