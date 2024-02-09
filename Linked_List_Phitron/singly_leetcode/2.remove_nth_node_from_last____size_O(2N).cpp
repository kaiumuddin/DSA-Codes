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
        if (head == NULL) return NULL;

        int sz = 0;
        for (auto i = head; i; i = i->next) sz++;

        if (sz - n == 0) return head->next;

        auto j = head;
        for (int i = 1; i <= sz - n - 1; i++) {
            j = j->next;
        }
        if (j->next) j->next = j->next->next;
        cout << j->val << endl;
        return head;
    }
};