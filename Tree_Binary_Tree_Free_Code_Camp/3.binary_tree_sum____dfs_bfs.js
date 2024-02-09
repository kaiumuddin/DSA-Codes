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


const sum_Dfs_Recursive = (root) => {
    if (root == null) return 0;

    const lsum = sum_Dfs_Recursive(root.left);
    const rsum = sum_Dfs_Recursive(root.right);

    return root.val + lsum + rsum;
};

console.log(sum_Dfs_Recursive(root));

///////////////////////////////////////////////////////////////////////////////////

const sum_Bfs = () => {
    if (root === null) return 0;
    let ans = 0;

    const queue = [root];
    while (queue.length) {
        const curr = queue.shift();
        ans += curr.val;

        if (curr.left) queue.push(curr.left);
        if (curr.right) queue.push(curr.right);
    }

    return ans;
};

// console.log(sum_Bfs(root));