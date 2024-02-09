class Node {
    constructor(val, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

const a =
    new Node('Picture',
        new Node('Marriage',
            new Node('Mehendi night'),
            new Node('Biyer night')),
        new Node('School',
            new Node('Boys',
                new Node('above 18'),
                new Node("Below 18")),
            new Node('Girls')));

const Dfs = (curr, space = "---") => {
    if (curr === null) return;

    console.log(space + curr.val);
    Dfs(curr.left, space + "---");
    Dfs(curr.right, space + "---");
};

Dfs(a);

const Bfs = (root) => {
    const queue = [root];

    while (queue.length > 0) {
        const curr = queue.shift();

        console.log(curr.val);

        if (curr.left !== null) queue.push(curr.left);
        if (curr.right !== null) queue.push(curr.right);
    }
};

// Bfs(a);
