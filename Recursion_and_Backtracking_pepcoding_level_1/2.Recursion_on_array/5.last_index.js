var last_index = (arr, target, i = 0) => {
    if (i === arr.length) return -1;
    const curr = target === arr[i] ? i : -1;
    const child = last_index(arr, target, i + 1);
    return child > curr ? child : curr;
};

console.log(last_index([-5, 34, -5, 34, 32], 34));
console.log(last_index([-5, 34, -5, 34, 32], -5));
console.log(last_index([-5, 34, -5, 34, 32], -2));
console.log(last_index([-5, 34, -5, 34, 32, 32], 32));

////////////////////////////////////////////////////////////////

var last_index = (arr, target, i = 0) => {
    if (i === arr.length) return -1;

    const faith = last_index(arr, target, i + 1);
    const curr = target === arr[i] ? i : -1;
    return faith !== -1 ? faith : curr;
};

console.log(last_index([-5, 34, -5, 34, 32], 34));
console.log(last_index([-5, 34, -5, 34, 32], -5));
console.log(last_index([-5, 34, -5, 34, 32], -2));
console.log(last_index([-5, 34, -5, 34, 32, 32], 32));