const minimumIsland = (grid) => {
    const visited = new Set();

    let mini = Infinity;

    for (let r = 0;r < grid.length;r += 1) {
        for (let c = 0;c < grid[0].length;c += 1) {
            if (grid[r][c] == "L" && !visited.has(r + ',' + c)) {
                const size = explore_dfs(grid, r, c, visited);
                mini = Math.min(mini, size);
            }
        }
    }

    return mini;
};

const explore_dfs = (grid, r, c, visited) => {
    const rowInbounds = 0 <= r && r < grid.length;
    const colInbounds = 0 <= c && c < grid[0].length;
    if (!rowInbounds || !colInbounds) return 0;

    if (grid[r][c] === 'W') return 0;

    const pos = r + ',' + c;
    if (visited.has(pos)) return 0;
    visited.add(pos);

    let size = 0;
    size += explore_dfs(grid, r - 1, c, visited);
    size += explore_dfs(grid, r + 1, c, visited);
    size += explore_dfs(grid, r, c - 1, visited);
    size += explore_dfs(grid, r, c + 1, visited);

    return size + 1;
};

const grid = [
    'W L W W W'.split(" "),
    'W L W W W'.split(" "),
    'W W W L W'.split(" "),
    'W W L L W'.split(" "),
    'L W W L L'.split(" "),
    'L L W W W'.split(" "),
];

console.log(minimumIsland(grid));