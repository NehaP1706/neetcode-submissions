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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;

        ListNode* tmp = head;

        while(tmp)
        {
            sz++;
            tmp = tmp->next;
        }

        int pos = sz - n;

        ListNode* temp = head;
        ListNode* prev = nullptr;
        int i = 0;

        while(temp)
        {
            if (i == pos)
            {
                if (prev)
                {
                    prev->next = temp->next;
                    break;
                }
                else
                {
                    head = head->next;
                }
            }

            prev = temp;
            temp = temp->next;
            i++;

            //cout << i << " " << pos << endl;
        }

        return head;
    }
};
