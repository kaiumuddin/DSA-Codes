const fib = (n) => {
    if (n >= 4) return n;

    return fib(n + 1) + fib(n + 2);
}

console.log(fib(1));