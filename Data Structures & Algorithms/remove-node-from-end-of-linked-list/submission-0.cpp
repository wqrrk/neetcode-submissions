class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) { 
            return nullptr;
        }
        ListNode* last = head; 
        int len = 1;
        //finding the last node
        while (last->next) { 
            last = last->next; 
            len++;
        }
        if ((len - n) == 0) { 
            return head->next;
        }
        ListNode* current = head;
        int dest = len - n - 1;
        //get to the element before the one we need to delete
        for (int i = 0; i < dest; i++) { 
            current = current->next;
        }
        current->next = current->next->next; 
        return head;
    }
};