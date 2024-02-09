// O(2 ^ n) - Exponential Time Complexity: This means that the algorithm's execution time doubles with each additional input. This is a very slow complexity and should be avoided if possible. Here's an example of an algorithm with exponential time complexity:

function fibonacci(n) {
    if (n === 0 || n === 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
