// Fibonacci

// Brute Force
// const fib = (n) => {
//     if(n <=2 ) return 1;
//     return fib(n-1) + fib(n-2);
// }

// Memoization
const fib = (n, memo = {}) => {
    if (n in memo) return memo[n];
    if (n <=2 ) return 1;
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

console.log(fib(5));
console.log(fib(7));
console.log(fib(8));
console.log(fib(50));

// 0 ,1, 2, 3, 4, 5
// 0, 1, 1, 2, 3, 5

