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

    ListNode* reverseK(ListNode* head, int k, ListNode*& nextHead) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (k--) {

            ListNode* nxt = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        nextHead = curr;

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        // Check if k nodes exist
        ListNode* temp = head;

        for (int i = 0; i < k; i++) {
            if (!temp)
                return head;

            temp = temp->next;
        }

        ListNode* nextHead = nullptr;

        ListNode* newHead = reverseK(head, k, nextHead);

        head->next = reverseKGroup(nextHead, k);

        return newHead;
    }
};
