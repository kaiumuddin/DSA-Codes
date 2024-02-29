
#include <iostream> 
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to reverse a linked list iteratively
    ListNode* iterative(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* curr_next;

        // Traverse the list, reversing pointers
        while (curr != NULL) {
            curr_next = curr->next; // Store next node
            curr->next = prev;      // Reverse the pointer
            prev = curr;            // Move prev to current node
            curr = curr_next;       // Move curr to next node
        }

        return prev; // New head is the last node processed
    }

    // Function to reverse a linked list recursively
    ListNode* recursive(ListNode* head) {
        // Base case: if list is empty or has only one node, return head
        if (head == NULL || head->next == NULL) return head;

        // Recursively reverse the rest of the list
        ListNode* newHead = recursive(head->next);

        // Reverse the pointers
        head->next->next = head;
        head->next = NULL;

        return newHead; // New head is the original list's tail
    }

    ListNode* reverseWithStack(ListNode* head) {
        stack<int> valueStack;

        while(head != NULL){
            valueStack.push(head->val);
            head = head->next;
        }

        ListNode* newHead = new ListNode(0);
        ListNode* curr = newHead;

        while(valueStack.size()){
            curr->next = new ListNode(valueStack.top());
            valueStack.pop();
            curr = curr->next;
        }

        return newHead->next; // New head is the original list's tail
    }

    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        // Call iterative or recursive method
        // return iterative(head);
        // return recursive(head);
        return reverseWithStack(head);
    }
};

// Function to print the elements of a linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;

    // Print original list
    cout << "Original List: ";
    printList(head);

    // Reverse the list
    ListNode* reversedHead = solution.reverseList(head);

    // Print reversed list
    cout << "Reversed List: ";
    printList(reversedHead);

    // Clean up memory
    ListNode* temp;
    while (reversedHead) {
        temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}
