
var graph = {
    f: ['g', 'i'],
    g: ['h'],
    h: [],
    i: ['g', 'k'],
    j: ['i'],
    k: [],
};

const dfs_hasPath = (graph, src, dst) => {
    if (src == dst) {
        return true;
    }

    for (neighbhor of graph[src]) {
        if (dfs_hasPath(graph, neighbhor, dst) === true) {
            return true;
        }
    }

    return false;
};

const bfs_hasPath = (graph, src, dst) => {
    const queue = [src];

    while (queue.length) {
        const curr = queue.shift();
        if (curr === dst) return true;

        for (let neighbhor of graph[curr]) {
            queue.push(neighbhor);
        }
    }

    return false;
};

// console.log(dfs_hasPath(graph, 'f', 'k'));
// console.log(bfs_hasPath(graph, 'f', 'k'));