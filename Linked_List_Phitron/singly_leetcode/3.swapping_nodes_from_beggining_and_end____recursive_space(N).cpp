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
    ListNode* a = new ListNode();
    ListNode* b = new ListNode();

    int  swapNodesHelper(ListNode* head, int k, int i) {
        if (head == NULL) return 1;

        if (i == k)  a = head;

        int ridx = swapNodesHelper(head->next, k, i + 1);

        if (ridx == k) b = head;

        return ridx + 1;

    }
    ListNode* swapNodes(ListNode* head, int k) {
        int ridx = swapNodesHelper(head, k, 1);

        swap(a->val, b->val);

        return head;
    }
};