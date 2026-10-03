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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry {0};
        ListNode* prev = new ListNode(0);
        ListNode* h1 = l1;
        ListNode* h2 = l2;

        while (h1 != nullptr && h2 != nullptr) {
            int total = h1->val + h2->val + carry;
            carry = total / 10;
            total = total % 10;
            h1->val = total;
            prev = h1;
            h1 = h1->next;
            h2 = h2->next;
        }

        if (h2 != nullptr) {
            prev->next = h2;
        }

        h1 = prev->next;
        while (h1) {
            int total = h1->val + carry;
            carry = total / 10;
            total = total % 10;
            h1->val = total;
            prev = h1;
            h1 = h1->next;
        }

        if (carry) {
            prev->next = new ListNode(carry);
        }

        return l1;
    }
};
