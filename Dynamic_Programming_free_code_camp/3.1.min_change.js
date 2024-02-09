// to solve recursively
// 3. terminate condition
// 1. build ans for current node
// 4. update ans for child node;
// 2. return ans

const min_change = (amount, coins) => {
    const ans = _min_change(amount, coins);
    return ans === Infinity ? -1 : ans;
};

const _min_change = (amount, coins) => {
    if (amount < 0) return Infinity;

    let curr = amount === 0 ? 0 : Infinity;

    for (let n of coins) {
        let child = _min_change(amount - n, coins);
        curr = Math.min(curr, 1 + child);
    }

    return curr;
};

console.log(min_change(0, []));
console.log(min_change(8, [1, 5, 4, 12]));


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

const min_change_memo = (amount, coins) => {
    const ans = _min_change_memo(amount, coins);
    return ans === Infinity ? -1 : ans;
};

const _min_change_memo = (amount, coins, memo = {}) => {
    if (amount in memo) return memo[amount];
    if (amount < 0) return Infinity;

    let curr = amount === 0 ? 0 : Infinity;

    for (let n of coins) {
        let child = _min_change_memo(amount - n, coins, memo);
        curr = Math.min(curr, 1 + child);
    }

    return memo[amount] = curr;
};

console.log(min_change_memo(0, []));
console.log(min_change_memo(8, [1, 5, 4, 12]));


// time : m+n
// space : m+n