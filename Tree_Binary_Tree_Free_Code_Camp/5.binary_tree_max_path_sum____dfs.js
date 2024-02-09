class Node {
    constructor(val, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

const root =
    new Node(5,
        new Node(11,
            new Node(4),
            new Node(2)
        ),
        new Node(3,
            null,
            new Node(1)
        )
    );

// to solve recursively
// 3. terminate condition
// 1. build ans for current node
// 4. build ans for child node;
// 2. return ans


// const max_path_sum_Dfs_Recursive = (root) => {
//     if (root === null) return -Infinity;
//     // if (!root.left && !root.right) return root.val;

//     let ans = root.val;

//     const l = max_path_sum_Dfs_Recursive(root.left);
//     const r = max_path_sum_Dfs_Recursive(root.right);
//     // ans += Math.max(l === -Infinity ? 0 : l, l === -Infinity ? 0 : r);
//     // ans += Math.max(l, r) === -Infinity ? 0 : Math.max(l, r);
//     let maxi = Math.max(l, r);
//     ans += (maxi === -Infinity) ? 0 : maxi;

//     return ans;
// };

// console.log(max_path_sum_Dfs_Recursive(root));

///////////////////////////////////////////////////////////////////////////////////


const dfs_Recursive = (root) => {
    if (root == null) return -Infinity;
    // if (!root.left && !root.right) return root.val; // either this one

    let l = dfs_Recursive(root.left);
    let r = dfs_Recursive(root.right);

    if (l == -Infinity && r == -Infinity) // or this one
        return root.val;

    return root.val + Math.max(l, r);
};

console.log(dfs_Recursive(root));

