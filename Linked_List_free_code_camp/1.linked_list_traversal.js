class Node {
    constructor(val, next = null) {
        this.val = val;
        this.next = next;
    }
}

const head =
    new Node('A',
        new Node('B',
            new Node('C',
                new Node('D', null))));


// A -> B -> C -> D -> null

const printLinkedListIterative = (head) => {
    let curr = head;
    while (curr) {
        console.log(curr.val);
        curr = curr.next;
    }
};

// printLinkedListIterative(head);


const printLinkedListRecursive = (head) => {
    if (head == null) return;
    console.log(head.val);
    printLinkedListRecursive(head.next);
};

printLinkedListRecursive(head);
