#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printList(ListNode* node) {
    for (;node;node = node->next) cout << node->val << " ";
    cout << endl;
}

void addFirst(ListNode*& th, ListNode*& tt, ListNode* node) {
    if (th == NULL) {
        th = node;
        tt = node;
    }
    else {
        node->next = th;
        th = node;
    }
}

int length(ListNode* node) {
    int s = 0;
    for (; node;node = node->next) s++;
    return s;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;

    int len = length(head);

    ListNode* th = NULL;
    ListNode* tt = NULL;
    ListNode* oh = NULL;
    ListNode* ot = NULL;

    ListNode* curr = head;

    while (len >= k) {
        int tmpK = k;
        while (tmpK-- > 0) {
            ListNode* forw = curr->next;
            curr->next = NULL;

            addFirst(th, tt, curr);
            curr = forw;
        }
        if (oh == NULL) {
            oh = th;
            ot = tt;
        }
        else {
            ot->next = th;
            ot = tt;
        }

        th = tt = NULL;
        len -= k;
    }

    ot->next = curr;

    return oh;

}

int main() {
    ListNode* head =
        new ListNode(1,
            new ListNode(2,
                new ListNode(3,
                    new ListNode(4,
                        new ListNode(5,
                            new ListNode(6,
                                new ListNode(7,
                                    new ListNode(8,
                                        new ListNode(9)))))))));


    printList(head);
    head = reverseKGroup(head, 3);
    printList(head);
    return 0;
}