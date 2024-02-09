// O(n log n) - Log - linear Time Complexity: This means that the algorithm's execution time increases by a multiple of n and log n with the input size. This is a common complexity for algorithms that use a combination of sorting and searching. Here's an example of an algorithm with log - linear time complexity:

function mergeSort(arr) {
    if (arr.length <= 1) {
        return arr;
    }

    const mid = Math.floor(arr.length / 2);
    const left = arr.slice(0, mid);
    const right = arr.slice(mid);

    return merge(mergeSort(left), mergeSort(right));
}

function merge(left, right) {
    const result = [];

    while (left.length && right.length) {
        if (left[0] <= right[0]) {
            result.push(left.shift());
        } else {
            result.push(right.shift());
        }
    }

    return result.concat(left, right);
}
