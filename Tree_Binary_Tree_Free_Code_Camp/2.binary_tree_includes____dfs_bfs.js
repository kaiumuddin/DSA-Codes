class Node {
    constructor(val, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

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

const includes_Dfs_Recursive = (root, target) => {
    if (root == null) return false; // 3. terminate condition
    if (root.val == target) return true;

    const l = includes_Dfs_Recursive(root.left, target); // 4. build ans for child node
    const r = includes_Dfs_Recursive(root.right, target); // 4. build ans for child node

    const ans = (root.val === target) || l || r; // 1. build ans for current node

    return ans; // 2. return ans
};

console.log(includes_Dfs_Recursive(root, 'a'));

///////////////////////////////////////////////////////////////////////////////////

const includes_Bfs = (root, target) => {
    if (root === null) return false;

    let ans = false;

    const queue = [root];
    while (queue.length) {
        const curr = queue.shift();
        if (curr.val == target) {
            ans = true;
            break;
        }
        if (curr.left) queue.push(curr.left);
        if (curr.right) queue.push(curr.right);
    }

    return ans;
};

// console.log(includes_Bfs(root, 'a'));