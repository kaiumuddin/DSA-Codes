#include <iostream>

using namespace std;

// Node structure for the circular linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node with data and next pointer
    Node(int val) : data(val), next(nullptr) {}
};

// Circular linked list class
class CircularLinkedList {
private:
    Node* head; // Pointer to the head node

public:
    // Constructor to initialize an empty circular linked list
    CircularLinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the circular linked list
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (!head) { // If the list is empty
            head = newNode;
            newNode->next = head; // Point back to itself
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Point back to the head
        }
    }

    // Function to delete a node at the beginning of the circular linked list
    void deleteAtBeginning() {
        if (!head) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }

        Node* temp = head;
        Node* lastNode = head;

        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }

        if (head->next == head) { // If there's only one node
            delete head;
            head = nullptr;
        }
        else {
            lastNode->next = head->next;
            head = head->next;
            delete temp;
        }
    }

    // Function to delete a node at the end of the circular linked list
    void deleteAtEnd() {
        if (!head) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        while (curr->next != head) {
            prev = curr;
            curr = curr->next;
        }

        if (prev) {
            prev->next = head;
            delete curr;
        }
        else { // If there's only one node
            delete head;
            head = nullptr;
        }
    }

    // Function to delete a node in between two nodes of the circular linked list
    void deleteInBetween(int position) {
        if (!head) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        // Traverse to the position before the deletion point
        for (int i = 0; i < position && curr->next != head; ++i) {
            prev = curr;
            curr = curr->next;
        }

        if (prev) {
            prev->next = curr->next;
            delete curr;
        }
        else { // If deleting the head node
            deleteAtBeginning();
        }
    }

    // Function to display the elements of the circular linked list
    void display() {
        if (!head) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(1); // Insert 1 at the end
    cll.insertAtEnd(2); // Insert 2 at the end
    cll.insertAtEnd(3); // Insert 3 at the end

    cout << "Original Circular Linked List: ";
    cll.display();

    cll.deleteAtBeginning(); // Delete node at the beginning

    // cout << "Circular Linked List after deleting at beginning: ";
    // cll.display();

    // cll.deleteAtEnd(); // Delete node at the end

    // cout << "Circular Linked List after deleting at end: ";
    // cll.display();

    // cll.deleteInBetween(0); // Delete node in between (at position 0)

    // cout << "Circular Linked List after deleting in between: ";
    cll.display();

    return 0;
}
