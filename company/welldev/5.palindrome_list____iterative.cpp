#include <iostream>

using namespace std;

// Node structure for the linked list
class ListNode {
public:
    int val;        // Value stored in the node
    ListNode* next; // Pointer to the next node
    
    // Constructor to initialize a node with value and next pointer
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    // Traverse the list, reversing the links of nodes
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev; // Return the new head of the reversed list
}

// Function to find the middle of the linked list
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Use slow and fast pointers to find the middle of the list
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast != nullptr){
        slow = slow->next;
    }

    return slow; // Return the middle node
}

// Function to check if a linked list is a palindrome
bool isPalindrome(ListNode* head) {
    // An empty list or single-node list is a palindrome
    if (head == nullptr || head->next == nullptr)
        return true;

    // Find the middle of the linked list
    ListNode* middle = findMiddle(head);


    // Reverse the second half of the linked list
    ListNode* reversedSecondHalf = reverseList(middle);

    // Compare the first half of the original linked list with the reversed second half
    ListNode* curr1 = head;
    ListNode* curr2 = reversedSecondHalf;

    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1->val != curr2->val)
            return false; // If values are not equal, it's not a palindrome

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return true; // If all values matched, it's a palindrome
}

int main() {
    // Create a palindrome linked list: 1->2->3->3->2->1
    // ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(3);
    // head->next->next->next->next = new ListNode(2);
    // head->next->next->next->next->next = new ListNode(1);

     ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(1);

    // Check if the linked list is a palindrome
    if (isPalindrome(head))
        cout << "Linked list is a palindrome." << endl;
    else
        cout << "Linked list is not a palindrome." << endl;

    // Clean up memory
    ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
