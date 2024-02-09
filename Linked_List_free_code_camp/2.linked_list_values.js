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

const linkedListValuesIterative = (head) => {
    const values = [];
    let curr = head;
    while (curr) {
        values.push(curr.val);
        curr = curr.next;
    }
    return values;
};

console.log(linkedListValuesIterative(head));


const linkedListValuesRecursive = (head) => {
    if (head == null) return [];
    const values = linkedListValuesRecursive(head.next);
    return [head.val, ...values];
};

console.log(linkedListValuesRecursive(head));
