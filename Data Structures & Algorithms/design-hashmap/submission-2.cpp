class MyHashMap {
private:
    
    struct Node { 
        int key; 
        int val;
        Node* next;
        Node(int key = -1, int val = -1, Node* next = nullptr) {
            this->key = key;
            this->val = val; 
            this->next = next;
        }
    };

    vector<Node*> data; 

    int hash(int key) { 
        return key % data.size(); 
    }

public:
    MyHashMap() {
        //init the buckets with a start value of 1000
        data.resize(1000);
        for (int i = 0; i < data.size(); i++) { 
            data[i] = new Node();
        }
    }

    ~MyHashMap() { 
        for (Node* head : data) { 
            Node* curr = head; 
            while (curr) { 
                Node* next = curr->next; 
                delete curr; 
                curr = next; 
            }
        }
    }
    
    void put(int key, int value) {
        //Find the bucket
        Node* curr = data[hash(key)]; 
        //Iterate through nodes in the bucket to find an empty one 
        while (curr->next) { 
            //if we found one with the key then update the value 
            if (curr->next->key == key) { 
                curr->next->val = value;
                return;
            } 
            //move on
            curr = curr->next;
        }
        //insert the new node
        curr->next = new Node(key,value);
    }
    
    int get(int key) {
        Node* curr = data[hash(key)];
        while (curr) { 
            if (curr->key == key) { 
                return curr->val;
            }
            curr = curr->next;
        }
        return -1; 
    }
    
    void remove(int key) {
       Node* curr = data[hash(key)]; 
       while (curr->next) { 
            if (curr->next->key == key) { 
                Node* tmp = curr->next; 
                curr->next = curr->next->next; 
                delete tmp; 
                return;
            }
            curr = curr->next;
       }
    }
};