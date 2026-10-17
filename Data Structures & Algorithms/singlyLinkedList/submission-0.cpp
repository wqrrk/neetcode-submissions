// #include <iostream>
// #include <vector>

// using namespace std;

class ListNode {
    public:
    int value;
    ListNode* next;

    ListNode(int val) {
        this->value = val;
        next = nullptr;
    }
};

class LinkedList {
public:

    ListNode* head;

    LinkedList() {
        this->head = nullptr;
    }

    int get(int index) {
        if (head == nullptr || index < 0) {
            return -1;
        }
        ListNode* current = this->head;
        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            return -1;
        }
        return current->value;
    }

    void insertHead(int val) {
        ListNode* newHead = new ListNode(val);
        if (head == nullptr) {
            head = newHead;
        } else {
            newHead->next = head;
            this->head = newHead;
        }
    }

    void insertTail(int val) {
        ListNode* newTail = new ListNode(val);
        ListNode* current = this->head;
        if (head == nullptr) {
            head = newTail;
        } else {
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newTail;
        }
    }

    bool remove(int index) {
        if (head == nullptr || index < 0) {
            return false;
        } else if (index == 0) {
            ListNode* newHead = head->next;
            ListNode* currentHead = head;
            this->head = newHead;
            delete currentHead;
            return true;
        } else {
            ListNode* current = this->head;
            for (int i = 0; i < index - 1 && current != nullptr; i++) {
                current = current->next;
            }
            if (current != nullptr && current->next != nullptr) {
                ListNode* deletingNode = current->next;
                current->next = deletingNode->next;
                delete deletingNode;
                return true;
            }
            return false;
        }
    }

    vector<int> getValues() {
        ListNode* current = this->head;
        vector<int> values;
        while (current != nullptr) {
            values.push_back(current->value);
            current = current->next;
        }
        return values;
    }
};