class Node {
    constructor(value, children = []) {
        this.value = value;
        this.children = children;
    }
}

function depthFirstTraversal(root) {
    if (root === null) return [];

    const result = [root.value];

    root.children.forEach(child => {
        result.push(...depthFirstTraversal(child));
    });
    return result;
}

function iterativeBfs(root) {
    if (root == null) return [];

    const queue = [root];
    const result = [];

    while (queue.length) {
        const curr = queue.shift();
        result.push(curr.value);

        curr.children.forEach(child => {
            queue.push(child);
        });
    }
    return result;
}

function order(root, ans) {
    if (root === null) return;

    ans.preorder.push(root.value);

    root.children.forEach(child => {
        order(child, ans);
        // ans.inorder.push(root.value);
    });

    ans.postorder.push(root.value);
}


// Create a generic tree
let root =
    new Node('a', [
        new Node('b', [
            new Node('e', [
                new Node('k')
            ]),
            new Node('f', [
                new Node('l'),
                new Node('m', [
                    new Node('t')
                ]),
            ]),
        ]),
        new Node('c', [
            new Node('g'),
            new Node('h', [
                new Node('n', [
                    new Node('u'),
                    new Node('v'),
                ])
            ]),
            new Node('i', [
                new Node('o'),
                new Node('p'),
            ]),
        ]),
        new Node('d', [
            new Node('j', [
                new Node('q'),
                new Node('r'),
                new Node('s'),
            ]),
        ]),
    ]);

// console.log(depthFirstTraversal(root));
// console.log(iterativeBfs(root));

// root =
//     new Node(1, [
//         new Node(2, [
//             new Node(5, []),
//             new Node(6, []),
//             new Node(7, []),
//         ]),
//         new Node(3, []),
//         new Node(4, []),
//     ]);

// root =
//     new Node(1, [
//         new Node(2, [
//             new Node(5, []),
//             new Node(6, []),
//         ]),
//         new Node(3, []),
//         new Node(4, []),
//     ]);


const ans = {
    preorder: [],
    inorder: [],
    postorder: []
};
order(root, ans);
console.log(ans);


