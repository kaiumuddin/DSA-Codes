// O(n) - Linear Time Complexity: This means that the algorithm's execution time increases linearly with the input size. This is a common complexity for algorithms that iterate through the input once. Here's an example of an algorithm with linear time complexity:

function linearSearch(arr, target) {
    for (let i = 0;i < arr.length;i++) {
        if (arr[i] === target) {
            return i;
        }
    }

    return -1;
}
