class Node {
    constructor(val, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

const root =
    new Node(3,
        new Node(11,
            new Node(4),
            new Node(2)
        ),
        new Node(4,
            null,
            new Node(1)
        )
    );

// to solve recursively
// 3. terminate condition
// 1. build ans for current node
// 4. build ans for child node;
// 2. return ans


const min_Dfs_Recursive = (root) => {
    if (root == null) return Infinity;

    const lmin = min_Dfs_Recursive(root.left);
    const rmin = min_Dfs_Recursive(root.right);

    return Math.min(root.val, lmin, rmin);
};

console.log(min_Dfs_Recursive(root));

///////////////////////////////////////////////////////////////////////////////////

const min_Bfs = (root) => {
    if (root === null) return Infinity;
    let ans = Infinity;

    const queue = [root];
    while (queue.length) {
        const curr = queue.shift();
        ans = Math.min(ans, curr.val);

        if (curr.left) queue.push(curr.left);
        if (curr.right) queue.push(curr.right);
    }

    return ans;

};

// console.log(min_Bfs(root));