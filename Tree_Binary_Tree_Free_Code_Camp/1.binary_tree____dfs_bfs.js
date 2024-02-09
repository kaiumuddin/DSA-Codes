class Node {
    constructor(val, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// const root = new Node(1,
//     new Node(2,
//         new Node(4),
//         new Node(5)
//     ),
//     new Node(3,
//         new Node(6),
//         new Node(7)
//     )
// );

/* 
        a
        /\
      b    c
     /\    /\
    d  e     f
*/

const root =
    new Node('a',
        new Node('b',
            new Node('d'),
            new Node('e')
        ),
        new Node('c',
            null,
            new Node('f')
        )
    );

function dfs(root) {
    if (root === null) return;

    console.log(root.val);

    dfs(root.left);
    dfs(root.right);
}

// dfs(root);


function recursiveDfs(root) {
    if (root == null) return [];

    const lvals = recursiveDfs(root.left);
    const rvals = recursiveDfs(root.right);
    
    return [root.val, ...lvals, ...rvals];
}

function iterativeDfs(root) {
    if (root == null) return [];

    const stack = [root];
    const ans = [];

    while (stack.length) {
        const curr = stack.pop();
        ans.push(curr.val);

        if (curr.right) stack.push(curr.right);
        if (curr.left) stack.push(curr.left);
    }

    return ans;
}

function iterativeBfs(root) {
    if (root == null) return [];

    const queue = [root];
    const ans = [];

    while (queue.length) {
        const curr = queue.shift();
        ans.push(curr.val);

        if (curr.left) queue.push(curr.left);
        if (curr.right) queue.push(curr.right);
    }

    return ans;
}


console.log(recursiveDfs(root));
// console.log(iterativeDfs(root));
// console.log(iterativeBfs(root));

