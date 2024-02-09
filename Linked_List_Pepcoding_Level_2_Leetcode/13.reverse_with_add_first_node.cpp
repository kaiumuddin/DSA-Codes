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


ListNode* reverse(ListNode* head) {
    ListNode* th = NULL;
    ListNode* tt = NULL;

    ListNode* curr = head;
    while (curr) {
        //remove first
        ListNode* forw = curr->next;
        curr->next = NULL;

        addFirst(th, tt, curr);

        curr = forw;
    }
    return th;
}

int main() {
    ListNode* head =
        new ListNode(1,
            new ListNode(2,
                new ListNode(3,
                    new ListNode(4,
                        new ListNode(5)))));


    printList(head);
    head = reverse(head);
    printList(head);
    return 0;
}