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

        auto dummy = new ListNode(-1, head);

        auto left = dummy;
        auto right = head;

        while (n > 0 && right) {
            right = right->next;
            n--;
        }

        while (right) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        return dummy->next;

    }
};