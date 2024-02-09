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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forw = nullptr;

        while (curr != nullptr) {
            forw = curr->next;

            curr->next = prev;

            prev = curr;
            curr = forw;
        }

        return prev;
    }

    ListNode* middleNode(ListNode* head) {
        auto slow = head;
        auto fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        auto mid = middleNode(head);
        auto nHead = mid->next;
        mid->next = nullptr;

        nHead = reverseList(nHead);

        auto i = head;
        auto j = nHead;

        bool res = true;
        while (j != nullptr) {
            if (i->val != j->val) {
                res = false;
                break;
            }

            i = i->next;
            j = j->next;
        }

        nHead = reverseList(nHead);
        mid->next = nHead;

        return res;
    }
};