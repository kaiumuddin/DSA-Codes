var cnt = 0;

function subset(total, nums, n) {
    cnt++;
    if (total == 0)
        return true;

    if (n == 0)
        return false;

    if (nums[n] > total)
        return subset(total, nums, n - 1);

    return subset(total, nums, n - 1) || subset(total - nums[n], nums, n - 1);
}

// console.log(subset(6, [0, 1, 2, 3], 3));
// console.log(subset(9, [0, 3, 34, 4, 12, 5, 2], 6));
console.log(subset(30, [0, 3, 34, 4, 12, 5, 2], 6));
console.log(cnt);