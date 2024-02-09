class Node {
    constructor(prev = null, val, next = null) {
        this.prev = prev;
        this.val = val;
        this.next = next;
    }
}

const a = new Node(null, 'A');
const b = new Node(a, 'B');
const c = new Node(b, 'C', null);

a.next = b;
b.next = c;

for (let curr = c;curr != null;curr = curr.next) {
    console.log(curr.val);
}
