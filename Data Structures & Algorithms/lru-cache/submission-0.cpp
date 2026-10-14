class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
    };
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node{-1, -1, nullptr, nullptr};
        tail = new Node{-1, -1, nullptr, nullptr};
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        Node* node = cache[key];
        removeNode(node);
        addToTail(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addToTail(node);
            cache[key] = node;
            return;
        }
        Node* newNode = new Node{key, value, nullptr, nullptr};
        addToTail(newNode);
        cache[key] = newNode;
        if(cache.size() > capacity){
            Node* removedNode = cache[head->next->key];
            removeNode(removedNode);
            cache.erase(removedNode->key);
        }

    }
    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addToTail(Node* node){
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }
};
