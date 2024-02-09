const connected_components_largest = (graph) => {
    const visited = new Set();
    let largest = 0;
    for (let node in graph) {
        const count = explore(graph, node, visited, 0);
        largest = Math.max(largest, count);
    }

    return largest;
};


const explore = (graph, curr, visited) => {
    if (visited.has(String(curr))) return 0;

    visited.add(String(curr));

    let size = 0;
    for (let neighbhor of graph[curr]) {
        size += explore(graph, neighbhor, visited);
    }

    return size + 1;
};

const graph = {
    0: [8, 1, 5],
    1: [0],
    5: [0, 8],
    8: [0, 5],
    2: [3, 4],
    3: [2, 4],
    4: [3, 2]
}; // 4


console.log(connected_components_largest(graph));

