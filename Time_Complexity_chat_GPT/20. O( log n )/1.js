// O(log n) - Logarithmic Time Complexity: This means that the algorithm's execution time increases logarithmically with the input size. This is a common complexity for algorithms that divide the input in half repeatedly. Here's an example of an algorithm with logarithmic time complexity:

function binarySearch(arr, target) {
    let low = 0;
    let high = arr.length - 1;

    while (low <= high) {
        let mid = Math.floor((low + high) / 2);

        if (arr[mid] === target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}
