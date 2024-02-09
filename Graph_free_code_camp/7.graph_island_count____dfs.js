const islandCount = (grid) => {
    const visited = new Set();
    let count = 0;

    for (let r = 0;r < grid.length;r += 1) {
        for (let c = 0;c < grid[0].length;c += 1) {
            if (grid[r][c] == "L" && !visited.has(r + ',' + c)) {
                explore_dfs(grid, r, c, visited);
                count++;
            }
        }
    }

    return count;
};

const explore_dfs = (grid, r, c, visited) => {
    const rowInbounds = 0 <= r && r < grid.length;
    const colInbounds = 0 <= c && c < grid[0].length;
    if (!rowInbounds || !colInbounds) return;

    if (grid[r][c] === 'W') return;

    const pos = r + ',' + c;
    if (visited.has(pos)) return;
    visited.add(pos);

    explore_dfs(grid, r - 1, c, visited);
    explore_dfs(grid, r + 1, c, visited);
    explore_dfs(grid, r, c - 1, visited);
    explore_dfs(grid, r, c + 1, visited);

};

const grid = [
    'W L W W W'.split(" "),
    'W L W W W'.split(" "),
    'W W W L W'.split(" "),
    'W W L L W'.split(" "),
    'L W W L L'.split(" "),
    'L L W W W'.split(" "),
];

console.log(islandCount(grid));