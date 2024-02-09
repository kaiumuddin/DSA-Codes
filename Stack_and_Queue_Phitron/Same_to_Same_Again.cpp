#include<bits/stdc++.h>
using namespace std;


class Node
{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myStack
{
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void push(int val) {
        sz++;
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    void pop() {
        sz--;
        Node* deleteNode = tail;
        tail = tail->prev;

        if (tail == NULL)
            head = NULL;
        else
            tail->next = NULL;

        delete deleteNode;
    }
    int top() {
        return tail->val;
    }
    int size() {
        return sz;
    }
    bool empty() {
        return sz == 0;
    }
};

class myQueue {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void push(int val) {
        sz++;
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    void pop() {
        sz--;
        Node* deleteNode = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
            delete deleteNode;
            return;
        }
        head->prev = NULL;
        delete deleteNode;
    }

    int front() {
        return head->val;
    }
    int size() {
        return sz;
    }
    bool empty() {
        return sz == 0;
    }
};

void printStack(myStack st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
void printQueue(myQueue q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


int main() {
    myStack st;
    myQueue q;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    // printStack(st);
    // printQueue(q);

    if (st.size() != q.size()) {
        cout << "NO" << endl;
        return 0;
    }

    list<int> a;
    list<int> b;

    while (!st.empty()) {
        a.push_back(st.top());
        st.pop();
    }
    while (!q.empty()) {
        b.push_back(q.front());
        q.pop();
    }

    auto ai = a.begin();
    auto bi = b.begin();

    while (ai != a.end() && bi != b.end()) {
        if (*ai != *bi) {
            cout << "NO" << endl;
            return 0;
        }
        ai++;
        bi++;
    }
    cout << "YES" << endl;

    // while (!st.empty() && !q.empty()) {
    //     // cout << st.top() << " " << q.front() << endl;
    //     if (st.top() != q.front()) {
    //         cout << "NO" << endl;
    //         return 0;
    //     }
    //     st.pop();
    //     q.pop();
    // }

    // cout << "YES" << endl;

    return 0;
}