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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        //int g = __gcd((int)str1.size(), (int)str2.size());

        if (!head || !head->next)
        {
            return head;
        }

        ListNode* temp = head;
        ListNode* next = head->next;

        while(next)
        {
            int n1 = temp->val;
            int n2 = next->val;

            int g = __gcd(n1, n2);

            ListNode* welp = next;
            ListNode* newer = new ListNode(g);
            temp->next = newer;
            newer->next = welp;

            temp = next;
            next = next->next;
        }

        return head;
    }
};