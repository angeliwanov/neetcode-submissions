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
   private:
    static ListNode* merge(ListNode* lst1, ListNode* lst2) {
        ListNode head{};
        ListNode* curr = &head;

        while (lst1 != nullptr && lst2 != nullptr) {
            if (lst1->val < lst2->val) {
                curr->next = lst1;
                lst1 = lst1->next;
            } else {
                curr->next = lst2;
                lst2 = lst2->next;
            }
            curr = curr->next;
        }

        curr->next = lst1 != nullptr ? lst1 : lst2;

        return head.next;
    }

   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        while (lists.size() > 1) {
            std::vector<ListNode*> tmp;

            for (size_t i = 0; i < lists.size(); i += 2) {
                ListNode* lst1 = lists[i];
                ListNode* lst2{};
                if (i + 1 < lists.size()) {
                    lst2 = lists[i + 1];
                }

                tmp.push_back(merge(lst1, lst2));
            }

            lists = tmp;
        }

        return lists.empty() ? nullptr : lists[0];
    }
};
