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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];

        int mid = (l + r) / 2;

        auto a = mergeKListsHelper(lists, l, mid);
        auto b = mergeKListsHelper(lists, mid + 1, r);

        return mergeTwoLists(a, b);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if (n == 0) return nullptr;

        int l = 0;
        int r = lists.size() - 1;

        return mergeKListsHelper(lists, l, r);
    }
};