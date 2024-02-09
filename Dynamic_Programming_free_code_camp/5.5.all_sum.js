// to solve recursively
// 3. terminate condition
// 1. build ans for current node
// 4. update ans for child node;
// 2. return ans

const all_sums = (target, nums) => {
    if (target < 0) return [];
    // if (target === 0) return [[]];
    let curr = target === 0 ? [[]] : [];

    for (let n of nums) {
        let child = all_sums(target - n, nums);

        for (let c of child) {
            curr.push([...c, n]);
        }
    }

    return curr;
};

console.log(all_sums(0, []));
console.log(all_sums(7, [2, 3]));
console.log(all_sums(7, [5, 3, 4, 7]));
console.log(all_sums(7, [2, 4]));
console.log(all_sums(8, [1, 4, 5]));
console.log(all_sums(8, [2, 3, 5]));
// console.log(all_sums(300, [7, 14]));

// time : nums^target * target
// space : target*target


////////////////////////////////////////////////////////////////////////////

// to solve memo
// 6. if ans for current node already in memo, return it
// 3. terminate condition
// 1. build ans for current node
// 4. update ans for child node;
// 5. store ans in memo
// 2. return ans

const all_sums_memo = (target, nums, memo = {}) => {
    if (target in memo) return memo[target];
    if (target < 0) return [];

    // if (target === 0) return [[]];
    let curr = target === 0 ? [[]] : [];

    for (let n of nums) {
        let child = all_sums_memo(target - n, nums, memo);

        for (let c of child) {
            curr.push([...c, n]);
        }
    }

    return memo[target] = curr;
};

console.log(all_sums_memo(0, []));
console.log(all_sums_memo(7, [2, 3]));
console.log(all_sums_memo(7, [5, 3, 4, 7]));
console.log(all_sums_memo(7, [2, 4]));
console.log(all_sums_memo(8, [1, 4, 5]));
console.log(all_sums_memo(8, [2, 3, 5]));
console.log(all_sums_memo(300, [7, 14]));

// time : n * m * m
// space : m^2