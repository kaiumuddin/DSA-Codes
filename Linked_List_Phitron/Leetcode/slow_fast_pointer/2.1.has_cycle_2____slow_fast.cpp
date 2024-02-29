#include <iostream>

using namespace std;

// Node class for the linked list
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next) {
        return nullptr; // Empty list or single node list, no cycle
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Detect cycle
    while (fast && fast->next) {
        slow = slow->next; // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps

        // If the pointers meet, there is a cycle
        if (slow == fast) {
            break;
        }
    }

    // If there is no cycle
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }

    // Reset one pointer to the head
    slow = head;

    // Move both pointers one step at a time until they meet again
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Return the node where the cycle starts
    return slow;
}

int main() {
    // Example with a cycle
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next; // Create cycle

    // Example without a cycle
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);

    cout << "Node where cycle starts in List 1: ";
    ListNode* cycleNode1 = detectCycle(head1);
    if (cycleNode1)
        cout << cycleNode1->val << endl;
    else
        cout << "No cycle found" << endl;

    cout << "Node where cycle starts in List 2: ";
    ListNode* cycleNode2 = detectCycle(head2);
    if (cycleNode2)
        cout << cycleNode2->val << endl;
    else
        cout << "No cycle found" << endl;

    // Clean up memory
    ListNode* temp;
    while (head1) {
        temp = head1;
        head1 = head1->next;
        delete temp;
    }
    while (head2) {
        temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}
