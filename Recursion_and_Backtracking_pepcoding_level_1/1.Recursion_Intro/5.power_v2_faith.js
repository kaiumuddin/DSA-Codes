const power_linear = (x, n) => {
    if (n === 0) return 1;

    const n_minus_1 = power_linear(x, n - 1); // faith

    return n_minus_1 * x; // F + E
};

console.log(power_linear(2, 6));



// Expectation
// power(x, n) = x * x * x;
// power(2, 3) = 3 * 3 * 3;

// Faith
// power(x, n - 1) = x * x;
// power(2, 3 - 1) = 2 * 2;

// F + E
// power(x, n) = power(x, n - 1) * x

///////////////////////////////////////////////////

const power_logarithmic = (x, n) => {
    if (n === 0) return 1;
    const faith_n_by_2 = power_logarithmic(x, n / 2);
    let faith_exp = faith_n_by_2 * faith_n_by_2;
    if (n & 1) {
        faith_exp = faith_exp * x;
    }
    return faith_exp;
};

console.log(power_logarithmic(2, 6));


// E
// p(x, n) = x * x * x... * n times
// p(2, 6) = 2 * 2 * 2 * 2 * 2 * 2

// F
// p(x, n/1) = x * x * ... * (n/ 2) times

// FE
// p(x, n) = p(x, n/2) * p(x, n/2)      // n is even
// p(x, n) = p(x, n/2) * p(x, n/2) * x  // n is odd