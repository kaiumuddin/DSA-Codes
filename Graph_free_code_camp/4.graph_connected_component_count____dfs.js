const connected_components_count = (graph) => {
    const visited = new Set();
    let count = 0;
    for (let node in graph) {
        if (explore(graph, node, visited) === true) {
            count++;
        }
    }

    return count;
};


const explore = (graph, curr, visited) => {
    if (visited.has(String(curr))) return false;

    visited.add(String(curr));

    for (let neighbhor of graph[curr]) {
        explore(graph, neighbhor, visited);
    }

    return true;
};

const graph = {
    0: [8, 1, 5],
    1: [0],
    5: [0, 8],
    8: [0, 5],
    2: [3, 4],
    3: [2, 4],
    4: [3, 2]
}; // 2


console.log(connected_components_count(graph));

