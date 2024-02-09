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
    ListNode* swapNodes(ListNode* head, int k) {
        auto curr = head;

        while (k - 1 > 0) {
            curr = curr->next;
            k--;
        }

        auto left = curr;
        auto right = head;

        while (curr->next) {
            curr = curr->next;
            right = right->next;
        }

        swap(left->val, right->val);

        return head;
    }
};