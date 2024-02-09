const factorial = (n) => {
    if (n === 0 || n === 1) return 1;

    const faith = factorial(n - 1); //faith
    const ans = n * faith; // faith + expection

    return ans;
};

console.log(factorial(5));

// Expectation
// factorial(3) = 3 * 2 * 1;

// Faith
// factorial(2) = 2 * 1;

// F + E
// factorial(3) = 3 * factorial(2)