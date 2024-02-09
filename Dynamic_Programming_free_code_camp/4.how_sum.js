// to solve recursively
// 3. terminate condition
// 1. build ans for current node
// 4. update ans for child node;
// 2. return ans

const how_sum = (target, nums) => {
    if (target < 0) return null;

    let curr = target === 0 ? [] : null;

    for (let n of nums) {
        let child = how_sum(target - n, nums);
        if (child != null) {
            curr = [...child, n];
            break;
        }
    }

    return curr;
};

console.log(how_sum(0, []));
console.log(how_sum(7, [2, 3]));
console.log(how_sum(7, [5, 3, 4, 7]));
console.log(how_sum(7, [2, 4]));
console.log(how_sum(8, [2, 3, 5]));
// console.log(how_sum(300, [7, 14]));

// time : nums^target * target
// space : target


////////////////////////////////////////////////////////////////////////////

// to solve memo
// 6. if ans for current node already in memo, return it
// 3. terminate condition
// 1. build ans for current node
// 4. update ans for child node;
// 5. store ans in memo
// 2. return ans

const how_sum_memo = (target, nums, memo = {}) => {
    if (target in memo) return memo[target];
    if (target < 0) return null;

    let curr = target === 0 ? [] : null;

    for (let n of nums) {
        let child = how_sum_memo(target - n, nums, memo);
        if (child != null) {
            curr = [...child, n];
            break;
        }
    }

    return memo[target] = curr;
};

console.log(how_sum_memo(0, []));
console.log(how_sum_memo(7, [2, 3]));
console.log(how_sum_memo(7, [5, 3, 4, 7]));
console.log(how_sum_memo(7, [2, 4]));
console.log(how_sum_memo(8, [2, 3, 5]));
console.log(how_sum_memo(300, [7, 14]));


// time : m+n
// space : m+n