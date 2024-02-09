class Node {
    constructor(val, next = null) {
        this.val = val;
        this.next = next;
    }
}

const head1 =
    new Node(1,
        new Node(3,
            new Node(5, null)));

const head2 =
    new Node(2,
        new Node(4,
            new Node(6,
                new Node(8,
                    new Node(10, null)))));

const printLinkedListIterative = (head) => {
    const ans = [];
    let curr = head;
    while (curr) {
        ans.push(curr.val);
        curr = curr.next;
    }
    return ans;
};
/////////////////////////////////////////////////////////////////////////////////////

console.log(printLinkedListIterative(head1));
console.log(printLinkedListIterative(head2));


const zipperList = (head1, head2) => {
    let tail = head1;
    let curr1 = head1.next;
    let curr2 = head2;

    let count = 0;

    while (curr1 && curr2) {
        if (count % 2 == 0) {
            tail.next = curr2;
            curr2 = curr2.next;
        } else {
            tail.next = curr1;
            curr1 = curr1.next;
        }
        tail = tail.next;
        count += 1;
    }

    if (curr1 != null) tail.next = curr1;
    if (curr2 != null) tail.next = curr2;

    return head1;
};


console.log(printLinkedListIterative(zipperList(head1, head2)));


/////////////////////////////////////////////////////////////////////////////////////






