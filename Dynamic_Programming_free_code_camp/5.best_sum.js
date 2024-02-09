// to solve recursively
// 3. terminate condition
// 1. build ans for current node
// 4. update ans for child node;
// 2. return ans

const best_sum = (target, nums) => {
    if (target < 0) return null;

    let curr = target === 0 ? [] : null;

    for (let n of nums) {
        let child = best_sum(target - n, nums);

        if (child !== null) {
            if (curr === null || child.length < curr.length) {
                curr = [...child, n];
            }
        }
    }

    return curr;
};

console.log(best_sum(0, []));
console.log(best_sum(7, [2, 3]));
console.log(best_sum(7, [5, 3, 4, 7]));
console.log(best_sum(7, [2, 4]));
console.log(best_sum(8, [1, 4, 5]));
console.log(best_sum(8, [2, 3, 5]));
// console.log(best_sum(300, [7, 14]));

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

const best_sum_memo = (target, nums, memo = {}) => {
    if (target in memo) return memo[target];
    if (target < 0) return null;

    let curr = target === 0 ? [] : null;

    for (let n of nums) {
        let child = best_sum_memo(target - n, nums, memo);

        if (child !== null) {
            if (curr === null || child.length < curr.length) {
                curr = [...child, n];
            }
        }
    }

    return memo[target] = curr;
};

console.log(best_sum_memo(0, []));
console.log(best_sum_memo(7, [2, 3]));
console.log(best_sum_memo(7, [5, 3, 4, 7]));
console.log(best_sum_memo(7, [2, 4]));
console.log(best_sum_memo(8, [1, 4, 5]));
console.log(best_sum_memo(8, [2, 3, 5]));
console.log(best_sum_memo(100, [1, 2, 5, 25]));
console.log(best_sum_memo(300, [7, 14]));

// time : n * m * m
// space : m^2