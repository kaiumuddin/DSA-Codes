// to solve recursively
// 3. terminate condition
// 1. build ans for current node
// 4. build ans for child node;
// 2. return ans

const fib = (n) => {
    if (n <= 2) return 1;
    let ans = 0;
    ans = fib(n - 1) + fib(n - 2);
    return ans;
};

// console.log(fib(6));
// console.log(fib(7));
// console.log(fib(8));
// console.log(fib(35));
// console.log(fib(50));

////////////////////////////////////////////////////////////////////////////

// to solve memo
// 6. if ans for current node already in memo, return it
// 3. terminate condition
// 1. build ans for current node
// 4. build ans for child node;
// 5. store ans in memo
// 2. return ans

const fib_memo = (n, memo = {}) => {
    if (n in memo) return memo[n];

    if (n <= 2) return 1;
    let ans = 0;
    ans = memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return ans;
};

console.log(fib_memo(4));
// console.log(fib_memo(6));
// console.log(fib_memo(7));
// console.log(fib_memo(8));
// console.log(fib_memo(35));
// console.log(fib_memo(50));