// to solve recursively
// 3. terminate condition
// 1. build ans for current node
// 4. build ans for child node;
// 2. return ans

const tribonacci = (n) => {
    if (n === 0) return 0;
    if (n === 1) return 0;
    if (n === 2) return 1;

    let ans = 0;
    ans = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    return ans;
};

console.log(tribonacci(6));
console.log(tribonacci(7));
console.log(tribonacci(8));
// console.log(tribonacci(35));
// console.log(tribonacci(50));

////////////////////////////////////////////////////////////////////////////

// to solve memo
// 6. if ans for current node already in memo, return it
// 3. terminate condition
// 1. build ans for current node
// 4. build ans for child node;
// 5. store ans in memo
// 2. return ans

const tribonacci_memo = (n, memo = {}) => {
    if (n in memo) return memo[n];
    if (n === 0) return 0;
    if (n === 1) return 0;
    if (n === 2) return 1;

    let ans = 0;
    ans = tribonacci_memo(n - 1, memo) + tribonacci_memo(n - 2, memo) + tribonacci_memo(n - 3, memo);
    return memo[n] = ans;
};

console.log(tribonacci_memo(6));
console.log(tribonacci_memo(7));
console.log(tribonacci_memo(8));
console.log(tribonacci_memo(37));
console.log(tribonacci_memo(50));