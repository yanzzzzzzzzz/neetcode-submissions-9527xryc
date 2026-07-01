/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* dummy = new Node(0);
        Node* tail = dummy;

        Node* curr = head;

        while(curr != NULL){
            // 1. 建立 copy node
            Node* copy = new Node(curr->val);
            // 2. 接到 tail 後面
            tail->next = copy;
            tail = tail->next;
            // 3. mp[curr] = copy
            mp[curr] = copy;
            // 4. curr = curr->next
            curr = curr->next;
        }
        curr = head;
        tail = dummy->next;

        while(curr != NULL){
            // 1. 找到 curr 對應的新 node
            // 2. 補 random
            tail->random = mp[curr->random];
            tail = tail->next;
            // 3. curr = curr->next
            curr = curr->next;
        }
        return dummy->next;
    }
};
