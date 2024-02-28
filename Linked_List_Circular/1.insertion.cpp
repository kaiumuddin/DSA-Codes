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
    
    // Function to insert a new node at the beginning of the circular linked list
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        
        if (!head) { // If the list is empty
            head = newNode;
            newNode->next = head; // Point back to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Point back to the head
            head = newNode; // Update head to the new node
        }
    }
    
    // Function to insert a new node at the end of the circular linked list
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        
        if (!head) { // If the list is empty
            head = newNode;
            newNode->next = head; // Point back to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Point back to the head
        }
    }
    
    // Function to insert a new node in between two nodes of the circular linked list
    void insertInBetween(int val, int position) {
        Node* newNode = new Node(val);
        
        if (!head || position <= 0) { // If the list is empty or position is 0, insert at the beginning
            insertAtBeginning(val);
            return;
        }
        
        Node* temp = head;
        for (int i = 1; i < position && temp->next != head; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
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
    cll.insertAtBeginning(1); // Insert 1 at the beginning
    cll.insertAtEnd(3); // Insert 3 at the end
    cll.insertInBetween(2, 1); // Insert 2 between nodes
    cll.insertInBetween(100, 10); // Insert 2 between nodes
    
    cout << "Original Circular Linked List: ";
    cll.display();
    
    return 0;
}
