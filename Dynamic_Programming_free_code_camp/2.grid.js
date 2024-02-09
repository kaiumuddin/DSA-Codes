// to solve recursively
// 3. terminate condition
// 1. build ans for current node
// 4. build ans for child node;
// 2. return ans

const grid = (m, n) => {
    if (m === 1 && n === 1) return 1;
    if (m === 0 || n === 0) return 0;
    let ans = 0;
    ans += grid(m - 1, n) + grid(m, n - 1);
    return ans;
};

console.log(grid(1, 1));
console.log(grid(2, 3));
console.log(grid(3, 2));
console.log(grid(3, 3));
// console.log(grid(18, 18));

// time : 2^m+n
// space : m+n


////////////////////////////////////////////////////////////////////////////

// to solve memo
// 6. if ans for current node already in memo, return it
// 3. terminate condition
// 1. build ans for current node
// 4. build ans for child node;
// 5. store ans in memo
// 2. return ans

const grid_memo = (m, n, memo = {}) => {
    const key = m + "," + n;
    if (key in memo) return memo[key];

    if (m === 1 && n === 1) return 1;
    if (m === 0 || n === 0) return 0;

    let ans = 0;

    ans = memo[key] = grid_memo(m - 1, n, memo) + grid_memo(m, n - 1, memo);

    return ans;
};

console.log(grid_memo(1, 1));
console.log(grid_memo(2, 3));
console.log(grid_memo(3, 2));
console.log(grid_memo(3, 3));
console.log(grid_memo(18, 18));

// time : m+n
// space : m+n