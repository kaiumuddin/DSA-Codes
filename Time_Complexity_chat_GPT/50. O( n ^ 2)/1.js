// O(n ^ 2) - Quadratic Time Complexity: This means that the algorithm's execution time increases exponentially with the input size. This is a common complexity for algorithms that have nested loops. Here's an example of an algorithm with quadratic time complexity:

function bubbleSort(arr) {
    for (let i = 0;i < arr.length;i++) {
        for (let j = 0;j < arr.length - i - 1;j++) {
            if (arr[j] > arr[j + 1]) {
                const temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr;
}
