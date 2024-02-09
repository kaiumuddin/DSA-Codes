#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    string val;
    Node* next;
    Node* prev;

    Node(string val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

int size(Node* head) {
    int count = 0;
    for (Node* i = head; i != NULL; i = i->next) {
        count++;
    }
    return count;
}

void printList(Node* head, Node* tail) {
    cout << "L -> ";
    for (Node* i = head; i != NULL; i = i->next)
        cout << i->val << " ";
    cout << endl;

    cout << "R -> ";
    for (Node* i = tail; i != NULL; i = i->prev)
        cout << i->val << " ";
    cout << endl;
}


void insertTail(Node*& head, Node*& tail, string val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}


void inputList(Node*& head, Node*& tail) {
    string s;
    while (true) {
        cin >> s;
        if (s == "end") {
            break;
        }
        insertTail(head, tail, s);
    }
}

void visit(Node*& head, Node*& tail, Node*& currPos, string val) {
    Node* tmp = head;
    while (tmp) {
        if (tmp->val == val) {
            cout << tmp->val << endl;
            currPos = tmp;
            return;
        }
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        cout << "Not Available" << endl;
    }
}

void prev(Node*& currPos, string val) {
    if (currPos->prev == NULL) {
        cout << "Not Available" << endl;
        return;
    }

    currPos = currPos->prev;
    cout << currPos->val << endl;
}

void next(Node*& currPos, string val) {
    if (currPos->next == NULL) {
        cout << "Not Available" << endl;
        return;
    }

    currPos = currPos->next;
    cout << currPos->val << endl;
}

void handleQuery(Node*& head, Node*& tail) {
    Node* currPos = NULL;

    int q;
    cin >> q;
    while (q--) {
        string f;
        cin >> f;

        if (f == "visit")
        {
            string s;
            cin >> s;

            visit(head, tail, currPos, s);
        }
        else if (f == "prev")
        {
            prev(currPos, f);
        }
        else if (f == "next")
        {
            next(currPos, f);
        }
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    inputList(head, tail);
    handleQuery(head, tail);

    return 0;
}