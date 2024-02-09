// A recursive solution for subset sum problem

// Returns true if there is a subset of set[] with sum
// equal to given sum
var cnt = 0;

function isSubsetSum(set, n, sum) {
    cnt++;
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    // If last element is greater than sum,
    // then ignore it
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);

    /* else, check if sum can be obtained
    by any of the following
    (a) including the last element
    (b) excluding the last element */
    return isSubsetSum(set, n - 1, sum) ||
        isSubsetSum(set, n - 1, sum - set[n - 1]);
}

let set = [3, 34, 4, 12, 5, 2];
let sum = 30;
let n = set.length;
if (isSubsetSum(set, n, sum) == true)
    console.log("true");
else
    console.log("false")
console.log(cnt);
// This code is contributed by mukesh07.