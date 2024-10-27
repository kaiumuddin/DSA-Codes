var all_index = (arr, target, i = 0) => {
    if (i === arr.length) return [];
    const curr = target === arr[i] ? [i] : [];
    const child = all_index(arr, target, i + 1);
    const ans = [...curr, ...child];
    return ans;
};

console.log(all_index([-5, 34, -5, 34, 32], 34));
console.log(all_index([-5, 34, -5, 34, 32], -5));
console.log(all_index([-5, 34, -5, 34, 32], -2));
console.log(all_index([-5, 34, -5, 34, 32, 32], 32));

///////////////////////////////////////////////////

var all_index = (arr, target, i = 0) => {
    if (i === arr.length) return [];

    const faith = all_index(arr, target, i + 1);
    if (arr[i] === target) faith.push(i);

    return faith;

};

console.log(all_index([-5, 34, -5, 34, 32], 34));
console.log(all_index([-5, 34, -5, 34, 32], -5));
console.log(all_index([-5, 34, -5, 34, 32], -2));
console.log(all_index([-5, 34, -5, 34, 32, 32], 32));