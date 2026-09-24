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
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while(second != nullptr){
            ListNode* nextNode = second->next;
            second->next = prev;
            prev = second;
            second = nextNode;
        }

        ListNode* first = head;
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = prev->next;

        while(prev != nullptr){
            first->next = prev;
            prev->next = tmp1;

            first = tmp1;
            prev = tmp2;

            tmp1 = first->next;
            tmp2 = prev->next;
        }
    }
};
