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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;

        auto curr = head;
        while (curr && curr->next) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            }

            else if (curr->next->val != val) {
                curr = curr->next;
            }
        }
        if (val == head->val) return head->next;
        return head;
    }
};