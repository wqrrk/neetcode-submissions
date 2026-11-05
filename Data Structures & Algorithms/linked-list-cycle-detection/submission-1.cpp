
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) { 
            return false;
        }
        set<ListNode*> visited; 
        ListNode* current = head; 
        while (current->next) { 
            if (auto [iterator, inserted] = visited.insert(current); !inserted) { 
                return true;
            }
            current = current->next;
        }
        return false;
    }
};