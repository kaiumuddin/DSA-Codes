
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

const undirected_hasPath = (graph, src, dst, visited) => {
    if (src === dst) return true;
    if (visited.has(src)) return false;
    visited.add(src);

    for (let neighbhor of graph[src]) {
        if (undirected_hasPath(graph, neighbhor, dst, visited) === true) {
            return true;
        }
    }

    return false;
};

const undirectedPath = (edges, nodeA, nodeB) => {
    const graph = buildGraph(edges);
    return undirected_hasPath(graph, nodeA, nodeB, new Set());
};

const edges =
    [
        ['i', 'j'],
        ['k', 'i'],
        ['m', 'k'],
        ['k', 'l'],
        ['o', 'n']
    ];

console.log(undirectedPath(edges, 'j', 'm'))

