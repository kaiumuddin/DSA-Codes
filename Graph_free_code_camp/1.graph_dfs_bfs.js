var graph = {
    a: ['b', 'd'],
    b: ['c', 'f'],
    c: ['e', 'g'],
    d: ['f'],
    e: ['b', 'f'],
    f: ['a'],
    g: ['e']
};
// adj list

const bfs_print = (graph, source) => {
    const queue = [source];

    while (queue.length) {
        const curr = queue.shift();
        console.log(curr);

        for (let neighbhor of graph[curr]) {
            queue.push(neighbhor);
        }
    }
};

const set = new Set();
const dfs_iterative_print = (graph, source) => {
    const stack = [source];

    set.add(source);

    while (stack.length) {
        const curr = stack.pop();
        console.log(curr);

        for (let neighbhor of graph[curr]) {
            if (set.has(neighbhor) === true) continue;
            set.add(neighbhor);
            stack.push(neighbhor);
        }
    }
};


const dfs_recursive_print = (graph, source) => {
    console.log(source);

    set.add(source);

    for (let neighbhor of graph[source]) {
        if (set.has(neighbhor) === false) {
            dfs_recursive_print(graph, neighbhor);
        };
    }
};

dfs_iterative_print(graph, 'a');
console.log('----------------')
set.clear();
dfs_recursive_print(graph, 'a');
// bfs_print(graph, 'a');



