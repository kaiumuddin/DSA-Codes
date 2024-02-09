function memo(n, dp) {
    if (n === 0) return 1;

    if (dp[n] != -1) return dp[n];

    const a = memo(n - 1, dp);

    let b = 0;
    if (n - 2 >= 0) b = memo(n - 2, dp);

    let c = 0;
    if (n - 3 >= 0) c = memo(n - 3, dp);

    return dp[n] = a + b + c;
}


function tabu(n, dp) {
    for (let i = 0; i <= n; i++) {
        if (i === 0) {
            dp[0] = 1;
            continue;
        }

        let a = dp[i - 1];

        let b = 0;
        if (i - 2 >= 0) b = dp[i - 2];

        let c = 0;
        if (i - 3 >= 0) c = dp[i - 3];

        dp[i] = a + b + c;
    }
    return dp[n];
}

(function main() {
    // console.log(memo(4, Array(1000 + 1).fill(-1)));
    // console.log(memo(20, Array(1000 + 1).fill(-1)));
    console.log(tabu(4, Array(1000 + 1).fill(-1)));
}());