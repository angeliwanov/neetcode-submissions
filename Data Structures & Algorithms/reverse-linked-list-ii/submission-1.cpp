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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < left - 1; ++i) {
            prev = curr;
            curr = curr->next;
        }

        ListNode* start = prev;
        ListNode* end = curr;

        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        end->next = curr;
        if (start != nullptr) {
            start->next = prev;
            return head;
        }
        return prev;
    }
};