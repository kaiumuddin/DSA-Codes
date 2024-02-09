class Node {
    constructor(val, next = null) {
        this.val = val;
        this.next = next;
    }
}

const head =
    new Node(1,
        new Node(2,
            new Node(3,
                new Node(4,
                    new Node(5, null)))));

// A -> B -> C -> D -> null

const printLinkedListIterative = (head) => {
    let curr = head;
    while (curr) {
        console.log(curr.val);
        curr = curr.next;
    }
};

const reverseList = (head) => {
    let prev = null;
    let curr = head;
    let next = head.next;

    while (curr) {
        next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
};

const reverseListRecursive = (curr, prev = null) => {
    if (curr == null) return prev;

    let next = curr.next;
    curr.next = prev;
    let newHead = curr;

    newHead = reverseListRecursive(next, curr);

    return newHead;
};

// printLinkedListIterative(reverseList(head));
printLinkedListIterative(reverseListRecursive(head));