const power_linear = (x, n) => {
    if (n === 0) return 1;
    let curr = x;
    let child = power_linear(x, n - 1);
    return curr * child;
};

console.log(power_linear(2, 6));
/////////////////////////////////////////////////////////

const power_logarithmic = (x, n) => {
    if (n === 0) return 1;

    let x2 = power_logarithmic(x, n / 2);
    let xn = x2 * x2;
    if (n & 1) xn = xn * x;

    return xn;
};

console.log(power_logarithmic(2, 6));
