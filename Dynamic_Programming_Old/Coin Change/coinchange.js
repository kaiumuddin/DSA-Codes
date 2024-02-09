memo = {};

function coinChange(amount, coins, index = 0) {

    key = index + "|" + amount;
    if (key in memo) return memo[key];

    if (index == coins.length)
        return 0;
    if (amount < 0)
        return 0;
    if (amount == 0)
        return 1;

    return memo[key] = coinChange(amount - coins[index], coins, index) + coinChange(amount, coins, index + 1);


}

console.log(coinChange(10, [2, 3]));
// console.log(coinChange(500, [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]));
console.log(memo);