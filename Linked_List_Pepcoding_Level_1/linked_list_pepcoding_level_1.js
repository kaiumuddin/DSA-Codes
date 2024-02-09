class node {
    constructor(data, next = null) {
        this.data = data;
        this.next = next;
    }
}

class linked_list {
    constructor() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    addFirst(n) {
        let t = new node(n);
        t.next = this.head;
        this.head = t;

        if (this.size == 0) {
            this.tail = t;
        }

        this.size++;
    }

    addLast(n) {
        if (this.size == 0) {
            let t = new node(n);
            t.next = null;
            this.head = this.tail = t;
            this.size++;
            return;
        }

        let t = new node(n);
        t.next = null;

        this.tail.next = t;
        this.tail = t;
        this.size++;
    }

    display() {
        for (let t = this.head;t != null;t = t.next) {
            console.log(t.data);
        }
    }
}

let l = new linked_list();

l.addLast(0);
l.addLast(10);
l.addLast(20);
l.addLast(30);
l.addLast(40);
l.addLast(50);
l.addFirst(-10);

l.display();
