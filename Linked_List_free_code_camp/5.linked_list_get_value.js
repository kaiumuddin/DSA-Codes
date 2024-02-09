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

const getNodeValue = (head, index) => {
    let ans = null;
    let i = 0;

    while (head && i <= index) {
        if (i == index) {
            ans = head.val;
            break;
        }
        head = head.next;
        i++;
    }

    return ans;
};

console.log(getNodeValue(head, 2));


const getNodeValueRecursive = (head, index) => {
    if (head === null) return null;
    console.log(head.val);
    if (index === 0) return head.val;
    let ans = null;

    ans = getNodeValueRecursive(head.next, index - 1);

    return ans;
};

console.log(getNodeValueRecursive(head, 1));
