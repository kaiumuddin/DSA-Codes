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
                new Node(4, null))));

// A -> B -> C -> D -> null

const sumList = (head) => {
    let sum = 0;
    let curr = head;
    while (curr) {
        sum += curr.val;
        curr = curr.next;
    }
    return sum;
};

console.log(sumList(head));


const sumListRecursive = (head) => {
    if (head == null) return 0;
    const sum = sumListRecursive(head.next);
    return head.val + sum;
};

console.log(sumListRecursive(head));
