var knapsack = function (W, weights, profits, n) {
    if (n == 0 || W <= 0)
        return 0;
    if (weights[n] > W)
        return knapsack(W, weights, profits, n - 1);
    else
        return Math.max(profits[n] + knapsack(W - weights[n], weights, profits, n - 1), knapsack(W, weights, profits, n - 1));
}

var knapsack = function (W, weights, profits, n) {
    if (n == 0 || W <= 0)
        return 0;
    if (weights[n] > W)
        return knapsack(W, weights, profits, n - 1);
    else
        return Math.max(profits[n] + knapsack(W - weights[n], weights, profits, n), knapsack(W, weights, profits, n - 1));
}

console.log(knapsack(5, [0, 2, 3, 4], [0, 5, 6, 7], 3));
console.log(knapsack(50, [0, 10, 20, 30], [0, 60, 100, 120], 3));