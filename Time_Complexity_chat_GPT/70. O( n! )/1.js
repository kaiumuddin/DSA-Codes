// O(n!) - Factorial Time Complexity: This means that the algorithm's execution time increases by a multiple of n! with the input size. This is a very slow complexity and should be avoided if possible. Here's an example of an algorithm with factorial time complexity:

function permute(arr) {
    if (arr.length <= 1) {
        return [arr];
    }

    const result = [];

    for (let i = 0;i < arr.length;i++) {
        const first = arr[i];
        const rest = arr.slice(0, i).concat(arr.slice(i + 1));
        const innerPermutations = permute(rest);

        for (let j = 0;j < innerPermutations.length;j++) {
            result.push([first].concat(innerPermutations[j]));
        }
    }

    return result;
}
