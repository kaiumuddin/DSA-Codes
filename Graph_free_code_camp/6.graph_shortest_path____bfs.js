const buildGraph = (edges) => {
    let graph = {};

    for (let [a, b] of edges) {
        if (!(a in graph)) graph[a] = [];
        if (!(b in graph)) graph[b] = [];

        graph[a].push(b);
        graph[b].push(a);
    }

    return graph;
};

const shortest_path = (edges, nodeA, nodeB) => {
    const graph = buildGraph(edges);

    const queue = [[nodeA, 0]];
    const visited = new Set([nodeA]);

    while (queue.length) {
        const [currNode, distance] = queue.shift();

        if (currNode == nodeB) return distance;

        for (let neighbhor of graph[currNode]) {
            if (!visited.has(neighbhor)) {
                visited.add(neighbhor);
                queue.push([neighbhor, distance + 1]);
            }
        }
    }

    return -1;
};

const edges =
    [
        ['w', 'x'],
        ['x', 'y'],
        ['z', 'y'],
        ['z', 'v'],
        ['w', 'v']
    ];

console.log(shortest_path(edges, 'w', 'y'));
