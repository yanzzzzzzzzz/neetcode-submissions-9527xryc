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
        if(head==NULL || head->next==NULL) return;

        // 找中點
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // 切開後半段
        ListNode* second = slow->next;
        slow->next = NULL;

        // 反轉後半段

        ListNode* prev = NULL;
        ListNode* curr = second;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // prev是反轉後的head
        ListNode* first = head;
        second = prev;

        //合併
        while(second != NULL){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
