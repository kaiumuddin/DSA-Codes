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
    void insert_tail(ListNode*& head, ListNode*& tail, int val) {
        if (head == NULL) {
            head = new ListNode(val);
            tail = head;
        }

        tail->next = new ListNode(val);
        tail = tail->next;
    }
    void reverseRec(ListNode*& head, ListNode* cur) {
        if (cur->next == NULL) {
            head = cur;
            return;
        }

        reverseRec(head, cur->next);

        cur->next->next = cur;
        cur->next = NULL;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        ListNode* tmp = head;

        while (tmp != NULL) {
            insert_tail(newHead, newTail, tmp->val);
            tmp = tmp->next;
        }

        reverseRec(newHead, newHead);

        ListNode* i = head;
        ListNode* j = newHead;



        while (i) {
            cout << i->val << " " << j->val << endl;
            if (i->val != j->val) return false;
            i = i->next;
            j = j->next;
        }

        return true;
    }
};