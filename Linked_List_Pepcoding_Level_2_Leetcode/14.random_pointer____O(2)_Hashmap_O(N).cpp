/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> oldToCopy;

        auto old = head;
        while (old) {
            auto copy = new Node(old->val);
            oldToCopy[old] = copy;

            old = old->next;
        }

        old = head;
        while (old) {
            auto copy = oldToCopy[old];
            copy->next = oldToCopy[old->next];
            copy->random = oldToCopy[old->random];

            old = old->next;
        }

        return oldToCopy[head];
    }
};