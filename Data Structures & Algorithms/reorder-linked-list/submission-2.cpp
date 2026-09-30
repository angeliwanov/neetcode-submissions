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
        //get the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        //swap the links betweeen the two halves
        ListNode* start = head;
        ListNode* end = prev;

        while (start && end) {
            if (start->next == end) {
                break;
            }
            ListNode* nextStart = start->next;
            ListNode* nextEnd = end->next;
            start->next = end;
            end->next = nextStart;
            start = nextStart;
            end = nextEnd;
        }
    }
};
